PROJECT= logickavr

MMCU= atmega168
F_CPU= 8000000UL
F_SCL = 100000UL
BAUD = 9600

AR= avr-ar
CC= avr-gcc
CFLAGS= -Os -Wall -mmcu=$(MMCU) -DF_CPU=$(F_CPU) -DF_SCL=$(F_SCL) -DBAUD=$(BAUD) -I$(dir $(realpath $(firstword $(MAKEFILE_LIST))))include

BUILDDIR= build
LIBDIR= lib

COMPONENTS= spi i2c usart midi ds1307 max7219 stepper

.PHONY: clean

all: $(BUILDDIR) $(LIBDIR) $(LIBDIR)/lib$(PROJECT).a

$(LIBDIR)/liblogickavr.a: $(foreach component,$(COMPONENTS),$(BUILDDIR)/$(component).o)
	$(AR) -rcs $@ $^
	avr-size --common $@

$(BUILDDIR)/%.o: src/%.c
	$(CC) $(CFLAGS) -o $@ -c $<

build:
	mkdir -p $(BUILDDIR)

lib:
	mkdir -p $(LIBDIR)

clean:
	rm -rf $(BUILDDIR) $(LIBDIR)
