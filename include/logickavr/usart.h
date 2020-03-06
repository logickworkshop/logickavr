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
 * AVR library routines for serial communications using USART.
 * Aaron Mavrinac <aaron@logick.ca>
 */

#ifndef LW_USART_H_
#define LW_USART_H_

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Initialize USART.
 *
 * baudrate: Baud rate.
 */
void lw_usart_init(void);

/**
 * Enable USART receive interrupt.
 */
void lw_usart_rxi(void);

/**
 * Transmit a byte on USART.
 *
 * c: Byte to transmit.
 */
void lw_usart_putc(char c);

/**
 * Receive a byte from USART.
 *
 * return: Byte received.
 */
char lw_usart_getc(void);

/**
 * Transmit a string on USART.
 *
 * s: String to transmit.
 */
void lw_usart_puts(const char * s);

#ifdef __cplusplus
} // extern "C"
#endif

#endif // LW_USART_H_
