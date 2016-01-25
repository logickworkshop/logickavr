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

// custom font
#define LW_MAX7219_DP             0x80
#define LW_MAX7219_0              0x7E
#define LW_MAX7219_1              0x30
#define LW_MAX7219_2              0x6D
#define LW_MAX7219_3              0x79
#define LW_MAX7219_4              0x33
#define LW_MAX7219_5              0x5B
#define LW_MAX7219_6              0x5F
#define LW_MAX7219_7              0x70
#define LW_MAX7219_8              0x7F
#define LW_MAX7219_9              0x7B
#define LW_MAX7219_A              0x76
#define LW_MAX7219_B              0x1F
#define LW_MAX7219_C              0x4E
#define LW_MAX7219_D              0x3D
#define LW_MAX7219_E              0x4F
#define LW_MAX7219_F              0x47
#define LW_MAX7219_G              0x5E
#define LW_MAX7219_H              0x17
#define LW_MAX7219_I              0x10
#define LW_MAX7219_J              0x3C
#define LW_MAX7219_K              0x37
#define LW_MAX7219_L              0x0E
#define LW_MAX7219_M              0x55
#define LW_MAX7219_N              0x15
#define LW_MAX7219_O              0x1D
#define LW_MAX7219_P              0x67
#define LW_MAX7219_Q              0x73
#define LW_MAX7219_R              0x05
#define LW_MAX7219_S              0x5B
#define LW_MAX7219_T              0x0F
#define LW_MAX7219_U              0x3E
#define LW_MAX7219_V              0x1C
#define LW_MAX7219_W              0x2B
#define LW_MAX7219_X              0x89
#define LW_MAX7219_Y              0x3B
#define LW_MAX7219_Z              0x6D

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
