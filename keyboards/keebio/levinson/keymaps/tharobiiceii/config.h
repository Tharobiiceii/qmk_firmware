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

#undef BACKLIGHT_LEVELS
#define BACKLIGHT_LEVELS 3 // Number of backlight levels

#define RGBLIGHT_ANIMATIONS
#define RGBLED_NUM 12

// #pragma once

/* Use I2C or Serial, not both */

#define USE_SERIAL
// #define USE_I2C

/* Select hand configuration */

#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS

#endif
