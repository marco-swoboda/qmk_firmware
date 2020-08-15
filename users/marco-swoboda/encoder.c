#include "marco-swoboda.h"

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
