// Planck Light Keymap
// 11.20.19

#include QMK_KEYBOARD_H
#include "action_layer.h"
#ifdef AUDIO_ENABLE
  #include "audio.h"
#endif

// Empty Space Keycodes
#define _______ KC_TRNS
#define XXXXXXX KC_NO

// Tap-Hold Keycodes
#define MO_FN0 MO(_FN0)
#define MO_FN1 MO(_FN1)
#define TAB_FN1 LT(_FN1, KC_TAB)
#define ENT_FN0 LT(_FN0, KC_ENT)
#define APP_SFT RSFT_T(KC_APP)

// Tapping Toggle Keycodes
#define TT_FN2 TT(_FN2)

// Tap Dance Keycodes
#define PLS_AST TD(PLUS_ASTERISK)
#define MNS_SLS TD(MINUS_SLASH)
#define DOT_CLN TD(DOT_COLON)

// Combined Layers
#define SYSTEM ((1UL << _FN0) | (1UL << _FN1))

// Layer Enumerations
enum layers {
  _BASE,
  _FN0,
  _FN1,
  _FN2,
  _SYSTEM
};

// Custom Key Enumerations
enum keycodes {
  BASE = SAFE_RANGE,
  SCRLK,
  CAPSLK,
  NUMLK,
  RGB_OP1,
  RGB_OP2,
  RGB_OP3,
  RGB_OP4,
  RGB_OP5,
  RGB_SPE,
  RGB_MDE,
  RGB_HUE,
  RGB_SAT,
  RGB_VAL
};

// Tap Dance Enumerations
enum tapdance {
  PLUS_ASTERISK,
  MINUS_SLASH,
  DOT_COLON
};

extern keymap_config_t keymap_config;

// Keymap
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // Base
  // ,-----------------------------------------------------------------------------------------------------------.
  // |    GESC|       Q|       W|       E|       R|       T|       Y|       U|       I|       O|       P|    BSPC|
  // |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
  // | TAB_FN1|       A|       S|       D|       F|       G|       H|       J|       K|       L|       ;| ENT_FN0|
  // |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
  // |  LShift|       Z|       X|       C|       V|       B|       N|       M|       ,|       .|       /| APP_SFT|
  // |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+--------|
  // |   LCtrl|  TT_FN2|    LGUI|    LAlt|  MO_FN0|            Space|  MO_FN1|    Left|    Down|      Up|   Right|
  // `-----------------------------------------------------------------------------------------------------------'

  [_BASE] = KEYMAP(
    KC_GESC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSPC,
    TAB_FN1,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, ENT_FN0,
    KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, APP_SFT,
    KC_LCTL,  TT_FN2, KC_LGUI, KC_LALT,  MO_FN0,  KC_SPC,  KC_SPC,  MO_FN1, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT
  ),

  // Fn0
  // ,-----------------------------------------------------------------------------------------------------------.
  // |   Pause|       !|       @|       #|       $|       %|       ^|       &|       *|       (|       )|    Menu|
  // |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
  // | ______ |       ||       _|       +|       {|       }|    Home|    PgDn|    PgUp|     End|       "| ______ |
  // |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
  // | ______ | ______ | ______ | ______ | ______ | ______ | ______ | ______ | ______ | ______ | ______ | ______ |
  // |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+--------|
  // | ______ | ______ | ______ | ______ | ______ | _______________ | ______ | ______ | ______ | ______ | ______ |
  // `-----------------------------------------------------------------------------------------------------------'

  [_FN0] = KEYMAP(
    KC_PAUS, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,  KC_APP,
    _______, KC_PIPE, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_HOME, KC_PGDN, KC_PGUP,  KC_END, KC_DQUO, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

  // Fn1
  // ,-----------------------------------------------------------------------------------------------------------.
  // |  PrtScr|       1|       2|       3|       4|       5|       6|       7|       8|       9|       0|  Delete|
  // |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
  // | ______ |       \|       -|       =|       [|       ]|    Left|    Down|      Up|   Right|       '| ______ |
  // |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
  // | ______ | ______ | ______ | ______ | ______ | ______ | ______ | ______ | ______ | ______ | ______ | ______ |
  // |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+--------|
  // | ______ | ______ | ______ | ______ | ______ | _______________ | ______ | ______ | ______ | ______ | ______ |
  // `-----------------------------------------------------------------------------------------------------------'

  [_FN1] = KEYMAP(
    KC_PSCR,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_DEL,
    _______, KC_BSLS, KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, KC_QUOT, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

  // Fn2
  // ,-----------------------------------------------------------------------------------------------------------.
  // | ______ |      F1|      F2|      F3|      F4|    Vol+|   NUMLK|       7|       8|       9|       0| ______ |
  // |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
  // | ______ |      F5|      F6|      F7|      F8|    Vol-| PLS_AST|       4|       5|       6| DOT_CLN| ______ |
  // |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
  // | ______ |      F9|     F10|     F11|     F12|    Mute| MNS_SLS|       1|       2|       3|   Enter| ______ |
  // |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+--------|
  // | ______ | ______ | ______ | ______ | ______ | _______________ | ______ | ______ | ______ | ______ | ______ |
  // `-----------------------------------------------------------------------------------------------------------'

  [_FN2] = KEYMAP(
    _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4, KC_VOLU,   NUMLK,   KC_P7,   KC_P8,   KC_P9,   KC_P0, _______,
    _______,   KC_F5,   KC_F6,   KC_F7,   KC_F8, KC_VOLD, PLS_AST,   KC_P4,   KC_P5,   KC_P6, DOT_CLN, _______,
    _______,   KC_F9,  KC_F10,  KC_F11,  KC_F12, KC_MUTE, MNS_SLS,   KC_P1,   KC_P2,   KC_P3, KC_PENT, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

  // System (Fn0 + Fn1)
  // ,-----------------------------------------------------------------------------------------------------------.
  // |   RESET|        |        |        |  AU_TOG|        |        |  MU_TOG|        |        |        |  CAPSLK|
  // |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
  // |        |        |        |        |        |        |        |        |        |        |        |        |
  // |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
  // |        | RGB_OP1| RGB_OP2| RGB_OP3| RGB_OP4| RGB_OP5| RGB_SPE| RGB_MDE| RGB_HUE| RGB_SAT| RGB_VAL|        |
  // |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+--------|
  // | RGB_TOG|        |        |        | ______ |       Music Mode| ______ |        |        |        |   SCRLK|
  // `-----------------------------------------------------------------------------------------------------------'

  [_SYSTEM] = KEYMAP(
      RESET, XXXXXXX, XXXXXXX, XXXXXXX,  AU_TOG, XXXXXXX, XXXXXXX,   MU_TOG, XXXXXXX, XXXXXXX, XXXXXXX, CAPSLK,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
    _______, RGB_OP1, RGB_OP2, RGB_OP3, RGB_OP4, RGB_OP5, RGB_SPE, RGB_MDE, RGB_HUE, RGB_SAT, RGB_VAL, _______,
    RGB_TOG, XXXXXXX, XXXXXXX, XXXXXXX, _______,  MU_MOD,  MU_MOD, _______, XXXXXXX, XXXXXXX, XXXXXXX,   SCRLK
  )
};

// Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  [PLUS_ASTERISK] = ACTION_TAP_DANCE_DOUBLE(KC_PPLS, KC_PAST),
  [MINUS_SLASH] = ACTION_TAP_DANCE_DOUBLE(KC_PMNS, KC_PSLS),
  [DOT_COLON] = ACTION_TAP_DANCE_DOUBLE(KC_PDOT, KC_COLN)
};

// Song List
#ifdef AUDIO_ENABLE
  float tone_startup[][2] = SONG(PLANCK_SOUND);
  float tone_scroll[][2] = SONG(SCROLL_LOCK_ON_SOUND);
  float tone_noscroll[][2] = SONG(SCROLL_LOCK_OFF_SOUND);
  float tone_caps[][2] = SONG(CAPS_LOCK_ON_SOUND);
  float tone_nocaps[][2] = SONG(CAPS_LOCK_OFF_SOUND);
  float tone_num[][2] = SONG(NUM_LOCK_ON_SOUND);
  float tone_nonum[][2] = SONG(NUM_LOCK_OFF_SOUND);
#endif

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
    case RGB_OP1:
      if (record->event.pressed) {
        #ifdef RGB_MATRIX_ENABLE
          uint8_t shifted = get_mods() & MOD_MASK_SHIFT;
          if (shifted) {
            // Red breathing
            rgblight_mode(RGB_MATRIX_BREATHING);
            rgblight_sethsv(0, 255, 255);
          } else {
            // Red static
            rgblight_mode(RGB_MATRIX_SOLID_COLOR);
            rgblight_sethsv(0, 255, 255);
          }
        #endif
      }
      return false;
    case RGB_OP2:
      if (record->event.pressed) {
        #ifdef RGB_MATRIX_ENABLE
          uint8_t shifted = get_mods() & MOD_MASK_SHIFT;
          if (shifted) {
            // Green breathing
            rgblight_mode(RGB_MATRIX_BREATHING);
            rgblight_sethsv(85, 255, 255);
          } else {
            // Green static
            rgblight_mode(RGB_MATRIX_SOLID_COLOR);
            rgblight_sethsv(85, 255, 255);
          }
        #endif
      }
      return false;
    case RGB_OP3:
      if (record->event.pressed) {
        #ifdef RGB_MATRIX_ENABLE
          uint8_t shifted = get_mods() & MOD_MASK_SHIFT;
          if (shifted) {
            // Blue breathing
            rgblight_mode(RGB_MATRIX_BREATHING);
            rgblight_sethsv(170, 255, 255);
          } else {
            // Blue static
            rgblight_mode(RGB_MATRIX_SOLID_COLOR);
            rgblight_sethsv(170, 255, 255);
          }
        #endif
      }
      return false;
    case RGB_OP4:
      if (record->event.pressed) {
        #ifdef RGB_MATRIX_ENABLE
          uint8_t shifted = get_mods() & MOD_MASK_SHIFT;
          if (shifted) {
            // White breathing
            rgblight_mode(RGB_MATRIX_BREATHING);
            rgblight_sethsv(0, 0, 255);
          } else {
            // White static
            rgblight_mode(RGB_MATRIX_SOLID_COLOR);
            rgblight_sethsv(0, 0, 255);
          }
        #endif
      }
      return false;
          case RGB_OP5:
      if (record->event.pressed) {
        #ifdef RGB_MATRIX_ENABLE
          uint8_t shifted = get_mods() & MOD_MASK_SHIFT;
          if (shifted) {
            // Cyan breathing
            rgblight_mode(RGB_MATRIX_BREATHING);
            rgblight_sethsv(128, 255, 255);
          } else {
            // Cyan static
            rgblight_mode(RGB_MATRIX_SOLID_COLOR);
            rgblight_sethsv(128, 255, 255);
          }
        #endif
      }
      return false;
    case RGB_SPE:
      if (record->event.pressed) {
        #ifdef RGB_MATRIX_ENABLE
          uint8_t shifted = get_mods() & MOD_MASK_SHIFT;
          if (shifted) {
            rgblight_decrease_speed();
          } else {
            rgblight_increase_speed();
          }
        #endif
      }
      return false;
    case RGB_MDE:
      if (record->event.pressed) {
        #ifdef RGB_MATRIX_ENABLE
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
        #ifdef RGB_MATRIX_ENABLE
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
        #ifdef RGB_MATRIX_ENABLE
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
        #ifdef RGB_MATRIX_ENABLE
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

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case MO_FN0:
    case MO_FN1:
      return false;
    default:
      return true;
  }
}

// Disable light in middle of 2U position
#ifdef RGB_MATRIX_ENABLE
  void rgb_matrix_indicators_user(void) {
    rgb_matrix_set_color(42, 0, 0, 0);
  }
#endif

// Startup Tasks
void matrix_init_user(void) {
  #ifdef AUDIO_ENABLE
    startup_user();
  #endif
}

// Startup Music
#ifdef AUDIO_ENABLE
  void startup_user(void) {
    wait_ms(20); // gets rid of tick
    PLAY_SONG(tone_startup);
  }
#endif
