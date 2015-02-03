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
 * AVR library routines for serial communications using USART.
 * Aaron Mavrinac <aaron@logick.ca>
 */

#include <avr/io.h>
#include <avr/interrupt.h>

#include <logickavr/usart.h>

void lw_usart_init(uint32_t baudrate)
{
  // enable rx/tx and interrupts
  UCSR0B = _BV(RXEN0) | _BV(TXEN0) | _BV(RXCIE0);

  // set 8-bit data size
  UCSR0C = _BV(UCSZ01) | _BV(UCSZ00);

  // set baud rate
  lw_usart_setbaud(baudrate);

  // enable interrupts
  sei();
}

void lw_usart_setbaud(uint32_t baudrate)
{
  uint16_t bauddiv = ((F_CPU + (baudrate * 8L)) / (baudrate * 16L) - 1);
  UBRR0L = bauddiv;
  UBRR0H = bauddiv >> 8;
}
