#include "marco-swoboda.h"


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


/*
//  Happens before most anything is started. Good for hardware setup that you want running very early.
void keyboard_pre_init_user(void) {
#ifdef CONSOLE_ENABLE
    print("keyboard_pre_init_user\n");
#endif
}

//  Happens before most anything is started. Good for hardware setup that you want running very early.
void keyboard_pre_init_kb(void) {
#ifdef CONSOLE_ENABLE
    print("keyboard_pre_init_kb\n");
#endif
}

// Happens midway through the firmware’s startup process. Hardware is initialized, but features may not be yet.
void matrix_init_kb(void) {
#ifdef CONSOLE_ENABLE
    print("matrix_init_kb\n");
#endif
}

// Happens midway through the firmware’s startup process. Hardware is initialized, but features may not be yet.
void matrix_init_user(void) {
#ifdef CONSOLE_ENABLE
    print("matrix_init_user\n");
#endif
}

// Happens at the end of the firmware’s startup process. This is where you’d want to put “customization” code, for the most part.
void keyboard_post_init_kb(void) {
#ifdef CONSOLE_ENABLE
    print("keyboard_post_init_kb\n");
#endif
}

// Happens at the end of the firmware’s startup process. This is where you’d want to put “customization” code, for the most part.
void keyboard_post_init_user(void) {
#ifdef CONSOLE_ENABLE
    print("keyboard_post_init_user\n");
#endif
}

// called when the system board is idled and when it wakes up, respectively
void suspend_power_down_kb(void) {
#ifdef CONSOLE_ENABLE
    print("suspend_power_down_kb\n");
#endif
}

// called when the system board is idled and when it wakes up, respectively
void suspend_power_down_user(void) {
#ifdef CONSOLE_ENABLE
    print("suspend_power_down_user\n");
#endif
}

// called when the system board is idled and when it wakes up, respectively
void suspend_wakeup_init_kb(void) {
#ifdef CONSOLE_ENABLE
    print("suspend_wakeup_init_kb\n");
#endif
}
// called when the system board is idled and when it wakes up, respectively
void suspend_wakeup_init_user(void) {
#ifdef CONSOLE_ENABLE
    print("suspend_wakeup_init_user\n");
#endif
}

void eeconfig_init_user(void) {  // EEPROM is getting reset!
#ifdef CONSOLE_ENABLE
    print("eeconfig_init_user\n");
#endif
}
// weitere Funktionen:
// Keyboard/Revision: void eeconfig_init_kb(void), uint32_t eeconfig_read_kb(void) and void eeconfig_update_kb(uint32_t val)
// Keymap: void eeconfig_init_user(void), uint32_t eeconfig_read_user(void) and void eeconfig_update_user(uint32_t val)

*/
