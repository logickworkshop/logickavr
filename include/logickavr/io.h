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
 * AVR library routines for digital I/O.
 * Aaron Mavrinac <aaron@logick.ca>
 */

#ifndef LW_IO_H_
#define LW_IO_H_

#ifdef __cplusplus
extern "C" {
#endif

/** Debounce an active-low pushbutton or switch.
 *
 * port: Port to debounce.
 * pin: Pin to debounce.
 */
uint8_t lw_debounce(uint8_t port, uint8_t pin);

#ifdef __cplusplus
} // extern "C"
#endif

#endif // LW_IO_H_
