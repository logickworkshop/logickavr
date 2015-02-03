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

#ifndef LW_MIDI_H_
#define LW_MIDI_H_

#ifdef __cplusplus
extern "C" {
#endif

#define LW_MIDI_BAUDRATE          31250

// MIDI channel commands
#define LW_MIDI_CMD_NOTE_OFF      0x80
#define LW_MIDI_CMD_NOTE_ON       0x90
#define LW_MIDI_CMD_AFTERTOUCH    0xA0
#define LW_MIDI_CMD_CONTINUOUS    0xB0
#define LW_MIDI_CMD_PATCH         0xC0
#define LW_MIDI_CMD_CH_PRESSURE   0xD0
#define LW_MIDI_CMD_PITCH_BEND    0xE0

// MIDI system messages
#define LW_MIDI_SYS_SE_START      0xF0
#define LW_MIDI_SYS_SE_END        0xF7
#define LW_MIDI_SYS_TC_QF         0xF1
#define LW_MIDI_SYS_SONG_PP       0xF2
#define LW_MIDI_SYS_SONG_SEL      0xF3
#define LW_MIDI_SYS_TUNE_REQ      0xF6
#define LW_MIDI_SYS_CLOCK         0xF8
#define LW_MIDI_SYS_START         0xFA
#define LW_MIDI_SYS_CONTINUE      0xFB
#define LW_MIDI_SYS_STOP          0xFC
#define LW_MIDI_SYS_ACT_SENSING   0xFE
#define LW_MIDI_SYS_RESET         0xFF

#ifdef __cplusplus
} // extern "C"
#endif

#endif // LW_MIDI_H_
