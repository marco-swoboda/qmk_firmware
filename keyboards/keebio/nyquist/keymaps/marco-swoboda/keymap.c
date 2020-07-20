#include QMK_KEYBOARD_H
#include "keymap_german.h"
#include "sendstring_german.h"

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _COLEMAK 1
#define _WORKMAN 2
#define _LOWER 3
#define _RAISE 4
#define _FN3 5
#define _FN4 6
#define _ADJUST 16

enum custom_keycodes {
    QWERTY = SAFE_RANGE,
    COLEMAK,
    WORKMAN,
    LOWER,
    RAISE,
    FN3,
    FN4,
    ADJUST,
};

#define KC_ KC_TRNS

#define KC_CAPW LGUI(LSFT(KC_3))        // Capture whole screen
#define KC_CPYW LGUI(LSFT(LCTL(KC_3)))  // Copy whole screen
#define KC_CAPP LGUI(LSFT(KC_4))        // Capture portion of screen
#define KC_CPYP LGUI(LSFT(LCTL(KC_4)))  // Copy portion of screen
#define KC_X0 KC_ESC //MT(MOD_LCTL, KC_ESC)
#define KC_NUM LOWER
#define KC_SYM RAISE
#define KC_X3 LT(_FN3, KC_GRV)
#define KC_X4 MT(MOD_LSFT, KC_ENT)
#define KC_X5 BL_STEP
#define KC_X6 MT(MOD_LALT, KC_SPC)
#define KC_X7 MT(MOD_RALT, KC_BSPC)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*  QWERTY
 * ┌────────┬────────┬────────┬────────┬────────┬────────┐        ┌────────┬────────┬────────┬────────┬────────┬────────┐
 * |   X0   |   Q    |   W    |   E    |   R    |   T    |        |   Y    |   U    |   I    |   O    |   P    |  MINS  |
 * ├────────┼────────┼────────┼────────┼────────┼────────┤        ├────────┼────────┼────────┼────────┼────────┼────────┤
 * |  TAB   |   A    |   S    |   D    |   F    |   G    |        |   H    |   J    |   K    |   L    |  SCLN  |  QUOT  |
 * ├────────┼────────┼────────┼────────┼────────┼────────┤        ├────────┼────────┼────────┼────────┼────────┼────────┤
 * |  LSFT  |   Z    |   X    |   C    |   V    |   B    |        |   N    |   M    |  COMM  |  DOT   |  SLSH  |   X4   |
 * ├────────┼────────┼────────┼────────┼────────┼────────┤        ├────────┼────────┼────────┼────────┼────────┼────────┤
 * |  SPC   |  LCTL  |   X3   |  LGUI  |   X6   |  NUM   |        |  SYM   |   X7   |  EQL   |  BSLS  |   UP   |  BSPC  |
 * └────────┴────────┴────────┴────────┴────────┴────────┘        └────────┴────────┴────────┴────────┴────────┴────────┘
 */
  [_QWERTY] = LAYOUT_ortho_4x12_short(
    X0  , Q   , W , E   , R , T ,      Y , U , I   , O   , P   , MINS,
    TAB , A   , S , D   , F , G ,      H , J , K   , L   , SCLN, QUOT,
    LSFT, Z   , X , C   , V , B ,      N , M , COMM, DOT , SLSH, X4  ,
    SPC , LCTL, X3, LGUI, X6,NUM,     SYM, X7, EQL , BSLS, UP  , BSPC
),

/*  COLEMAK
 * ┌────────┬────────┬────────┬────────┬────────┬────────┐        ┌────────┬────────┬────────┬────────┬────────┬────────┐
 * |   X0   |   Q    |   W    |   F    |   P    |   G    |        |   J    |   L    |   U    |   Y    |  SCLN  |  MINS  |
 * ├────────┼────────┼────────┼────────┼────────┼────────┤        ├────────┼────────┼────────┼────────┼────────┼────────┤
 * |  TAB   |   A    |   R    |   S    |   T    |   D    |        |   H    |   N    |   E    |   I    |   O    |  QUOT  |
 * ├────────┼────────┼────────┼────────┼────────┼────────┤        ├────────┼────────┼────────┼────────┼────────┼────────┤
 * |  LSFT  |   Z    |   X    |   C    |   V    |   B    |        |   K    |   M    |  COMM  |  DOT   |  SLSH  |   X4   |
 * ├────────┼────────┼────────┼────────┼────────┼────────┤        ├────────┼────────┼────────┼────────┼────────┼────────┤
 * |  SPC   |  LCTL  |   X3   |  LGUI  |   X6   |  NUM   |        |  SYM   |   X7   |  EQL   |  BSLS  |   UP   |  BSPC  |
 * └────────┴────────┴────────┴────────┴────────┴────────┘        └────────┴────────┴────────┴────────┴────────┴────────┘
 */
    [_COLEMAK] = LAYOUT_ortho_4x12_short(
        X0    ,   Q    ,   W    ,   F    ,   P    ,   G  ,            J    ,   L    ,   U    ,   Y    ,  SCLN  ,  MINS  ,
        TAB   ,   A    ,   R    ,   S    ,   T    ,   D  ,            H    ,   N    ,   E    ,   I    ,   O    ,  QUOT  ,
        LSFT  ,   Z    ,   X    ,   C    ,   V    ,   B  ,            K    ,   M    ,  COMM  ,  DOT   ,  SLSH  ,   X4   ,
        SPC   ,  LCTL  ,   X3   ,  LGUI  ,   X6   ,  NUM ,           SYM   ,   X7   ,  EQL   ,  BSLS  ,   UP   ,  BSPC
    ),

/*  WORKMAN
 * ┌────────┬────────┬────────┬────────┬────────┬────────┐        ┌────────┬────────┬────────┬────────┬────────┬────────┐
 * |   X0   |   Q    |   D    |   R    |   W    |   B    |        |   J    |   F    |   U    |   P    |  SCLN  |  MINS  |
 * ├────────┼────────┼────────┼────────┼────────┼────────┤        ├────────┼────────┼────────┼────────┼────────┼────────┤
 * |  TAB   |   A    |   S    |   H    |   T    |   G    |        |   Y    |   N    |   E    |   O    |   I    |  QUOT  |
 * ├────────┼────────┼────────┼────────┼────────┼────────┤        ├────────┼────────┼────────┼────────┼────────┼────────┤
 * |  LSFT  |   Z    |   X    |   M    |   C    |   V    |        |   K    |   L    |  COMM  |  DOT   |  SLSH  |   X4   |
 * ├────────┼────────┼────────┼────────┼────────┼────────┤        ├────────┼────────┼────────┼────────┼────────┼────────┤
 * |  SPC   |  LCTL  |   X3   |  LGUI  |   X6   |  NUM   |        |  SYM   |   X7   |  EQL   |  BSLS  |   UP   |  BSPC  |
 * └────────┴────────┴────────┴────────┴────────┴────────┘        └────────┴────────┴────────┴────────┴────────┴────────┘
 */
    [_WORKMAN] = LAYOUT_ortho_4x12_short(
        X0    ,   Q    ,   D    ,   R    ,   W    ,   B    ,          J    ,   F    ,   U    ,   P    ,  SCLN  ,  MINS  ,
        TAB   ,   A    ,   S    ,   H    ,   T    ,   G    ,          Y    ,   N    ,   E    ,   O    ,   I    ,  QUOT  ,
        LSFT  ,   Z    ,   X    ,   M    ,   C    ,   V    ,          K    ,   L    ,  COMM  ,  DOT   ,  SLSH  ,   X4   ,
        SPC   ,  LCTL  ,   X3   ,  LGUI  ,   X6   ,  NUM   ,         SYM   ,   X7   ,  EQL   ,  BSLS  ,   UP   ,  BSPC
    ),

/*  LOWER (Zahlen) [HOLDNUM]
 * ┌────────┬────────┬────────┬────────┬────────┬────────┐        ┌────────┬────────┬────────┬────────┬────────┬────────┐
 * |   X5   |    1   |   2    |   3    |   4    |   5    |        |   6    |   7    |   8    |   9    |   0    |        |
 * ├────────┼────────┼────────┼────────┼────────┼────────┤        ├────────┼────────┼────────┼────────┼────────┼────────┤
 * |  DEL   |  CAPP  |  LEFT  |  RIGHT |   UP   |   [    |        |   ]    |   P4   |   P5   |   P6   |   +    |   |    |
 * ├────────┼────────┼────────┼────────┼────────┼────────┤        ├────────┼────────┼────────┼────────┼────────┼────────┤
 * |  MUTE  |  CPYP  |        |        |  DOWN  |   {    |        |   }    |   P1   |   P2   |   P3   |   -    |        |
 * ├────────┼────────┼────────┼────────┼────────┼────────┤        ├────────┼────────┼────────┼────────┼────────┼────────┤
 * |        |        |        |        |  DEL   |        |        |        |  DEL   |   P0   |  PDOT  |        |        |
 * └────────┴────────┴────────┴────────┴────────┴────────┘        └────────┴────────┴────────┴────────┴────────┴────────┘
 */
    [_LOWER] = LAYOUT_ortho_4x12_short(
        X5  ,   1    ,   2    ,   3    ,   4    ,   5    ,            6    ,   7    ,   8    ,   9    ,   0    ,        ,
        DEL ,  CAPP  ,  LEFT  ,   UP   ,  RGHT  ,  LBRC  ,           RBRC  ,   P4   ,   P5   ,   P6   ,  PLUS  ,  PIPE  ,
            ,  CPYP  ,        ,  DOWN  ,        ,  LCBR  ,           RCBR  ,   P1   ,   P2   ,   P3   ,  MINS  ,        ,
            ,        ,        ,        ,  DEL   ,        ,                 ,  DEL   ,   P0   ,  PDOT  ,        ,
    ),


/*  RAISE (Sonderzeichen) [HOLDSYM]
 * ┌────────┬────────┬────────┬────────┬────────┬────────┐        ┌────────┬────────┬────────┬────────┬────────┬────────┐
 * |   ~    |    !   |   @    |   #    |   $    |   %    |        |   ^    |   &    |   *    |   (    |   )    |        |
 * ├────────┼────────┼────────┼────────┼────────┼────────┤        ├────────┼────────┼────────┼────────┼────────┼────────┤
 * |  DEL   | M PREV | M NEXT | VOL UP | PAGE UP|  [_]   |        |   =    |  HOME  |        |        |        |   \    |
 * ├────────┼────────┼────────┼────────┼────────┼────────┤        ├────────┼────────┼────────┼────────┼────────┼────────┤
 * |  MUTE  | M STOP | M PLAY | VOL DN | PAGE DN|  [-]   |        |   +    |  END   |        |        |        |        |
 * ├────────┼────────┼────────┼────────┼────────┼────────┤        ├────────┼────────┼────────┼────────┼────────┼────────┤
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * └────────┴────────┴────────┴────────┴────────┴────────┘        └────────┴────────┴────────┴────────┴────────┴────────┘
 */
    [_RAISE] = LAYOUT_ortho_4x12_short(
        GRAVE   ,  EXLM  ,   AT   ,  HASH  ,  DLR   ,  PERC  ,           CIRC  ,  AMPR  ,  ASTR  ,  LPRN  ,  RPRN  ,        ,
        DEL     ,  MPRV  ,  MNXT  ,  VOLU  ,  PGUP  ,  UNDS  ,           EQL   ,  HOME  ,        ,        ,        ,  BSLS  ,
        MUTE    ,  MSTP  ,  MPLY  ,  VOLD  ,  PGDN  ,  MINS  ,           PLUS  ,  END   ,        ,        ,        ,        ,
                ,        ,        ,        ,        ,        ,                 ,        ,        ,        ,        ,
    ),

/*  _FN (Function Layer) [HOLD X3]
 * ┌────────┬────────┬────────┬────────┬────────┬────────┐        ┌────────┬────────┬────────┬────────┬────────┬────────┐
 * |  F12   |   F1   |   F2   |   F3   |   F4   |   F5   |        |   F6   |   F7   |   F8   |   F9   |  F10   |  F11   |
 * ├────────┼────────┼────────┼────────┼────────┼────────┤        ├────────┼────────┼────────┼────────┼────────┼────────┤
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * ├────────┼────────┼────────┼────────┼────────┼────────┤        ├────────┼────────┼────────┼────────┼────────┼────────┤
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * ├────────┼────────┼────────┼────────┼────────┼────────┤        ├────────┼────────┼────────┼────────┼────────┼────────┤
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * └────────┴────────┴────────┴────────┴────────┴────────┘        └────────┴────────┴────────┴────────┴────────┴────────┘
 */
    [_FN3] = LAYOUT_ortho_4x12_short(
        F12 ,   F1   ,   F2   ,   F3   ,   F4   ,   F5   ,            F6   ,   F7   ,   F8   ,   F9   ,  F10   ,  F11   ,
            ,        ,        ,        ,        ,        ,                 ,        ,        ,        ,        ,        ,
            ,        ,        ,        ,        ,        ,                 ,        ,        ,        ,        ,        ,
            ,        ,        ,        ,        ,        ,                 ,        ,        ,        ,        ,
    ),

/*  Adjust (Lower + Raise) (NUM +SYM)
 * ┌────────┬────────┬────────┬────────┬────────┬────────┐        ┌────────┬────────┬────────┬────────┬────────┬────────┐
 * |        | Reset  | RGB Tg | RGB Md | Hue Up | Hue Dn |        | Sat Up | Sat Dn | Val Up | Val Dn |        |        |
 * ├────────┼────────┼────────┼────────┼────────┼────────┤        ├────────┼────────┼────────┼────────┼────────┼────────┤
 * |        |        |        | Aud on | Aud off| AG norm|        |AG swap | Qwerty | Colemk | Workman|        |        |
 * ├────────┼────────┼────────┼────────┼────────┼────────┤        ├────────┼────────┼────────┼────────┼────────┼────────┤
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * ├────────┼────────┼────────┼────────┼────────┼────────┤        ├────────┼────────┼────────┼────────┼────────┼────────┤
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * └────────┴────────┴────────┴────────┴────────┴────────┘        └────────┴────────┴────────┴────────┴────────┴────────┘
 */
  [_ADJUST] = LAYOUT( \
    _______, RESET  , RGB_TOG, RGB_MOD, RGB_HUD, RGB_HUI, RGB_SAD, RGB_SAI, RGB_VAD, RGB_VAI, _______, _______, \
    _______, _______, _______, AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  COLEMAK, WORKMAN,  _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
  )

};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
float tone_dvorak[][2]     = SONG(DVORAK_SOUND);
float tone_colemak[][2]    = SONG(COLEMAK_SOUND);
#endif

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_qwerty);
        #endif
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case COLEMAK:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_colemak);
        #endif
        persistent_default_layer_set(1UL<<_COLEMAK);
      }
      return false;
      break;
    case WORKMAN:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_dvorak);
        #endif
        persistent_default_layer_set(1UL<<_WORKMAN);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}
