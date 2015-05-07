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
 * AVR library routines for stepper motors via SN754410.
 * Aaron Mavrinac <aaron@logick.ca>
 */

#include <avr/io.h>
#include <avr/interrupt.h>

#include <logickavr/stepper.h>

const uint8_t motor[] = {
  (1 << PB0) | (1 << PB2),
  (1 << PB0),
  (1 << PB0) | (1 << PB3),
  (1 << PB3),
  (1 << PB1) | (1 << PB3),
  (1 << PB1),
  (1 << PB1) | (1 << PB2),
  (1 << PB2)
};

volatile uint8_t phase;
volatile int8_t direction = 1;
volatile uint16_t steps;

void lw_stepper_init_timer(void)
{
  TCCR0A |= (1 << WGM01);
  TCCR0B |= (1 << CS00) | (1 << CS02);
  OCR0A = LW_STEPPER_DELAY_MAX;
  sei();
}

int16_t lw_stepper_step(int16_t count, uint8_t delay)
{
  // set direction
  if(count < 0)
  {
    count = -count;
    direction = -1;
  }
  else
  {
    direction = 1;
  }
  
  // set delay
  OCR0A = delay;
  
  // enable stepping interrupts until complete
  steps = 0;
  TIMSK0 |= (1 << OCIE0A);
  while(steps < count);
  TIMSK0 &= -(1 << OCIE0A);

  return steps * direction;
}

void lw_stepper_trapezoid(int16_t count, uint8_t accel)
{
  uint8_t trapezoid_steps = 0;
  uint8_t ramp_steps = (LW_STEPPER_DELAY_MAX - LW_STEPPER_DELAY_MIN) / accel;
  uint8_t delay = LW_STEPPER_DELAY_MAX;
  int8_t sign = count < 0 ? -1 : 1;

  if(sign * count > ramp_steps * 2)
  {
    // ramp up
    while(trapezoid_steps < ramp_steps)
    {
      lw_stepper_step(sign, delay);
      delay -= accel;
      trapezoid_steps++;
    }

    // cruise
    delay = LW_STEPPER_DELAY_MIN;
    trapezoid_steps +=
      sign * lw_stepper_step(sign * (sign * count - ramp_steps * 2), delay);

    // ramp down
    while(trapezoid_steps < sign * count)
    {
      lw_stepper_step(sign, delay);
      delay += accel;
      trapezoid_steps++;
    }
  }
  else
  {
    while(trapezoid_steps < sign * count / 2)
    {
      lw_stepper_step(sign, delay);
      delay -= accel;
      trapezoid_steps++;
    }
    delay += accel;
    while(trapezoid_steps < sign * count)
    {
      lw_stepper_step(sign, delay);
      delay += accel;
      trapezoid_steps++;
    }
  }
}

ISR(TIMER0_COMPA_vect)
{
  phase += direction;
  phase &= 0b00000111;
  PORTB = motor[phase];
  steps++;
}
