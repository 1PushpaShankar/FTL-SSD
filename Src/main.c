#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stddef.h>
#include "stm32f4xx.h"
#include "uart.h"
#include "arm_math.h"
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#include "uart.h"
#include "cli.h"
#include "nand.h"
#include "ftl.h"
#include "gc.h"
#include "wl.h"
#include "profiler.h"

#define WL_CHECK_INTERVAL_WRITES            100U
#define WL_MIN_FREE_BLOCKS                  5U

uint8_t source_buffer[PAGE_SIZE];
//uint32_t task1Profiler, task2Profiler, task3Profiler;
volatile profiler_stats_t ftl_profiler;
volatile profiler_stats_t gc_profiler;
volatile profiler_stats_t wl_profiler;

volatile bool gc_requested = false;
volatile bool wl_requested = false;
volatile uint32_t wl_last_elapsed = 0;
volatile uint32_t ftl_last_cycles = 0;
volatile uint32_t gc_last_cycles = 0;
volatile uint32_t core_clock_hz = 0U;

const TickType_t _10ms =  pdMS_TO_TICKS(10);

/* FreeRTOS handles */
static SemaphoreHandle_t gc_sem;
static SemaphoreHandle_t wl_sem;
QueueHandle_t uart_rx_queue;

/* Task prototypes */
void ftl_task(void *pvParameters);
void gc_task(void *pvParameters);
void wl_task(void *pvParameters);
void uart_cli_task(void *pvParameters);
void handle_command(char *line);

int main(void)
{

	SystemCoreClockUpdate();
	core_clock_hz = SystemCoreClock;

	/*Initialize the modules*/
	profiler_init();

	profiler_reset(&ftl_profiler);
	profiler_reset(&gc_profiler);
	profiler_reset(&wl_profiler);

	/*UART initialize and test*/
    uart_init();
    uart_rx_queue = xQueueCreate(64, sizeof(char));
    if(uart_rx_queue == NULL){
    	/* Handle error*/
     }

    ftl_status_t status = ftl_init();
    if (status != FTL_OK) {
           for (;;) {}
       }


    /*Create the semaphores*/
   	gc_sem = xSemaphoreCreateBinary();
   	wl_sem = xSemaphoreCreateBinary();

    if ((gc_sem == NULL) || (wl_sem == NULL)){
          	for(;;){}
         }

    /*Temporary data for source*/
    memset(source_buffer, 0x11, sizeof(source_buffer));

    xTaskCreate(uart_cli_task, "UART_CLI", 256, NULL, 4, NULL);
    uart2_enable_rx_interrupt();

    /*Create FTL task with higher priority*/
    BaseType_t ftl_task_created = xTaskCreate(ftl_task, "FTL", 256, NULL, 3, NULL);    //higher the number , higher the priority (FreeRTOS Specific)
    if (ftl_task_created != pdPASS) {
        for (;;) {}
    }

    /*Create GC task with lower priority*/
    BaseType_t gc_task_created = xTaskCreate(gc_task, "Garbage collection", 256,  NULL, 2, NULL);
    if (gc_task_created != pdPASS) {
        for (;;) {}
    }

	/*Create WL task with lower priority*/
    BaseType_t wl_task_created = xTaskCreate(wl_task, "Wear Leveling", 256,  NULL, 1, NULL);
    if (wl_task_created != pdPASS) {
        for (;;) {}
    }

     vTaskStartScheduler();

    for (;;) {}
}

void ftl_task(void *pvParameters)
{
	static uint32_t ftl_write_counter = 0U;

	while(1)
	{
		static lpa_t lpa_test = 0;
		uint32_t start_fl    = profiler_get_cycles();
		ftl_status_t ftl_st  =  ftl_program(lpa_test, source_buffer );
		uint32_t ftl_elapsed = profiler_elapsed_cycles(start_fl);
		profiler_update(&ftl_profiler, ftl_elapsed);

		if(ftl_st == FTL_OK){
			ftl_write_counter++;
			lpa_test++;
			if(lpa_test >= LOGICAL_PAGE_COUNT ){
				lpa_test = 0 ;
			}
			if(ftl_write_counter >= WL_CHECK_INTERVAL_WRITES){
				ftl_write_counter = 0U;
				if(!wl_requested){
				wl_requested = true;
				xSemaphoreGive(wl_sem);
				}
			}
		}
		uint32_t free_BC =  get_free_block_count();
		if(free_BC <= LOW_WATERMARK_GC ){
			if(!gc_requested){
				gc_requested = true;
				xSemaphoreGive(gc_sem);
			}
		}

		//task1Profiler++;
		vTaskDelay(_10ms);

	}
}

void gc_task(void *pvParameters)
{
	while(1)
	{
		xSemaphoreTake(gc_sem, portMAX_DELAY);
		while(gc_requested){
			uint32_t start_gc = profiler_get_cycles();
			gc_status_t gc_st =  run_gc();
			uint32_t elapsed_gc = profiler_elapsed_cycles(start_gc);
			profiler_update(&gc_profiler, elapsed_gc);
			//task2Profiler++;

			if(gc_st == GC_NO_VICTIM){
				gc_requested = false;
				break;
			}
		    if(gc_st != GC_OK){
		    	gc_requested = false;
		    	break;
		    }
			/*After GC has reclaimed one block, ask WL to evaluate*/
			if(!wl_requested){
				wl_requested = true;
				xSemaphoreGive(wl_sem);
			}

		uint32_t free_BC =  get_free_block_count();
		if(free_BC >= HIGH_WATERMARK_GC){
			gc_requested = false;
			break;
		 }

		//vTaskDelay(0);
	  }

	}

}

void wl_task(void *pvParameters){
	while(1)
		{
		xSemaphoreTake(wl_sem, portMAX_DELAY);
		wl_requested = false;
		if(!gc_requested){
			uint32_t free_BC =  get_free_block_count();
			if(free_BC >= WL_MIN_FREE_BLOCKS){
				uint32_t start_wl = profiler_get_cycles();
				wl_status_t wl_st = wl_checkand_run();
				uint32_t elapsed_wl = profiler_elapsed_cycles(start_wl);
				profiler_update(&wl_profiler, elapsed_wl);

			}
		}
		//task3Profiler++;
		//vTaskDelay(0);
	}
}


