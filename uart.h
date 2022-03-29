#ifndef UART_H
#define UART_H

#include <stdint.h>

void uart_init();
void uart_transmit(uint8_t data);
void uart_puts(char* message);

#endif