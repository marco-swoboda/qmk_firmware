#pragma once
#include QMK_KEYBOARD_H

#include "wrappers.h"
#include "process_records.h"

#include "tap_dance.h"


/* Define layer names */
enum userspace_layers {
    _QWERTY  = 0,
    _WORKMAN,
    _WORKMAN_P,
    _LOWER,
    _RAISE,
    _ADJUST,
    _PROGRAMMER,
};

