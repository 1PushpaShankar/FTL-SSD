#ifndef __UART_H__
#define __UART_H__

#include <stdint.h>
#include "stm32f4xx.h"

void uart_init(void);
void uart2_write_hex8(uint8_t value);
void uart2_read(void);
void uart2_write(char ch);

#endif
