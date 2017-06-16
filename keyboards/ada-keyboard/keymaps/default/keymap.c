#include "ada-keyboard.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QW 0
#define _RS 1

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QW] = /* Qwerty */ KEYMAP( \
    KC_ESC,  KC_1,  KC_2,    KC_3,    KC_4,    KC_5,                                    KC_6,   KC_7,    KC_8,    KC_9,    KC_0,     KC_EQL,
    KC_GRV,  KC_Q,  KC_W,    KC_E,    KC_R,    KC_T,                                    KC_Y,   KC_U,    KC_I,    KC_O,    KC_P,     KC_UNDS,
    KC_TAB,  KC_A,  KC_S,    KC_D,    KC_F,    KC_G,                                    KC_H,   KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,
    KC_LSFT, KC_Z,  KC_X,    KC_C,    KC_V,    KC_B,                                    KC_N,   KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT,
                    KC_TRNS, KC_LALT, KC_LGUI, KC_BSPC,  KC_ESC,              KC_ENT,   KC_SPC, KC_RGUI, KC_RALT, KC_BSLS,
                                               OSL(_RS), OSM(MOD_LCTL),       OSM(MOD_LCTL), OSL(_RS)
  ),
  [_RS] = /* [> RAISE <] */ KEYMAP( \
    KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_5,                          KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
    KC_TRNS, KC_EXLM, KC_AT,   KC_HASH, KC_ESC,  KC_PERC,                       KC_LCBR, KC_LBRC, KC_PIPE, KC_RBRC, KC_RCBR, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_CIRC, KC_PGUP, KC_PGDN, KC_DLR,                        KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_EQL,  KC_LPRN, KC_RPRN, KC_ASTR,                       KC_TRNS, KC_PLUS, KC_AMPR, KC_MINS, KC_TRNS, KC_TRNS,
                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                 KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS
  )
};

const uint16_t PROGMEM fn_actions[] = {

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
          if (record->event.pressed) {
            register_code(KC_RSFT);
          } else {
            unregister_code(KC_RSFT);
          }
        break;
      }
    return MACRO_NONE;
};
