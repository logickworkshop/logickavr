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
 * AVR library routines for stepper motors via SN754410.
 * Aaron Mavrinac <aaron@logick.ca>
 */

#ifndef LW_STEPPER_H_
#define LW_STEPPER_H_

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Initialize timer.
 */
void lw_stepper_init_timer(void);

/**
 * Step motor a specified number of times at a specified rate.
 *
 * count: Number of steps to take.
 * delay: Delay between steps (rotation speed).
 */
int16_t lw_stepper_step(int16_t count, uint8_t delay);

/**
 * Step motor a specified number of times using a trapezoid velocity profile.
 *
 * count: Number of steps to take.
 * accel: Acceleration/deceleration rate for trapezoid profile.
 */
void lw_stepper_trapezoid(int16_t count, uint8_t accel);

#ifdef __cplusplus
} // extern "C"
#endif

#endif // LW_STEPPER_H_
