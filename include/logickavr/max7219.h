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
 * AVR library routines for MAX7219 7-segment display driver.
 * Aaron Mavrinac <aaron@logick.ca>
 */

#ifndef LW_MAX7219_H_
#define LW_MAX7219_H_

#include <logickavr/spi.h>

#ifdef __cplusplus
extern "C" {
#endif

// Register Address Map
#define LW_MAX7219_NOP            0x00
#define LW_MAX7219_DIGIT0         0x01
#define LW_MAX7219_DIGIT1         0x02
#define LW_MAX7219_DIGIT2         0x03
#define LW_MAX7219_DIGIT3         0x04
#define LW_MAX7219_DIGIT4         0x05
#define LW_MAX7219_DIGIT5         0x06
#define LW_MAX7219_DIGIT6         0x07
#define LW_MAX7219_DIGIT7         0x08
#define LW_MAX7219_DECODE         0x09
#define LW_MAX7219_INTENSITY      0x0A
#define LW_MAX7219_SCAN_LIMIT     0x0B
#define LW_MAX7219_SHUTDOWN       0x0C
#define LW_MAX7219_TEST           0x0F

#ifdef __cplusplus
} // extern "C"
#endif

#endif // LW_MAX7219_H_
