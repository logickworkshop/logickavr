PROJECT= logickavr

MMCU= atmega168
F_CPU= 1000000UL

AR= avr-ar
CC= avr-gcc
CFLAGS= -Os -Wall -mmcu=$(MMCU) -DF_CPU=$(F_CPU) -I/home/aaron/projects/logickavr/include

BUILDDIR= build
LIBDIR= lib

COMPONENTS= spi usart max7219

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
