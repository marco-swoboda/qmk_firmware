#include "marco-swoboda.h"

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
