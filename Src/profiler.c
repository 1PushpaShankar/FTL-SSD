#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stddef.h>
#include "stm32f4xx.h"
#include "profiler.h"

void profiler_init(void){
	CoreDebug->DEMCR |= CoreDebug_DEMCR_TRCENA_Msk;
	DWT->CTRL |= DWT_CTRL_CYCCNTENA_Msk;
	DWT->CYCCNT = 0U;  //Read this bit before and after for profiling info
}

uint32_t profiler_get_cycles(){

	return DWT->CYCCNT ;
}
uint32_t profiler_elapsed_cycles(uint32_t start){

	return DWT->CYCCNT - start;
}

void profiler_update(volatile profiler_stats_t *stats, uint32_t elapsed_cycles){

	if(stats == NULL){
		return;
	}
	stats->last_cycles = elapsed_cycles;

	if(stats->count == 0U){
		 stats->min_cycles = elapsed_cycles;
		 stats->max_cycles = elapsed_cycles;
	}
	else{
		if(elapsed_cycles <  stats->min_cycles){
			stats->min_cycles = elapsed_cycles;
		}
		if(elapsed_cycles >  stats->max_cycles){
			stats->max_cycles = elapsed_cycles;
		}
	}

	stats->total_cycles += elapsed_cycles;
	stats->count++;
	stats->average_cycles = stats->total_cycles/stats->count;


}

uint32_t profiler_cycles_to_us(uint32_t cycles){
   if(SystemCoreClock == 0U ){
	   return 0U;
   }
   return (uint32_t)(((uint64_t) cycles * 1000000ULL)/ SystemCoreClock);
}

void profiler_reset( volatile profiler_stats_t *stats){
	if(stats == NULL){
		return;
	}

	stats->count        = 0U;
	stats->total_cycles = 0U;
	stats->min_cycles   = 0U;
	stats->max_cycles    = 0U;
	stats->last_cycles  = 0U;
	stats->average_cycles = 0U;

}
