// Minivan Keymap
// 5.11.20

#include QMK_KEYBOARD_H
#include "action_layer.h"

// Empty Space Keycodes
#define _______ KC_TRNS
#define XXXXXXX KC_NO

// Tap-Hold Keycodes
#define MO_FN0 MO(_FN0)
#define MO_FN1 MO(_FN1)
#define APP_GUI RGUI_T(KC_APP)
#define TAB_FN1 LT(_FN1, KC_TAB)
#define ENT_FN0 LT(_FN0, KC_ENT)
#define APP_GUI RGUI_T(KC_APP)

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
  NUMLK
};

extern keymap_config_t keymap_config;

// Keymap
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // Base
  // ,-----------------------------------------------------------------------------------------------------------------.
  // |    GESC|       Q|       W|       E|       R|       T|       Y|       U|       I|       O|       P|     Backspace|
  // |-----------------------------------------------------------------------------------------------------------------|
  // |   TAB_FN1|       A|       S|       D|       F|       G|       H|       J|       K|       L|       ;|     ENT_FN0|
  // |-----------------------------------------------------------------------------------------------------------------|
  // |        LShift|       Z|       X|       C|       V|       B|       N|       M|       ,|       .|       /|  RShift|
  // |-----------------------------------------------------------------------------------------------------------------|
  // |   LCtrl|    LGUI|    LAlt|  MO_FN0|              Space|            Space|      MO_FN1|    RAlt| APP_GUI|   RCtrl|
  // `-----------------------------------------------------------------------------------------------------------------'

  [_BASE] = LAYOUT_arrow_command(
    KC_GESC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSPC,
    TAB_FN1,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, ENT_FN0,
    KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT,
    KC_LCTL, KC_LGUI, KC_LALT,  MO_FN0,  KC_SPC,  KC_SPC,  MO_FN1, KC_RALT, APP_GUI, KC_RCTL
  ),

  // Fn0
  // ,-----------------------------------------------------------------------------------------------------------------.
  // |   Pause|       !|       @|       #|       $|       %|       ^|       &|       *|       (|       )|        Insert|
  // |-----------------------------------------------------------------------------------------------------------------|
  // | ________ |    Pipe|       _|       +|       {|       }|    Home|     PgDn|    PgUp|    End|       "| __________ |
  // |-----------------------------------------------------------------------------------------------------------------|
  // | ____________ | ______ | ______ | ______ | ______ | ______ | ______ | ______ | ______ | ______ | ______ | ______ |
  // |-----------------------------------------------------------------------------------------------------------------|
  // | ______ | ______ | ______ | ______ | ________________ | _______________ | __________ | ______ | _______ | ______ |
  // `-----------------------------------------------------------------------------------------------------------------'

  [_FN0] = LAYOUT_arrow_command(
    KC_PAUS, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,  KC_INS,
    _______, KC_PIPE, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_HOME, KC_PGDN, KC_PGUP,  KC_END, KC_DQUO, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

  // Fn1
  // ,-----------------------------------------------------------------------------------------------------------------.
  // |   Print|       1|       2|       3|       4|       5|       6|       7|       8|       9|       0|        Delete|
  // |-----------------------------------------------------------------------------------------------------------------|
  // | ________ |       \|       -|       =|       [|       ]|    Left|    Down|      Up|   Right|       '| __________ |
  // |-----------------------------------------------------------------------------------------------------------------|
  // | ____________ | ______ | ______ | ______ | ______ | ______ | ______ | ______ | ______ | ______ | ______ | ______ |
  // |-----------------------------------------------------------------------------------------------------------------|
  // | ______ | ______ | ______ | ______ | ________________ | _______________ | __________ | ______ | _______ | ______ |
  // `----------------------------------------------------------------------------------------------------------------'

  [_FN1] = LAYOUT_arrow_command(
    KC_PSCR,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_DEL,
    _______, KC_BSLS, KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, KC_QUOT, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

  // System (Fn0 - Fn1)
  // ,-----------------------------------------------------------------------------------------------------------------.
  // |   RESET|      F1|      F2|      F3|      F4|      F5|      F6|      F7|      F8|      F9|     F10|           F11|
  // |-----------------------------------------------------------------------------------------------------------------|
  // | ________ |    Vol-|    Vol-|    Mute|        |        |        |        |  CAPSLK|   NUMLK|   SCRLK| __________ |
  // |-----------------------------------------------------------------------------------------------------------------|
  // | ____________ |        |        |        |        |        |        |        |        |        |        | ______ |
  // |-----------------------------------------------------------------------------------------------------------------|
  // | RGB_TOG|        |        | ______ |                  |                 | __________ |        |         |     F12|
  // `-----------------------------------------------------------------------------------------------------------------'

  [_SYSTEM] = LAYOUT_arrow_command(
      RESET,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
    _______, KC_VOLD, KC_VOLU, KC_MUTE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  CAPSLK,   NUMLK,   SCRLK, _______,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
    RGB_TOG, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX,  KC_F12
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
