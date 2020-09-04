#pragma once

typedef struct {
    bool is_press_action;
    uint8_t state;
} tap;

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP, // Send two single taps
    TRIPLE_TAP,
    TRIPLE_HOLD
};

// tap dance declarations
enum {
    TD_CLOSE_LPRN,
    TD_H_CTL,
    TD_LBRC, // [, {
    TD_RBRC, // ], }
    TD_QUOT_LAYR, // layer switch/toggle
};

