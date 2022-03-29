#ifndef SPI_H
#define SPI_H

#include <stdint.h>

#define CS      PORTB2   // D10
#define MOSI    PORTB3   // D11
#define MISO    PORTB4   // D12
#define SCK     PORTB5   // D13

void spi_master_init();
uint8_t spi_master_transmit(uint8_t data);

#endif