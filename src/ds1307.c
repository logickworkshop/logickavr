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
 *
 * AVR library routines for DS1307 RTC.
 * Aaron Mavrinac <aaron@logick.ca>
 */

#include <logickavr/ds1307.h>

#define LW_DS1307_ADDR            0xD0

#define LW_DS1307_SECONDS         0x00
#define LW_DS1307_MINUTES         0x01
#define LW_DS1307_HOURS           0x02
#define LW_DS1307_DAYOFWK         0x03
#define LW_DS1307_DAYS            0x04
#define LW_DS1307_MONTHS          0x05
#define LW_DS1307_YEARS           0x06

#define LW_DS1307_AMPM            5
#define LW_DS1307_24HR            6

uint8_t convert_from(uint8_t data)
{
  return 10 * ((data & 0xF0) >> 4) + (data & 0x0F);
}

uint8_t convert_to(uint8_t data)
{
  return ((data / 10) << 4) | (data % 10);
}

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
  *Y = convert_from(lw_ds1307_read_register(LW_DS1307_YEARS));
  *M = convert_from(lw_ds1307_read_register(LW_DS1307_MONTHS));
  *D = convert_from(lw_ds1307_read_register(LW_DS1307_DAYS));
}

void lw_ds1307_get_time(uint8_t * h, uint8_t * m, uint8_t * s, uint8_t * pm)
{
  uint8_t h_data;

  h_data = lw_ds1307_read_register(LW_DS1307_HOURS);
  *m = convert_from(lw_ds1307_read_register(LW_DS1307_MINUTES));
  *s = convert_from(lw_ds1307_read_register(LW_DS1307_SECONDS));

  if (h_data & (1 << LW_DS1307_24HR))
  {
    *pm = 0;
    h_data &= 0x3F;
    *h = convert_from(h_data);
  }
  else
  {
    *pm = h_data & (1 << LW_DS1307_AMPM) ? 1 : 0;
    h_data &= 0x1F;
    *h = convert_from(h_data);
  }
}

void lw_ds1307_set_date(uint8_t Y, uint8_t M, uint8_t D)
{
  if (M > 12 || D > 31)
  {
    return;
  }

  lw_ds1307_write_register(LW_DS1307_YEARS, convert_to(Y));
  lw_ds1307_write_register(LW_DS1307_MONTHS, convert_to(M));
  lw_ds1307_write_register(LW_DS1307_DAYS, convert_to(D));
}

void lw_ds1307_set_time_24hr(uint8_t h, uint8_t m, uint8_t s)
{
  if (h > 23 || m > 59 || s > 59)
  {
    return;
  }

  lw_ds1307_write_register(LW_DS1307_HOURS, convert_to(h) | (1 << LW_DS1307_24HR));
  lw_ds1307_write_register(LW_DS1307_MINUTES, convert_to(m));
  lw_ds1307_write_register(LW_DS1307_SECONDS, convert_to(s));
}

void lw_ds1307_set_time_12hr(uint8_t h, uint8_t m, uint8_t s, uint8_t pm)
{
  if (h > 12 || m > 59 || s > 59)
  {
    return;
  }

  lw_ds1307_write_register(LW_DS1307_HOURS, convert_to(h) | ((1 & pm) << LW_DS1307_AMPM));
  lw_ds1307_write_register(LW_DS1307_MINUTES, convert_to(m));
  lw_ds1307_write_register(LW_DS1307_SECONDS, convert_to(s));
}
