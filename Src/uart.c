#include "uart.h"


#define GPIOAEN			(1U<<0)
#define UART2EN			(1U<<17)
#define CR1_TE			(1U<<3)
#define CR1_RE          (1U<<2)
#define CR1_UE			(1U<<13)

#define SR_TXE			(1U<<7)
#define SR_RXNE			(1U<<5)


#define SYS_FREQ		16000000
#define APB1_CLK		SYS_FREQ

#define UART_BAUDRATE	115200

static void uart2_set_baudrate(uint32_t periph_clk, uint32_t baudrate);

void uart2_write(char ch);
void uart2_read(void);


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
	USART2->CR1 = CR1_TE | CR1_RE;

	/*Enable UART module*/
	USART2->CR1 |= CR1_UE;

	/*Enable UART DMA module for Transmission and Reception*/
	//USART2->CR3 = (USART2->CR3 & ~(0x3 << 6)) | (0x3 << 6);


}

void uart2_write(char ch)
{
		/*Make sure transmit data register is empty*/
		 while(!(USART2->SR & SR_TXE));
	 /*Write to the transmit data register*/
		 USART2->DR = (ch & 0xFF);


}

void uart2_write_hex8(uint8_t value)
{
    const char hex[] = "0123456789ABCDEF";

    uart2_write(hex[(value >> 4) & 0x0F]);  // high nibble
    uart2_write(hex[value & 0x0F]);         // low nibble
}

void uart2_read(void)
{
	/*Make sure receive data register is empty*/
	   while(!(USART2->SR & SR_RXNE));

	/*Write to the receive data register*/
	   return (USART2->DR & 0xFF);
}


static uint16_t compute_uart_bd( uint32_t periph_clk, uint32_t baudrate)
{
	return ((periph_clk + (baudrate/2U))/baudrate);
}

static void uart2_set_baudrate(uint32_t periph_clk, uint32_t baudrate)
{
	USART2->BRR = compute_uart_bd(periph_clk,baudrate);
}
static void fpu_enable(void)
{
	/*Enable Floating Point Unit :  Enable CP10 and CP11 full access*/
//	SCB->CPACR |= (1U<<20);
//	SCB->CPACR |= (1U<<21);
//	SCB->CPACR |= (1U<<22);
//	SCB->CPACR |= (1U<<23);
	SCB->CPACR |= (0xF << 20);

}
