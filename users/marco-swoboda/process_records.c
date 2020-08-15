#include "marco-swoboda.h"

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef CONSOLE_ENABLE
  uprintf("process_record_user: kc: %u, col: %u, row: %u, pressed: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed);
#endif
  switch (keycode) {
    case KC_QWERTY ... KC_WORKMAN_P:
        if (record->event.pressed) {
            uint8_t mods = mod_config(get_mods() | get_oneshot_mods());
            if (!mods) {
                set_single_persistent_default_layer(keycode - KC_QWERTY);
#ifdef CONSOLE_ENABLE
  print("QWERTY");
#endif
            } else if (mods & MOD_MASK_SHIFT) {
#ifdef CONSOLE_ENABLE
  print("WORKMAN_P");
#endif
                set_single_persistent_default_layer(keycode - KC_QWERTY + 4);
            } else if (mods & MOD_MASK_CTRL) {
#ifdef CONSOLE_ENABLE
  print("WORKMAN");
#endif
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
#ifdef CONSOLE_ENABLE
    uprintf("layer_state_set_user: LAYER: %u\n", state);
#endif
    state = update_tri_layer_state(state, _RAISE, _LOWER, _ADJUST);
#ifdef CONSOLE_ENABLE
    uprintf("next state: LAYER: %u\n", state);
#endif
    return layer_state_set_keymap(state);
}

void encoder_update_user(uint8_t index, bool clockwise) {
#ifdef CONSOLE_ENABLE
    if (clockwise) {
        uprintf("encoder_update_user: clockwise index: %u\n", index);
    } else {
        uprintf("encoder_update_user: anticlockwise index: %u\n", index);
    }
#endif
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

// COMBO CUT AND PASTE
#ifdef COMBO_ENABLE
enum combo_events {
    XM_CUT,
    MC_COPY,
    XC_PASTE
};

const uint16_t PROGMEM cut_combo[] = {KC_X, KC_M, COMBO_END};
const uint16_t PROGMEM copy_combo[] = {KC_M, KC_C, COMBO_END};
const uint16_t PROGMEM paste_combo[] = {KC_X, KC_C, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    [XM_CUT] = COMBO_ACTION(cut_combo),
    [MC_COPY] = COMBO_ACTION(copy_combo),
    [XC_PASTE] = COMBO_ACTION(paste_combo)
};

void process_combo_event(uint8_t combo_index, bool pressed) {
    switch(combo_index) {
        case XC_PASTE:
            if (pressed) {
                tap_code16(LCTL(KC_V));
            }
            break;
        case XM_CUT:
            if (pressed) {
                tap_code16(LCTL(KC_X));
            }
            break;
        case MC_COPY:
            if (pressed) {
                tap_code16(LCTL(KC_C));
            }
            break;
    }
}
#endif
