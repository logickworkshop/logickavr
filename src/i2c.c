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
 * AVR library routines for TWI/I2C interface.
 * Aaron Mavrinac <aaron@logick.ca>
 */

#include <logickavr/i2c.h>

void lw_i2c_init()
{
  TWSR = 0;
  TWBR = (uint8_t)(((F_CPU / F_SCL) - 16) / 2);
  TWCR |= (1 << TWEN);
}

void lw_i2c_wait_complete()
{
  loop_until_bit_is_set(TWCR, TWINT);
}

void lw_i2c_start()
{
  TWCR = (_BV(TWINT) | _BV(TWEN) | _BV(TWSTA));
  lw_i2c_wait_complete();
}

void lw_i2c_stop()
{
  TWCR = (_BV(TWINT) | _BV(TWEN) | _BV(TWSTO));
}

void lw_i2c_send(uint8_t data)
{
  TWDR = data;
  TWCR = (_BV(TWINT) | _BV(TWEN));
  lw_i2c_wait_complete();
}

uint8_t lw_i2c_read_ack()
{
  TWCR = (_BV(TWINT) | _BV(TWEN) | _BV(TWEA));
  lw_i2c_wait_complete();
  return TWDR;
}

uint8_t lw_i2c_read_noack()
{
  TWCR = (_BV(TWINT) | _BV(TWEN));
  lw_i2c_wait_complete();
  return TWDR;
}
