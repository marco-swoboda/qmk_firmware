#include "marco-swoboda.h"




/* Return an integer that corresponds to what kind of tap dance should be executed.
 *
 * How to figure out tap dance state: interrupted and pressed.
 *
 * Interrupted: If the state of a dance dance is "interrupted", that means that another key has been hit
 *  under the tapping term. This is typically indicitive that you are trying to "tap" the key.
 *
 * Pressed: Whether or not the key is still being pressed. If this value is true, that means the tapping term
 *  has ended, but the key is still being pressed down. This generally means the key is being "held".
 *
 * One thing that is currenlty not possible with qmk software in regards to tap dance is to mimic the "permissive hold"
 *  feature. In general, advanced tap dances do not work well if they are used with commonly typed letters.
 *  For example "A". Tap dances are best used on non-letter keys that are not hit while typing letters.
 *
 * Good places to put an advanced tap dance:
 *  z,q,x,j,k,v,b, any function key, home/end, comma, semi-colon
 *
 * Criteria for "good placement" of a tap dance key:
 *  Not a key that is hit frequently in a sentence
 *  Not a key that is used frequently to double tap, for example 'tab' is often double tapped in a terminal, or
 *    in a web form. So 'tab' would be a poor choice for a tap dance.
 *  Letters used in common words as a double. For example 'p' in 'pepper'. If a tap dance function existed on the
 *    letter 'p', the word 'pepper' would be quite frustating to type.
 *
 * For the third point, there does exist the 'DOUBLE_SINGLE_TAP', however this is not fully tested
 *
 */
uint8_t cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        // Key has not been interrupted, but the key is still held. Means you want to send a 'HOLD'.
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        // DOUBLE_SINGLE_TAP is to distinguish between typing "pepper", and actually wanting a double tap
        // action when hitting 'pp'. Suggested use case for this return value is when you want to send two
        // keystrokes of the key, and not the 'double tap' action/macro.
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }

    // Assumes no one is trying to type the same letter three times (at least not quickly).
    // If your tap dance key is 'KC_W', and you want to type "www." quickly - then you will need to add
    // an exception here to return a 'TRIPLE_SINGLE_TAP', and define that enum just like 'DOUBLE_SINGLE_TAP'
    if (state->count == 3) {
        if (state->interrupted || !state->pressed) return TRIPLE_TAP;
        else return TRIPLE_HOLD;
    } else return 8; // Magic number. At some point this method will expand to work for more presses
}

// Create an instance of 'tap' for the 'h' tap dance.
static tap htap_state = {
    .is_press_action = true,
    .state = 0
};

void h_finished(qk_tap_dance_state_t *state, void *user_data) {
    htap_state.state = cur_dance(state);
    switch (htap_state.state) {
        case SINGLE_TAP: register_code(KC_H); break;
        case SINGLE_HOLD: register_code(KC_LCTRL); break;
        case DOUBLE_TAP: register_code(KC_ESC); break;
        case DOUBLE_HOLD: register_code(KC_LALT); break;
        // Last case is for fast typing. Assuming your key is `f`:
        // For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
        // In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
        case DOUBLE_SINGLE_TAP: tap_code(KC_H); register_code(KC_H);
    }
}

void h_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (htap_state.state) {
        case SINGLE_TAP: unregister_code(KC_H); break;
        case SINGLE_HOLD: unregister_code(KC_LCTRL); break;
        case DOUBLE_TAP: unregister_code(KC_ESC); break;
        case DOUBLE_HOLD: unregister_code(KC_LALT); break;
        case DOUBLE_SINGLE_TAP: unregister_code(KC_H); break;
    }
    htap_state.state = 0;
}


// Initialize tap structure associated with example tap dance key
static tap ql_tap_state = {
    .is_press_action = true,
    .state = 0
};

// Functions that control what our tap dance key does
void ql_finished(qk_tap_dance_state_t *state, void *user_data) {
    ql_tap_state.state = cur_dance(state);
    switch (ql_tap_state.state) {
        case SINGLE_TAP:
            tap_code(KC_QUOT);
            break;
        case SINGLE_HOLD:
            layer_on(_LOWER);
            break;
        case DOUBLE_TAP:
            // Check to see if the layer is already set
            if (layer_state_is(_LOWER)) {
                // If already set, then switch it off
                layer_off(_LOWER);
            } else {
                // If not already set, then switch the layer on
                layer_on(_LOWER);
            }
            break;
    }
}

void ql_reset(qk_tap_dance_state_t *state, void *user_data) {
    // If the key was held down and now is released then switch off the layer
    if (ql_tap_state.state == SINGLE_HOLD) {
        layer_off(_LOWER);
    }
    ql_tap_state.state = 0;
}

// tap dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for (, twice for )
    [TD_CLOSE_LPRN] = ACTION_TAP_DANCE_DOUBLE(KC_LPRN, KC_RPRN),
    // Tap once for [, twice for {
    [TD_LBRC] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_LCBR),
    // Tap once for ], twice for }
    [TD_RBRC] = ACTION_TAP_DANCE_DOUBLE(KC_RBRC, KC_RCBR),
    // 1=h, 1h=CTRL, 2t=ESC, 2h=LALT
    [TD_H_CTL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, h_finished, h_reset),

    [TD_QUOT_LAYR] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, ql_finished, ql_reset, 275)
};
