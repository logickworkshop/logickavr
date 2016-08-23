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
 * AVR library routines for TWI/I2C interface.
 * Aaron Mavrinac <aaron@logick.ca>
 */

#ifndef LW_I2C_H_
#define LW_I2C_H_

#include <avr/io.h>

#ifdef __cplusplus
extern "C" {
#endif

void lw_i2c_init();

void lw_i2c_wait_complete();

void lw_i2c_start();
void lw_i2c_stop();

void lw_i2c_send(uint8_t data);

uint8_t lw_i2c_read_ack();
uint8_t lw_i2c_read_noack();

#ifdef __cplusplus
} // extern "C"
#endif

#endif // LW_I2C_H_
