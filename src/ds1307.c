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
 * AVR library routines for DS1307 RTC.
 * Aaron Mavrinac <aaron@logick.ca>
 */

#include <logickavr/ds1307.h>

void lw_ds1307_write_register(uint8_t reg, uint8_t data)
{
  lw_i2c_start();
  lw_i2c_send(LW_DS1307_ADDR);
  lw_i2c_send(reg);
  lw_i2c_send(data);
  lw_i2c_stop();
}

uint8_t lw_ds1307_read_register(uint8_t reg)
{
  uint8_t data = 0;
  lw_i2c_start();
  lw_i2c_send(LW_DS1307_ADDR);
  lw_i2c_send(reg);
  lw_i2c_start();
  lw_i2c_send(LW_DS1307_ADDR + 1);
  data = lw_i2c_read_noack();
  lw_i2c_stop();
  return data;
}

void lw_ds1307_get_date(uint8_t * Y, uint8_t * M, uint8_t * D)
{
  *Y = lw_ds1307_read_register(LW_DS1307_YEARS);
  *M = lw_ds1307_read_register(LW_DS1307_MONTHS);
  *D = lw_ds1307_read_register(LW_DS1307_DAYS);
}

void lw_ds1307_get_time(uint8_t * h, uint8_t * m, uint8_t * s)
{
  *h = lw_ds1307_read_register(LW_DS1307_HOURS);
  *m = lw_ds1307_read_register(LW_DS1307_MINUTES);
  *s = lw_ds1307_read_register(LW_DS1307_SECONDS);

  if(*h & LW_DS1307_PM)
  {
    *h &= 0x1F;
  }
  else
  {
    *h &= 0x3F;
  }
}

void lw_ds1307_get_date_time(uint8_t * Y, uint8_t * M, uint8_t * D, uint8_t * h, uint8_t * m, uint8_t * s)
{
  lw_ds1307_get_date(Y, M, D);
  lw_ds1307_get_time(h, m, s);
}

void lw_ds1307_set_date_time(uint8_t Y, uint8_t M, uint8_t D, uint8_t h, uint8_t m, uint8_t s)
{
  lw_ds1307_write_register(LW_DS1307_YEARS, Y);
  lw_ds1307_write_register(LW_DS1307_MONTHS, M);
  lw_ds1307_write_register(LW_DS1307_DAYS, D);
  lw_ds1307_write_register(LW_DS1307_HOURS, h);
  lw_ds1307_write_register(LW_DS1307_MINUTES, m);
  lw_ds1307_write_register(LW_DS1307_SECONDS, s);
}
