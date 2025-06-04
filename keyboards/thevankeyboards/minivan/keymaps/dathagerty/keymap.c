#include QMK_KEYBOARD_H


// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

#define _QW 0
#define _ST 1
#define _CM 2
#define _L1 3
#define _L2 4
#define _L3 5


#define QWERTY PDF(_QW)
#define STRNK PDF(_ST)
#define COLEMAK PDF(_CM)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QW] = LAYOUT( /* Qwerty */
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    MO(_L1), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, MO(_L1),
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, MO(_L2),
    KC_LCTL, MO(_L2), KC_LGUI,                   KC_ENT,  KC_SPC,                    KC_RALT, KC_ESC,  TG(_L3)
  ),
  [_ST] = LAYOUT( /* STRNK */
    KC_ESC,  KC_F,    KC_D,    KC_L,    KC_B,    KC_V,    KC_J,    KC_G,    KC_O,    KC_U,    KC_COMM, KC_BSPC,
    MO(_L1), KC_S,    KC_T,    KC_R,    KC_N,    KC_K,    KC_Y,    KC_M,    KC_A,    KC_E,    KC_I,    MO(_L1),
    KC_LSFT, KC_Z,    KC_Q,    KC_X,    KC_H,    KC_P,    KC_W,    KC_C,    KC_QUOT, KC_SCLN, KC_DOT,  MO(_L2),
    KC_LCTL, MO(_L2), KC_LGUI,                   KC_SPC,  KC_ENT,                    KC_RALT, KC_ESC,  TG(_L3)
  ),
  [_CM] = LAYOUT( /* Colemak */
    KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC,
    MO(_L1), KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    MO(_L1),
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, MO(_L2),
    KC_LCTL, MO(_L2), KC_LGUI,                   KC_ENT,  KC_SPC,                    KC_RALT, KC_ESC,  TG(_L3)
  ),
  [_L1] = LAYOUT( /* LAYER 1 */
    KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,
    _______, KC_BSLS, KC_QUOT, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_DOWN, KC_UP,   KC_LEFT, KC_RGHT, _______,
    _______, KC_ESC,  _______, KC_PSCR, _______, _______, _______, KC_MSTP, KC_MPLY, KC_MPRV, KC_MNXT, KC_RSFT,
    _______, KC_LGUI, _______,                   _______, _______,                   _______, _______, _______
  ),
  [_L2] = LAYOUT( /* LAYER 2 */
    _______, QWERTY,  STRNK,   COLEMAK, _______, _______, _______, KC_7,    KC_8,    KC_9,    KC_0,    _______,
    KC_ESC,  KC_PIPE, KC_DQUO, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_4,    KC_5,    KC_6,    KC_VOLU, KC_ENT,
    _______, _______, _______, _______, _______, _______, KC_0,    KC_1,    KC_2,    KC_3,    KC_VOLD, _______,
    _______, _______, _______,                   _______, _______,                   _______, _______, _______
  ),
  [_L3] = LAYOUT( /* LAYER 3 */
    _______, _______, _______, _______, _______, _______, _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   _______,
    KC_ESC,  _______, _______, _______, _______, _______, _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   _______,
    KC_LSFT, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,
    _______, KC_LSFT, KC_B,                      KC_SPC,  KC_C,                      _______, _______, _______
  )
};
