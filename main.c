#include <stdio.h>
#include <util/delay.h>

#include "sd.h"
#include "spi.h"
#include "uart.h"

#define DELAY_MS    1000

int main() {
    spi_master_init();
    uart_init();

    uint8_t res[5];

    res[0] = sd_go_idle();
    sd_print_response(res);

    sd_send_if_cond(res);
    sd_print_response(res);

    // sprintf(message, "%d", res);
    // uart_puts(message);
    // uart_puts("\r\n");
    uart_puts("hello world\r\n");

    for (;;) {
        // _delay_ms(DELAY_MS);
    }

}