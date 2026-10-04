#ifndef __UART_H__
#define __UART_H__

#include <stdint.h>
#include "stm32f4xx.h"
#include "FreeRTOS.h"
#include "queue.h"

void uart_init(void);
void uart2_write_string(const char *str);
//char uart2_read(void);
void uart2_write(char ch);
void uart2_enable_rx_interrupt(void);
void USART2_IRQHandler(void);

extern QueueHandle_t uart_rx_queue;

#endif
