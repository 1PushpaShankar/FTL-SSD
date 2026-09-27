#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "stm32f4xx.h"
#include "uart.h"
#include "arm_math.h"
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#include "nand.h"
#include "ftl.h"
#include "gc.h"

uint8_t source_buffer[BLOCK_COUNT];
uint32_t task1Profiler, task2Profiler;
volatile bool gc_requested = false;
//Free RTOS handles
static SemaphoreHandle_t gc_sem;

//Task prototypes
void ftl_task(void *pvParameters);
void gc_task(void *pvParameters);
const TickType_t _10ms =  pdMS_TO_TICKS(10);

int main(void)
{
    uart_init();
    ftl_status_t status = ftl_init();
    if (status != FTL_OK) {
           // halt
           for (;;) {}
       }
    memset(source_buffer, 0x11, sizeof(source_buffer));

    //Create a GC semaphore
    gc_sem = xSemaphoreCreateBinary();

    //Create FTL task with higher priority
    xTaskCreate(ftl_task, "FTL", 256, NULL, 2, NULL);    //higher the number , higher the priority (FreeRTOS Specific)

    //Create GC task with lower priority
	 xTaskCreate(gc_task, "Garbage collection", 256,  NULL, 1, NULL);

     vTaskStartScheduler();

    for (;;) {}
}

void ftl_task(void *pvParameters)
{
	while(1)
	{
		static lpa_t lpa_test = 0;
		ftl_status_t st =  ftl_program(lpa_test, source_buffer );
		if(st == FTL_OK){
			lpa_test++;
			if(lpa_test >= LOGICAL_PAGE_COUNT ){
				lpa_test = 0 ;
			}
		}
		uint32_t free_BC =  get_free_block_count();
		if(free_BC <= LOW_WATERMARK_GC ){
			if(!gc_requested){
				gc_requested = true;
				xSemaphoreGive(gc_sem);
			}
		}

		task1Profiler++;
		vTaskDelay(_10ms);

	}
}

void gc_task(void *pvParameters)
{
	while(1)
	{
		xSemaphoreTake(gc_sem, portMAX_DELAY);

		while(gc_requested){
			gc_status_t gc_st =  run_gc();
			if(gc_st == GC_NO_VICTIM){
				gc_requested = false;
				break;
		}

		uint32_t free_BC =  get_free_block_count();
		if(free_BC >= HIGH_WATERMARK_GC){
			gc_requested = false;
			break;
		 }
		task2Profiler++;
		vTaskDelay(0);
	  }

	}

}




