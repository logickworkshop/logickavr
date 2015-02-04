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
 * AVR library routines for MIDI (musical instrument digital interface).
 * Aaron Mavrinac <aaron@logick.ca>
 */

#include <stdarg.h>

#include <logickavr/midi.h>
#include <logickavr/usart.h>

void lw_midi_sendmsg(char cmd, ...)
{
  // send command byte
  lw_usart_putc(cmd);

  va_list ap;
  va_start(ap, cmd);

  switch((cmd & 0xF0) == 0xF0 ? cmd : cmd & 0xF0)
  {
    // two-argument commands
    case LW_MIDI_CMD_NOTE_OFF:
    case LW_MIDI_CMD_NOTE_ON:
    case LW_MIDI_CMD_AFTERTOUCH:
    case LW_MIDI_CMD_CC:
    case LW_MIDI_CMD_PITCH_BEND:
    case LW_MIDI_SYS_SONG_PP:
      lw_usart_putc((char)va_arg(ap, int));
    // one-argument commands
    case LW_MIDI_CMD_PC:
    case LW_MIDI_CMD_PRESSURE:
    case LW_MIDI_SYS_TC_QF:
    case LW_MIDI_SYS_SONG_SEL:
      lw_usart_putc((char)va_arg(ap, int));
      break;
  }

  va_end(ap);
}

void lw_midi_sendsysex(const char * data, size_t n)
{
  size_t i;

  // send system exclusive start message
  lw_midi_sendmsg(LW_MIDI_SYS_SE_START);

  for(i = 0; i < n; ++i)
  {
    lw_usart_putc(data[i]);
  }

  // send system exclusive end message
  lw_midi_sendmsg(LW_MIDI_SYS_SE_END);
}
