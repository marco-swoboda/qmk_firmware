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




