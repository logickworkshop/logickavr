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

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

// register address map
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

// Code B characters
#define LW_MAX7219_CODEB_NEG      0x0A
#define LW_MAX7219_CODEB_E        0x0B
#define LW_MAX7219_CODEB_H        0x0C
#define LW_MAX7219_CODEB_L        0x0D
#define LW_MAX7219_CODEB_P        0x0E
#define LW_MAX7219_CODEB_BLANK    0x0F

// initialization flags
#define LW_MAX7219_CODEB          0x01

/**
 * Initialize MAX7219.
 *
 * digits: Number of digits to scan.
 * intensity: LED intensity value.
 * flags: Miscellaneous flags.
 */
void lw_max7219_init(char digits, char intensity, uint8_t flags);

/**
 * Write a byte to MAX7219.
 * 
 * reg: Register to which to write.
 * data: Byte to write.
 */
void lw_max7219_write(char reg, char data);

#ifdef __cplusplus
} // extern "C"
#endif

#endif // LW_MAX7219_H_
