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
  UCSR0B = (1 << RXEN0) | (1 << TXEN0) | (1 << RXCIE0);

  // set 8-bit data size
  UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);

  // set baud rate
  lw_usart_setbaud(baudrate);

  // enable interrupts
  sei();
}

void lw_usart_setbaud(uint32_t baudrate)
{
  uint16_t bauddiv = ((F_CPU + (baudrate * 8L)) / (baudrate * 16L) - 1L);

  if(100L * F_CPU > 16L * (bauddiv + 1L) * (100L * baudrate + baudrate * LW_USART_BAUD_TOL))
  {
    // recalculate baud rate for U2X
    bauddiv = ((F_CPU + (baudrate * 4L)) / (baudrate * 8L) - 1L);
    UCSR0A |= (1 << U2X0);
  }
  else
  {
    UCSR0A &= ~(1 << U2X0);
  }

  UBRR0L = bauddiv & 0xFF;
  UBRR0H = bauddiv >> 8;
}

void lw_usart_putc(char c)
{
  loop_until_bit_is_set(UCSR0A, UDRE0);
  UDR0 = c;
}

char lw_usart_getc(void)
{
  loop_until_bit_is_set(UCSR0A, RXC0);
  return UDR0;
}
