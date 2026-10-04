#include <string.h>
#include <stdlib.h>
#include "uart.h"
#include "cli.h"
#include "ftl.h"

void uart_cli_task(void *argument)
{
		char c;
		char line[64];
		uint8_t index = 0;
		while(1){
			if(xQueueReceive(uart_rx_queue, &c, portMAX_DELAY) == pdTRUE){
				uart2_write(c);
				if (c == '\r' || c == '\n'){
					line[index] = '\0';
					uart2_write('\r');
					uart2_write('\n');
					 handle_command(line);
					 index = 0;
				}
				else if (index < sizeof(line) - 1){
                     line[index++] = c;
				}

			}
		}
	}

void handle_command(char *line)
{
	 uart2_write_string("Received command: ");
	 uart2_write_string(line);
	 uart2_write_string("\r\n");

}
