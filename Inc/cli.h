#ifndef CLI_H
#define CLI_H

#include <stdint.h>
#include "FreeRTOS.h"
#include "queue.h"
#include "app_defs.h"
#include "app_status.h"
#include "profiler.h"
#include "stats.h"

extern QueueHandle_t uart_rx_queue;

void uart_cli_task(void *pvParameters);
void handle_command(char *line);


#endif /* CLI_H */
