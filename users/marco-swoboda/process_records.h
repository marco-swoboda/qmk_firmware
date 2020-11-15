#pragma once
#include "marco-swoboda.h"
#include "tap_dance.h"


#if defined(KEYMAP_SAFE_RANGE)
#    define PLACEHOLDER_SAFE_RANGE KEYMAP_SAFE_RANGE
#else
#    define PLACEHOLDER_SAFE_RANGE SAFE_RANGE
#endif


enum userspace_custom_keycodes {
    KC_QWERTY = PLACEHOLDER_SAFE_RANGE, // Sets default layer to QWERTY
    KC_WORKMAN,                         // Sets default layer to WORKMAN
    KC_WORKMAN_P,                       // Sets default layer to WORKMAN_P
    KC_DVORAK,                          // Sets default layer to WORKMAN_P
    KC_DVORAK_AU,                       // Sets default layer to WORKMAN_P
    VRSN,                               // Prints QMK Firmware and board info
    // KC_MAKE,                         // Run keyboard's customized make command
    // KC_RGB_T,                        // Toggles RGB Layer Indication mode
    // RGB_IDL,                         // RGB Idling animations
    // KC_CCCV,                         // Hold to copy, tap to paste
    // KC_NUKE,                         // NUCLEAR LAUNCH DETECTED!!!
    // UC_FLIP,                         // (ಠ痊ಠ)┻━┻
    // UC_TABL,                         // ┬─┬ノ( º _ ºノ)
    // UC_SHRG,                         // ¯\_(ツ)_/¯
    // UC_DISA,                         // ಠ_ಠ
    NEW_SAFE_RANGE                      // use "NEWPLACEHOLDER for keymap specific codes
};

#define KC_LOWER   MO(_LOWER)
#define KC_RAISE   MO(_RAISE)
#define KC_ADJUST  MO(_ADJUST)
#define OS_LWR  OSL(_LOWER)
#define OS_RSE  OSL(_RAISE)

#define KC_LAYR KC_TRNS
#define KC_RESET RESET
#define KC_RST   KC_RESET


// Mod Tap Definitions
// -------------------
                                      //  Tap     Hold
                                      //  ------------------
#define BK_LWER LT(_LOWER, KC_BSPC)   //  BSPC    LOWER
#define SP_LWER LT(_LOWER, KC_SPC)    //  SPACE   LOWER
#define DL_RAIS LT(_RAISE, KC_DEL)    //  DEL     RAISE
#define ET_RAIS LT(_RAISE, KC_ENTER)  //  ENTER   RAISE
#define ALT_GRV LALT_T(KC_GRV)        //  `       LALT

// Tap Dance Definitions                  Single   | Single Hold |  Double     | Double Hold
#define KC_PARENS TD(TD_CLOSE_LPRN)   //  LPRN     | ----------- |  RPRN       | -------------

#ifdef TAP_DANCE_ENABLE
#define KC_H_CTL  TD(TD_H_CTL)        //  h        | LCTRL       |  ESC        | hh
#define KC_BRCL   TD(TD_LBRC)         //  [        |             |  {
#define KC_BRCR   TD(TD_RBRC)         //  ]        |             |  }
#else
#define KC_H_CTL  KC_H
#define KC_BRCL   KC_LBRC
#define KC_BRCR   KC_RBRC
#endif

/* OSM keycodes, to keep things clean and easy to change */
#define KC_MLSF OSM(MOD_LSFT)
#define KC_MRSF OSM(MOD_RSFT)

#define OS_LGUI OSM(MOD_LGUI)
#define OS_RGUI OSM(MOD_RGUI)
#define OS_LSFT OSM(MOD_LSFT)
#define OS_RSFT OSM(MOD_RSFT)
#define OS_LCTL OSM(MOD_LCTL)
#define OS_RCTL OSM(MOD_RCTL)
#define OS_LALT OSM(MOD_LALT)
#define OS_RALT OSM(MOD_RALT)
#define OS_MEH  OSM(MOD_MEH)
#define OS_HYPR OSM(MOD_HYPR)

#define ALT_APP LALT_T(KC_APP)
#define ALT_TAB LALT_T(KC_TAB)

#define MG_NKRO MAGIC_TOGGLE_NKRO

#define UC_IRNY UC(0x2E2E)
#define UC_CLUE UC(0x203D)


#define QWERTY  KC_QWERTY
#define WORKMAN_P  KC_WORKMAN_P
#define WORKMAN KC_WORKMAN
#define DVORAK  KC_DVORAK
#define DVORAK_AU  KC_DVORAK_AU

#define LOWER   MO(_LOWER)
#define RAISE   MO(_RAISE)
#define ADJUST  MO(_ADJUST)
#define PROGR   MO(_PROGRAMMER)

