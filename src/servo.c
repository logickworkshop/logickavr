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

#include <util/delay.h>

#include <logickavr/servo.h>

#define LW_SERVO_PWM_STEP         5.555555555555555

void lw_servo_pwm(volatile uint8_t * port, uint8_t pin, uint8_t angle)
{
  // output the initial pulse
  *port |= (1 << pin);
  _delay_us(1000);

  // output the angle PWM
  uint8_t angle_comp = 180 - angle;
  while (angle--)
  {
    _delay_us(LW_SERVO_PWM_STEP);
  }
  *port &= ~(1 << pin);
  while (angle_comp--)
  {
    _delay_us(LW_SERVO_PWM_STEP);
  }

  // wait the remainder of 20ms
  _delay_us(18000);
}
