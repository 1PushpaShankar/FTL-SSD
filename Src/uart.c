#include "FreeRTOS.h"
#include "uart.h"
#include "cli.h"
#include <stdio.h>

static void uart2_set_baudrate(uint32_t periph_clk, uint32_t baudrate);
void uart2_write(char ch);
void uart2_write_string(const char *str);
char uart2_read(void);


int __io_putchar(char ch)
{
	uart2_write(ch);

	return ch;
}

void uart_init(void)
{
	/*****Configure UART GPIO Pin******/
	/*Enable clock access to GPIOA*/
	RCC->AHB1ENR |= GPIOAEN;

	/*Set PA2 mode to alternate function mode */
	GPIOA->MODER =  (GPIOA->MODER & ~(0x3U<<4)) | ((0x2 & 0x3) << 4);

	/*Set PA3 mode to alternate function mode */
	GPIOA->MODER =  (GPIOA->MODER & ~(0x3U<<6)) | ((0x2 & 0x3) << 6);

	/*Set PA3 alternate function type to UART_RX(AF07)*/
	GPIOA->AFR[0] |=(1U<<12);
	GPIOA->AFR[0] |=(1U<<13);
	GPIOA->AFR[0] |=(1U<<14);
	GPIOA->AFR[0] &=~(1U<<15);

	/*Set PA2 alternate function type to UART_TX(AF07)*/
	GPIOA->AFR[0] |=(1U<<8);
	GPIOA->AFR[0] |=(1U<<9);
	GPIOA->AFR[0] |=(1U<<10);
	GPIOA->AFR[0] &=~(1U<<11);

	/*****Configure UART  ******/
	/*Enable clock access to UART2*/
	RCC->APB1ENR |=UART2EN;

	/*Configure baudrate*/
	uart2_set_baudrate(APB1_CLK,UART_BAUDRATE);

	/*Configure the transfer direction*/
	USART2->CR1 |= CR1_TE | CR1_RE;

	/*Enable UART module*/
	USART2->CR1 |= CR1_UE;

	/*Enable UART DMA module for Transmission and Reception*/
	//USART2->CR3 = (USART2->CR3 & ~(0x3 << 6)) | (0x3 << 6);


}

void uart2_write_number(uint32_t value)
{
    char buffer[11];

    (void)snprintf(buffer,
                   sizeof(buffer),
                   "%lu",
                   (unsigned long)value);

    uart2_write_string(buffer);
}

void uart2_write(char ch)
{
		/*Make sure transmit data register is empty*/
		 while(!(USART2->SR & SR_TXE));
	 /*Write to the transmit data register*/
		 USART2->DR = (ch & 0xFF);

}

void uart2_write_string(const char *str)
{
    while (*str)
    {
        uart2_write(*str++);
    }
}

//char uart2_read(void)
//{
//	/*Make sure receive data register is empty*/
//	   while(!(USART2->SR & SR_RXNE));
//
//	/*Write to the receive data register*/
//	   return (char)(USART2->DR & 0xFF);
//}


static uint16_t compute_uart_bd( uint32_t periph_clk, uint32_t baudrate)
{
	return ((periph_clk + (baudrate/2U))/baudrate);
}

static void uart2_set_baudrate(uint32_t periph_clk, uint32_t baudrate)
{
	USART2->BRR = compute_uart_bd(periph_clk,baudrate);
}
//static void fpu_enable(void)
//{
//	/*Enable Floating Point Unit :  Enable CP10 and CP11 full access*/
////	SCB->CPACR |= (1U<<20);
////	SCB->CPACR |= (1U<<21);
////	SCB->CPACR |= (1U<<22);
////	SCB->CPACR |= (1U<<23);
//	SCB->CPACR |= (0xF << 20);
//
//}
void uart2_enable_rx_interrupt(void)
{
    USART2->CR1 |= CR1_RXNEIE;      /* Enable RX interrupt */
    NVIC_EnableIRQ(USART2_IRQn);
    NVIC_SetPriority(USART2_IRQn, 6);
}

void USART2_IRQHandler(void)
{
    BaseType_t higher_priority_task_woken = pdFALSE;
    char received;

    if (USART2->SR & SR_RXNE)
    {
        received = (char)(USART2->DR & 0xFF);
        xQueueSendFromISR(uart_rx_queue, &received, &higher_priority_task_woken);

    }

    portYIELD_FROM_ISR(higher_priority_task_woken);
}
