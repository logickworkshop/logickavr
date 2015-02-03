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

#include <logickavr/max7219.h>
#include <logickavr/spi.h>

void lw_max7219_write(char reg, char data)
{
    // load pin low
    PORTB &= ~(1 << LW_SPI_PIN_SS);

    // write data
    lw_spi_sendbyte(reg);
    lw_spi_sendbyte(data);

    // load pin high
    PORTB |= (1 << LW_SPI_PIN_SS);
}
