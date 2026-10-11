#ifndef PROFILER_H
#define PROFILER_H


#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <stddef.h>
#include "stm32f4xx.h"
#include "uart.h"
#include "arm_math.h"
#include "FreeRTOS.h"
#include "task.h"
#include "app_defs.h"
#include "app_status.h"
#include "stats.h"


void profiler_init(void);
uint32_t profiler_get_cycles();
uint32_t profiler_elapsed_cycles(uint32_t start);
uint32_t profiler_cycles_to_us(uint32_t cycles);

void profiler_update(volatile  profiler_stats_t *stats, uint32_t elapsed_cycles);
void profiler_reset(volatile  profiler_stats_t *stats);

#endif
