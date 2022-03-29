#include <avr/io.h>

#include "spi.h"


/*  ST7735 samples SDA on rising edge of SCK
    this is SPI Mode 0 of AVR
*/
void spi_master_init() {
    /* set these pins as OUTPUT */
    DDRB |= (1<<CS) | (1<<SCK) | (1<<MOSI);
    /* chips on SPI bus are disabled when CS is HIGH */
    PORTB |= (1<<CS);
    /* SPR0/1 = 0, SPI2X = 1, f_spi = f_osc/2 */
    SPCR = (1<<SPE) | (1<<MSTR);
    SPSR = (1<<SPI2X);
}

uint8_t spi_master_transmit(uint8_t data) {
    /* load data into register */
    SPDR = data;
    /* poll SPI Status Register */
    while (!(SPSR & (1<<SPIF)));
    return SPDR;
}