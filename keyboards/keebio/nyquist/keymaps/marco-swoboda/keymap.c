#include "marco-swoboda.h"

/*
 * The `LAYOUT_levinson_base` macro is a template to allow the use of identical
 * modifiers for the default layouts (eg QWERTY, Colemak, Dvorak, etc), so
 * that there is no need to set them up for each layout, and modify all of
 * them if I want to change them.  This helps to keep consistency and ease
 * of use. K## is a placeholder to pass through the individual keycodes
 */

// clang-format off

#define LAYOUT_wrapper(...)                  LAYOUT_ortho_4x12(__VA_ARGS__)

#define LAYOUT_levinson_base( \
    K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, \
    K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, \
    K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A  \
  ) \
  LAYOUT_wrapper( \
    KC_ESC,         K01,        K02,     K03,     K04,     K05,           K06,      K07,     K08,     K09,     K0A,     KC_MINS, \
    LALT_T(KC_TAB), K11,        K12,     K13,     K14,     K15,           K16,      K17,     K18,     K19,     K1A,     KC_BSLS, \
    KC_TAB,         K21,        K22,     K23,     K24,     K25,           K26,      K27,     K28,     K29,     K2A,     KC_QUOT, \
    OS_LSFT,        OS_RCTL,    KC_GRV,  OS_LGUI, SP_LWER, BK_LWER,       DL_RAIS,  ET_RAIS, OS_RGUI, OS_RALT, OS_RCTL, OS_RSFT  \
  )

#define LAYOUT_levinson_base_wrapper(...)       LAYOUT_levinson_base(__VA_ARGS__)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_levinson_base_wrapper (
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,
    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH
  ),

  [_WORKMAN] = LAYOUT_levinson_base_wrapper(
    KC_Q,    KC_D,    KC_R,    KC_W,    KC_B,    KC_J,    KC_F,    KC_U,    KC_P,    KC_SCLN,
    KC_A,    KC_S,    KC_H,    KC_T,    KC_G,    KC_Y,    KC_N,    KC_E,    KC_O,    KC_I,
    KC_Z,    KC_X,    KC_M,    KC_C,    KC_V,    KC_K,    KC_L,    KC_COMM, KC_DOT,  KC_SLSH
  ),

  [_LOWER] = LAYOUT_wrapper(
     KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,     KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PGUP,
     RESET,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_PGDN,
     KC_DEL,  _______, KC_LEFT, KC_RGHT, KC_UP,   KC_LBRC,     KC_RBRC, KC_P4,   KC_P5,   KC_P6,   KC_PLUS, KC_HOME,
     BL_STEP, _______, _______, _______, _______, _______,     _______, _______, KC_P2,   KC_P3,   KC_MINS, KC_END
  ),

  [_RAISE] = LAYOUT_wrapper(
     KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
     RGB_TOG, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
     RGB_MOD, KC_MPRV, KC_MNXT, KC_VOLU, KC_PGUP, KC_UNDS,      KC_EQL,  KC_HOME, RGB_HUI, RGB_SAI, RGB_VAI, _______,
     KC_MUTE, KC_MSTP, KC_MPLY, KC_VOLD, _______, _______,      _______, _______, RGB_HUD, RGB_SAD, RGB_VAD, _______
  ),

  [_ADJUST] = LAYOUT_wrapper(
     _______, _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______, _______,
     _______, RESET  , RGB_TOG, RGB_MOD, RGB_HUD, RGB_HUI,       RGB_SAD, RGB_SAI, RGB_VAD, RGB_VAI, _______, _______,
     _______, _______, _______, AU_ON,   AU_OFF,  _______,       _______, QWERTY , WORKMAN, WORKMAN, DEBUG , _______,
     _______, _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______, _______
  )
};
