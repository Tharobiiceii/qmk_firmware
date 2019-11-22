#ifndef CONFIG_USER_H
#define CONFIG_USER_H

#include "config_common.h"

#ifdef AUDIO_ENABLE
    #define STARTUP_SONG SONG(NO_SOUND)
#endif

#define GRAVE_ESC_CTRL_OVERRIDE // Always send Escape if Ctrl is pressed

#define TAPPING_TERM 200 // Time before a tap becomes a hold

#define TAPPING_TOGGLE 2 // Number of taps before triggering the toggle

#define PERMISSIVE_HOLD // Makes tap and hold keys work better for fast typers

#define RGB_MATRIX_KEYPRESSES // Reacts to keypresses (will slow down matrix scan by a lot)

// Most tactile encoders have detents every 4 stages
#define ENCODER_RESOLUTION 4

#endif
