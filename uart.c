#include <avr/io.h>

#include "uart.h"

#define BAUD        1000000                     // text corrupted at 115200
#define UBRR_REG    ((F_CPU)/(BAUD*8UL)-1)      // see spec sheet: buad rate generator        

void uart_init() {
    UBRR0L = (uint8_t)UBRR_REG;                 // write lower byte
    UBRR0H = (uint8_t)(UBRR_REG >> 8);          // write higher byte

    UCSR0A |= (1<<U2X0);                        // U2X0 bit seems to be 1 by default on Pro Mini 3.3V 8Mhz
    UCSR0B |= (1 << RXEN0) | (1 << TXEN0);      // enable transmitter & receiver
}

void uart_transmit(uint8_t data) {
    while (!(UCSR0A & (1<<UDRE0)));             // wait for empty transmit buffer
    UDR0 = data;                                // put data into buffer
}

void uart_puts(char* message) {
    char* p = message;
    while (*p) {
        uart_transmit(*p++);
    }
}