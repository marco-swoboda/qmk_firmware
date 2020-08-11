#include "marco-swoboda.h"

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case KC_QWERTY ... KC_WORKMAN_P:
        if (record->event.pressed) {
            uint8_t mods = mod_config(get_mods() | get_oneshot_mods());
            if (!mods) {
                set_single_persistent_default_layer(keycode - KC_QWERTY);
            } else if (mods & MOD_MASK_SHIFT) {
                set_single_persistent_default_layer(keycode - KC_QWERTY + 4);
            } else if (mods & MOD_MASK_CTRL) {
                set_single_persistent_default_layer(keycode - KC_QWERTY + 8);
            }
        }
        break;
  }
  return true;
}

__attribute__((weak)) layer_state_t layer_state_set_keymap(layer_state_t state) { return state; }

// on layer change, no matter where the change was initiated
// Then runs keymap's layer change check
layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _RAISE, _LOWER, _ADJUST);
#if defined(RGBLIGHT_ENABLE)
//    state = layer_state_set_rgb_light(state);
#endif  // RGBLIGHT_ENABLE
    return layer_state_set_keymap(state);
}

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    else if (index == 1) {
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
}
