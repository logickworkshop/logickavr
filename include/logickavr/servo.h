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
 * AVR library routines for servo motor control via digital I/O pins.
 * Aaron Mavrinac <aaron@logick.ca>
 */

#ifndef LW_SERVO_H_
#define LW_SERVO_H_

#ifdef __cplusplus
extern "C" {
#endif

/** Debounce an active-low button.
 *
 * port: Servo control signal port.
 * pin: Servo control signal pin.
 * angle: Servo angle in degrees (0 to 180).
 */
void lw_servo_pwm(volatile uint8_t * port, uint8_t pin, uint8_t angle);

#ifdef __cplusplus
} // extern "C"
#endif

#endif // LW_SERVO_H_
