#include "marco-swoboda.h"


// clang-format off
#define LAYOUT_wrapper(...)                  LAYOUT(__VA_ARGS__)

/*
 * The `LAYOUT_iris_base` macro is a template to allow the use of identical
 * modifiers for the default layouts (eg QWERTY, Colemak, Dvorak, etc), so
 * that there is no need to set them up for each layout, and modify all of
 * them if I want to change them.  This helps to keep consistency and ease
 * of use. K## is a placeholder to pass through the individual keycodes
 */
#define LAYOUT_iris_base( \
    K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, \
    K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, \
    K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, \
    K31, K32, K33, K34, K35, K36, K37, K38, K39, K3A  \
  ) \
  LAYOUT_wrapper( \
     KC_ESC,         K01, K02, K03,      K04,     K05,                           K06,     K07,     K08,     K09,     K0A,     KC_MINS, \
     LALT_T(KC_TAB), K11, K12, K13,      K14,     K15,                           K16,     K17,     K18,     K19,     K1A,     KC_BSLS, \
     KC_TAB,         K21, K22, K23,      K24,     K25,                           K26,     K27,     K28,     K29,     K2A,     RALT_T(KC_QUOT), \
     OS_LSFT, CTL_T(K31), K32, K33,      K34,     K35,     OS_LALT,    OS_RGUI,  K36,     K37,     K38,     K39, RCTL_T(K3A), OS_RSFT, \
                             KC_GRV,   KC_SPC,     BK_LWER,                   DL_RAIS,  KC_ENTER,  PROGR                           \
  )
#define LAYOUT_iris_base_wrapper(...)       LAYOUT_iris_base(__VA_ARGS__)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_iris_base_wrapper (
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
              ________________NUMBER_LEFT________________,                            ________________NUMBER_RIGHT_______________,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
              _________________QWERTY_L1_________________,                            _________________QWERTY_R1_________________,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
              _________________QWERTY_L2_________________,                            _________________QWERTY_R2_________________,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
              _________________QWERTY_L3_________________,                            _________________QWERTY_R3_________________
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘

                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_WORKMAN] = LAYOUT_iris_base_wrapper(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
              ________________NUMBER_LEFT________________,                            ________________NUMBER_RIGHT_______________,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
              _________________WORKMAN_L1________________,                               KC_J,    KC_F,    KC_U,    KC_P,    KC_SCLN,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
              _________________WORKMAN_L2________________,                               KC_Y,    KC_N,    KC_E,    KC_O,    KC_I,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
              _________________WORKMAN_L3________________,                               KC_K,    KC_L,    KC_COMM, KC_DOT,  KC_SLSH
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘

                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_WORKMAN_P] = LAYOUT_iris_base_wrapper(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
              _________________LOWER_L1__________________,                            _________________LOWER_R1__________________,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
              _________________WORKMAN_L1________________,                            _________________WORKMAN_R1________________,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
              _________________WORKMAN_L2________________,                            _________________WORKMAN_R2________________,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
              _________________WORKMAN_L3________________,                            _________________WORKMAN_R3________________
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘

                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_LOWER] = LAYOUT_wrapper(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_TILD, _________________LOWER_L1__________________,                            _________________LOWER_R1__________________, KC_PGUP,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     RESET,   ________________NUMBER_LEFT________________,                            ________________NUMBER_RIGHT_______________, KC_PGDN,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_DEL,  BL_STEP, KC_LEFT, KC_UP   , KC_RGHT, KC_LBRC,                            KC_RBRC, KC_P4,   KC_P5,   KC_P6,   KC_PLUS, KC_HOME,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, KC_DOWN,KC_PARENS, KC_LCBR,KC_PARENS,          KC_RPRN, KC_RCBR, KC_P1,   KC_P2,   KC_P3,   KC_MINS, KC_END,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, KC_LAYR,                    KC_LAYR, _______, KC_P0
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_RAISE] = LAYOUT_wrapper(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_F12,  _________________FUNC_LEFT_________________,                            _________________FUNC_RIGHT________________,  KC_F11,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     RGB_TOG, _________________LOWER_L1__________________,                            _________________LOWER_R1__________________, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     RGB_MOD, KC_MPRV, KC_MNXT, KC_VOLU, KC_PGUP, KC_UNDS,                            KC_EQL,  KC_HOME, RGB_HUI, RGB_SAI, RGB_VAI, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_MUTE, KC_MSTP, KC_MPLY, KC_VOLD, KC_PGDN, KC_MINS,KC_PARENS,          _______, KC_PLUS, KC_END,  RGB_HUD, RGB_SAD, RGB_VAD, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, KC_LAYR,                   KC_LAYR, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_ADJUST] = LAYOUT_wrapper(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, RESET  , RGB_TOG, RGB_MOD, RGB_HUD, RGB_HUI,                            RGB_SAD, RGB_SAI , RGB_VAD, RGB_VAI, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, AU_ON,   AU_OFF,  _______,                            _______, QWERTY, WORKMAN_P, WORKMAN, DEBUG , _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, VRSN    , _______,          _______, _______, _______, _______, _______, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, KC_LAYR,                   KC_LAYR, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_PROGRAMMER] = LAYOUT_wrapper(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
      _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
      _______,UC(0x00C4),UC(0x00D6),UC(0x00DC),UC(0x20AC), _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
      _______,UC(0x00E4),UC(0x00F6),UC(0x00FC),UC(0x00DF), _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
      KC_LCBR, KC_LBRC, KC_LPRN, KC_RPRN, KC_RBRC, KC_RCBR, _______,          _______, _______, _______, _______, _______, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, KC_LAYR
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  )
};
