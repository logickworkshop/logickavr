/*
 * ####                                                ####
 * ####                                                ####        
 * ####                                                ####      ##
 * ####                                                ####    ####
 * ####  ############  ############  ####  ##########  ####  ####
 * ####  ####    ####  ####    ####  ####  ####        ########
 * ####  ####    ####  ####    ####  ####  ####        ########
 * ####  ####    ####  ####    ####  ####  ####        ####  ####
 * ####  ####    ####  ####    ####  ####  ####        ####    ####
 * ####  ############  ############  ####  ##########  ####      ####
 *                             ####                                ####
 * ################################                                  ####
 *            __      __              __              __      __       ####
 *   |  |    |  |    [__)    |_/     (__     |__|    |  |    [__)        ####
 *   |/\|    |__|    |  \    |  \    .__)    |  |    |__|    |             ##
 *
 * AVR library routines for serial communications using USART.
 * Aaron Mavrinac <aaron@logick.ca>
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/setbaud.h>

#include <logickavr/usart.h>

void lw_usart_init(uint32_t baudrate)
{
  // set baud rate
  UBRR0H = UBRRH_VALUE;
  UBRR0L = UBRRL_VALUE;
#if USE_2X
  UCSR0A |= (1 << U2X0);
#else
  UCSR0A &= ~(1 << U2X0);
#endif

  // enable rx/tx
  UCSR0B = (1 << RXEN0) | (1 << TXEN0);

  // set 8-bit data size
  UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);
}

void lw_usart_rxi(void)
{
  // enable USART receive interrupt
  UCSR0B |= (1 << RXCIE0);

  // enable global interrupt flag
  sei();
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
