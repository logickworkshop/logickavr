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
 * AVR library routines for serial communications using USART.
 * Aaron Mavrinac <aaron@logick.ca>
 */

#ifndef LW_USART_H_
#define LW_USART_H_

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifdef BAUD_TOL
  #define LW_USART_BAUD_TOL         BAUD_TOL
#else
  #define LW_USART_BAUD_TOL         2L
#endif

/**
 * Initialize USART.
 *
 * baudrate: Baud rate.
 */
void lw_usart_init(uint32_t baudrate);

/**
 * Set USART baud rate.
 *
 * baudrate: Baud rate.
 */
void lw_usart_setbaud(uint32_t baudrate);

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

#ifdef __cplusplus
} // extern "C"
#endif

#endif // LW_USART_H_
