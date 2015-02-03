/*
 * ####                                                ####
 * ####                                                ####      ##
 * ####                                                ####    ####
 * ####                                                ####  ####
 * ####  ############  ############  ####  ##########  ########
 * ####  ####    ####  ####    ####  ####  ####        ########
 * ####  ####    ####  ####    ####  ####  ####        ####  ####
 * ####  ####    ####  ####    ####  ####  ####        ####    ####
 * ####  ####    ####  ####    ####  ####  ####        ####      ####
 * ####  ############  ############  ####  ##########  ####        ####
 *                             ####                                  ####
 * ################################                                    ####
 *            __      __              __              __      __         ####
 *   |  |    |  |    [__)    |_/     (__     |__|    |  |    [__)          ####
 *   |/\|    |__|    |  \    |  \    .__)    |  |    |__|    |               ####
 *                                                                             ##
 *
 * AVR library routines for SPI (serial peripheral interface).
 * Aaron Mavrinac <aaron@logick.ca>
 */

#ifndef LW_SPI_H_
#define LW_SPI_H_

#include <avr/io.h>

#ifdef __cplusplus
extern "C" {
#endif

// SPI pin definitions
#if (defined(__AVR_AT90USB82__) || \
     defined(__AVR_AT90USB162__))
  #define LW_SPI_PIN_SCK        PORTB1
  #define LW_SPI_PIN_MOSI       PORTB2
  #define LW_SPI_PIN_MISO       PORTB3
  #define LW_SPI_PIN_SS         PORTB0
#elif (defined(__AVR_ATmega48__) || \
       defined(__AVR_ATmega88__) ||  \
       defined(__AVR_ATmega168__) || \
       defined(__AVR_ATmega328__) || \
       defined(__AVR_ATmega328P__))
  #define LW_SPI_PIN_SCK        PORTB5
  #define LW_SPI_PIN_MOSI       PORTB3
  #define LW_SPI_PIN_MISO       PORTB4
  #define LW_SPI_PIN_SS         PORTB2
#endif

/**
 * Send a byte via SPI.
 *
 * data: Byte to send.
 */
void lw_spi_sendbyte(char data)
{
  SPDR = data;
  while(!(SPSR & (1 << SPIF)));
}

#ifdef __cplusplus
} // extern "C"
#endif

#endif // LW_SPI_H_
