#include "marco-swoboda.h"
#include "version.h"

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef CONSOLE_ENABLE
  uprintf("process_record_user: kc: %u, col: %u, row: %u, pressed: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed);
#endif
  switch (keycode) {
    case KC_QWERTY ... KC_DVORAK_AU:
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
            } else if (mods & MOD_MASK_CTRL) {
#ifdef CONSOLE_ENABLE
  print("DVORAK");
#endif
                set_single_persistent_default_layer(keycode - KC_QWERTY + 12);
            } else if (mods & MOD_MASK_CTRL) {
#ifdef CONSOLE_ENABLE
  print("DVORAK_AU");
#endif
                set_single_persistent_default_layer(keycode - KC_QWERTY + 16);
            }
        }
        break;
    case VRSN:  // Prints firmware version
        if (record->event.pressed) {
            send_string_with_delay_P(PSTR(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION ", Built on: " QMK_BUILDDATE), TAP_CODE_DELAY);
        }
        break;
  }
  return true;
}




