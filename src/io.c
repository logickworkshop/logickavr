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
 * AVR library routines for digital I/O.
 * Aaron Mavrinac <aaron@logick.ca>
 */

#include <avr/io.h>
#include <util/delay.h>

#include <logickavr/io.h>

#define LW_IO_DEBOUNCE_TIME       1000

uint8_t lw_debounce(uint8_t port, uint8_t pin)
{
  if (bit_is_clear(port, pin))
  {
    _delay_us(LW_IO_DEBOUNCE_TIME);
    if (bit_is_clear(port, pin))
    {
      return 1;
    }
  }

  return 0;
}
