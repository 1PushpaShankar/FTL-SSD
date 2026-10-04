#ifndef CLI_H
#define CLI_H

#include "FreeRTOS.h"
#include "queue.h"

extern QueueHandle_t uart_rx_queue;

void uart_cli_task(void *argument);
void handle_command(char *line);

#endif
