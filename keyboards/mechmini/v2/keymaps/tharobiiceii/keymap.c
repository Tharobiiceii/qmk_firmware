// Mechmini 2 Keymap
// 3.10.20

#include QMK_KEYBOARD_H
#include "action_layer.h"

// Empty Space Keycodes
#define _______ KC_TRNS
#define XXXXXXX KC_NO

// Tap-Hold Keycodes
#define MO_FN0 MO(_FN0)
#define MO_FN1 MO(_FN1)
#define TAB_FN1 LT(_FN1, KC_TAB)
#define ENT_FN0 LT(_FN0, KC_ENT)
#define APP_SFT LSFT_T(KC_APP)
#define SLS_SFT RSFT_T(KC_SLSH)
#define APP_CTL RCTL_T(KC_APP)

// Combined Layers
#define SYSTEM ((1UL << _FN0) | (1UL << _FN1))

// Layer Enumerations
enum layers {
  _BASE = 0,
  _FN0,
  _FN1,
  _SYSTEM
};

// Custom Key Enumerations
enum keycodes {
  BASE = SAFE_RANGE,
  SCRLK,
  CAPSLK,
  NUMLK,
  LED_RGB,
  RGB_OP1,
  RGB_OP2,
  RGB_OP3,
  RGB_OP4,
  RGB_OP5,
  RGB_MDE,
  RGB_HUE,
  RGB_SAT,
  RGB_VAL
};

extern keymap_config_t keymap_config;

// Keymap
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // Base
  // ,-----------------------------------------------------------------------------------------------------------.
  // |    GESC|       Q|       W|       E|       R|       T|       Y|       U|       I|       O|       P|    Back|
  // |-----------------------------------------------------------------------------------------------------------|
  // |   TAB_FN1|       A|       S|       D|       F|       G|       H|       J|       K|       L|        ENT_FN0|
  // |-----------------------------------------------------------------------------------------------------------|
  // |         LShift|       Z|       X|       C|       V|       B|       N|       M|       ,|         .| SLS_SFT|
  // |-----------------------------------------------------------------------------------------------------------|
  // |     LCtrl|     Alt|    MO_FN0|                   Space|               Space|    MO_FN1|    RGUI|   APP_CTL|
  // `-----------------------------------------------------------------------------------------------------------'

  [_BASE] = LAYOUT_split_space(
    KC_GESC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSPC,
    TAB_FN1,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L, ENT_FN0,
    KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M, KC_COMM,  KC_DOT, SLS_SFT,
    KC_LCTL, KC_LALT,  MO_FN0,  KC_SPC,  KC_SPC,  MO_FN1, KC_RGUI, APP_CTL
  ),

  // Fn0
  // ,-----------------------------------------------------------------------------------------------------------.
  // |   Pause|       !|       @|       #|       $|       %|       ^|       &|       *|       (|       )|    Menu|
  // |-----------------------------------------------------------------------------------------------------------|
  // | ________ |    Pipe|       _|       +|       {|       }|    Home|     PgDn|    PgUp|    End| _____________ |
  // |-----------------------------------------------------------------------------------------------------------|
  // | _____________ | ______ | ______ | ______ | ______ | ______ | ______ | ______ |       :|         "| ______ |
  // |-----------------------------------------------------------------------------------------------------------|
  // | ________ | ______ | ________ | ______________________ | __________________ | ________ | ______ | ________ |
  // `-----------------------------------------------------------------------------------------------------------'

  [_FN0] = LAYOUT_split_space(
    KC_PAUS, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,  KC_APP,
    _______, KC_PIPE, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_HOME, KC_PGDN, KC_PGUP,  KC_END, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_COLN, KC_DQUO, _______,
    _______, _______, _______, _______, _______, _______, _______, _______
  ),

  // Fn1
  // ,-----------------------------------------------------------------------------------------------------------.
  // |   Print|       1|       2|       3|       4|       5|       6|       7|       8|       9|       0|  Delete|
  // |-----------------------------------------------------------------------------------------------------------|
  // | ________ |       \|       -|       =|       [|       ]|    Left|    Down|      Up|   Right| _____________ |
  // |-----------------------------------------------------------------------------------------------------------|
  // | _____________ | ______ | ______ | ______ | ______ | ______ | ______ | ______ |       ;|         '| ______ |
  // |-----------------------------------------------------------------------------------------------------------|
  // | ________ | ______ | ________ | ______________________ | __________________ | ________ | ______ | ________ |
  // `-----------------------------------------------------------------------------------------------------------'

  [_FN1] = LAYOUT_split_space(
    KC_PSCR,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_DEL,
    _______, KC_BSLS, KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_SCLN, KC_QUOT, _______,
    _______, _______, _______, _______, _______, _______, _______, _______
  ),

  // System (Fn0 - Fn1)
  // ,-----------------------------------------------------------------------------------------------------------.
  // |   RESET|      F1|      F2|      F3|      F4|      F5|      F6|      F7|      F8|      F9|     F10|     F11|
  // |-----------------------------------------------------------------------------------------------------------|
  // | ________ |    Vol-|    Vol-|    Mute|        |        |        |  CAPSLK|   NUMLK|   SCRLK| _____________ |
  // |-----------------------------------------------------------------------------------------------------------|
  // | _____________ | RGB_OP1| RGB_OP2| RGB_OP3| RGB_OP4| RGB_OP5| RGB_MDE| RGB_HUE| RGB_SAT|   RGB_VAL| ______ |
  // |-----------------------------------------------------------------------------------------------------------|
  // |   LED_RGB|        | ________ |                        |                    | ________ |        |       F12|
  // `-----------------------------------------------------------------------------------------------------------'

  [_SYSTEM] = LAYOUT_split_space(
      RESET,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
    _______, KC_VOLD, KC_VOLU, KC_MUTE, XXXXXXX, XXXXXXX, XXXXXXX,  CAPSLK,   NUMLK,   SCRLK, _______,
    _______, RGB_OP1, RGB_OP2, RGB_OP3, RGB_OP4, RGB_OP5, RGB_MDE, RGB_HUE, RGB_SAT, RGB_VAL, _______,
    LED_RGB, XXXXXXX, _______, XXXXXXX, XXXXXXX, _______, XXXXXXX,  KC_F12
  )
};

// Process Custom Keycodes
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case SCRLK:
      if (record->event.pressed) {
        register_code(KC_SLCK);
      } else {
        unregister_code(KC_SLCK);
      }
      #ifdef AUDIO_ENABLE
        if (host_keyboard_leds() & (1 << USB_LED_SCROLL_LOCK)) {
          PLAY_SONG(tone_scroll);
        } else {
          PLAY_SONG(tone_noscroll);
        }
      #endif
      return false;
    case CAPSLK:
      if (record->event.pressed) {
        register_code(KC_CAPS);
      } else {
        unregister_code(KC_CAPS);
      }
      #ifdef AUDIO_ENABLE
        if (host_keyboard_leds() & (1 << USB_LED_CAPS_LOCK)) {
          PLAY_SONG(tone_caps);
        } else {
          PLAY_SONG(tone_nocaps);
        }
      #endif
      return false;
    case NUMLK:
      if (record->event.pressed) {
        register_code(KC_NLCK);
      } else {
        unregister_code(KC_NLCK);
      }
      #ifdef AUDIO_ENABLE
        if (host_keyboard_leds() & (1 << USB_LED_NUM_LOCK)) {
          PLAY_SONG(tone_num);
        } else {
          PLAY_SONG(tone_nonum);
        }
      #endif
      return false;
    case LED_RGB:
          if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          uint8_t shifted = get_mods() & MOD_MASK_SHIFT;
          if (shifted) {
            rgblight_toggle();
          } else {
            backlight_step();
          }
        #endif
      }
      return false;
    case RGB_OP1:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          uint8_t shifted = get_mods() & MOD_MASK_SHIFT;
          if (shifted) {
            // Red breathing
            rgblight_mode(RGBLIGHT_MODE_BREATHING + 1);
            rgblight_sethsv(HSV_RED);
          } else {
            // Red static
            rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
            rgblight_sethsv(HSV_RED);
          }
        #endif
      }
      return false;
    case RGB_OP2:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          uint8_t shifted = get_mods() & MOD_MASK_SHIFT;
          if (shifted) {
            // Green breathing
            rgblight_mode(RGBLIGHT_MODE_BREATHING + 1);
            rgblight_sethsv(HSV_GREEN);
          } else {
            // Green static
            rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
            rgblight_sethsv(HSV_GREEN);
          }
        #endif
      }
      return false;
    case RGB_OP3:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          uint8_t shifted = get_mods() & MOD_MASK_SHIFT;
          if (shifted) {
            // Blue breathing
            rgblight_mode(RGBLIGHT_MODE_BREATHING + 1);
            rgblight_sethsv(HSV_BLUE);
          } else {
            // Blue static
            rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
            rgblight_sethsv(HSV_BLUE);
          }
        #endif
      }
      return false;
    case RGB_OP4:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          uint8_t shifted = get_mods() & MOD_MASK_SHIFT;
          if (shifted) {
            // White breathing
            rgblight_mode(RGBLIGHT_MODE_BREATHING + 1);
            rgblight_sethsv(HSV_WHITE);
          } else {
            // White static
            rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
            rgblight_sethsv(HSV_WHITE);
          }
        #endif
      }
      return false;
    case RGB_OP5:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          uint8_t shifted = get_mods() & MOD_MASK_SHIFT;
          if (shifted) {
            // Cyan breathing
            rgblight_mode(RGBLIGHT_MODE_BREATHING + 1);
            rgblight_sethsv(128, 255, 255);
          } else {
            // Cyan static
            rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
            rgblight_sethsv(128, 255, 255);
          }
        #endif
      }
      return false;
    case RGB_MDE:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          uint8_t shifted = get_mods() & MOD_MASK_SHIFT;
          if (shifted) {
            rgblight_step_reverse();
          } else {
            rgblight_step();
          }
        #endif
      }
      return false;
    case RGB_HUE:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          uint8_t shifted = get_mods() & MOD_MASK_SHIFT;
          if (shifted) {
            rgblight_decrease_hue();
          } else {
            rgblight_increase_hue();
          }
        #endif
      }
      return false;
    case RGB_SAT:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          uint8_t shifted = get_mods() & MOD_MASK_SHIFT;
          if (shifted) {
            rgblight_decrease_sat();
          } else {
            rgblight_increase_sat();
          }
        #endif
      }
      return false;
    case RGB_VAL:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          uint8_t shifted = get_mods() & MOD_MASK_SHIFT;
          if (shifted) {
            rgblight_decrease_val();
          } else {
            rgblight_increase_val();
          }
        #endif
      }
      return false;
    default:
      return true;
  }
}

// Process Combined Layers
uint32_t layer_state_set_user(uint32_t state) {
  if ((state & SYSTEM) == SYSTEM) {
    state |= 1UL << _SYSTEM;
  } else {
    state &= ~(1UL << _SYSTEM);
  }
  return state;
}
