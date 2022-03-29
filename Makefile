CC = avr-gcc
OBJCOPY = avr-objcopy
CFLAGS = -Os -DF_CPU=8000000UL -mmcu=atmega328p
CONF_DIR = C:\Users\yff\AppData\Local\Arduino15\packages\arduino\tools\avrdude\6.3.0-arduino17\etc\avrdude.conf

PORT = com7

all: main.out

main.out: main.o sd.o spi.o uart.o
	$(CC) $(CFLAGS) main.o sd.o spi.o uart.o -o main.out

%.o: %.c
	$(CC) $(CFLAGS) -c $^

# $<: first prerequisite $@: target
main.hex: main.out
	${OBJCOPY} -O ihex -R .eeprom $< $@

install.main: main.hex
	avrdude -C ${CONF_DIR} -F -V -c arduino -p ATMEGA328P -P ${PORT} -b 57600 -U flash:w:$<

clean:
	del *.o *.out *.hex