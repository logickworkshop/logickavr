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

#ifndef LW_DS1307_H_
#define LW_DS1307_H_

#include <logickavr/i2c.h>

#ifdef __cplusplus
extern "C" {
#endif

void lw_ds1307_write_register(uint8_t reg, uint8_t data);
uint8_t lw_ds1307_read_register(uint8_t reg);

void lw_ds1307_get_date(uint8_t * Y, uint8_t * M, uint8_t * D);
void lw_ds1307_get_time(uint8_t * h, uint8_t * m, uint8_t * s);
void lw_ds1307_get_date_time(uint8_t * Y, uint8_t * M, uint8_t * D, uint8_t * h, uint8_t * m, uint8_t * s);

void lw_ds1307_set_date_time(uint8_t Y, uint8_t M, uint8_t D, uint8_t h, uint8_t m, uint8_t s);

#ifdef __cplusplus
} // extern "C"
#endif

#endif // LW_DS1307_H_
