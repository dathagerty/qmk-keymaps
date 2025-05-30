/* Copyright 2021 Jane Bernhardt
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/* Good on you for modifying your layout! if you don't have
 * time to read the QMK docs, a list of keycodes can be found at
 * https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes.md
 */

#include QMK_KEYBOARD_H

enum {
    _BAS, // 0 - STRNK layout
    _TAP, // 1 - STRNK no home row mods
    _MED, // 2 - media keys
    _NAV, // 3 - navigation keys
    _MOU, // 4 - mouse keys
    _SYM, // 5 - symbols
    _NUM, // 6 - numbers/function/motion
    _FUN, // 7 - function keys
};

#define MAC_RDO SGUI(KC_Z)
#define MAC_PST G(KC_V)
#define MAC_CPY G(KC_C)
#define MAC_CUT G(KC_X)
#define MAC_UDO G(KC_Z)

#define TG_BASE TD(TD_TBAS)
#define TG_TAP TD(TD_TTAP)

#define HOME_S GUI_T(KC_S)
#define HOME_T ALT_T(KC_T)
#define HOME_R CTL_T(KC_R)
#define HOME_N SFT_T(KC_N)
#define HOME_Z SGUI_T(KC_Z)

#define HOME_M SFT_T(KC_M)
#define HOME_A CTL_T(KC_A)
#define HOME_E ALT_T(KC_E)
#define HOME_I GUI_T(KC_I)
#define HOME_DT SGUI_T(KC_DOT)

#define MED_ESC LT(_MED, KC_ESC)
#define NAV_SPC LT(_NAV, KC_SPC)
#define MOU_TAB LT(_MOU, KC_TAB)
#define SYM_ENT LT(_SYM, KC_ENT)
#define NUM_BSP LT(_NUM, KC_BSPC)
#define FUN_DEL LT(_FUN, KC_DEL)

#define RAYCAST A(KC_SPC)


// Look Ma, I'm Gene Kelly!
// It's tap dances

// TODO: tap dance for caps word
enum {
    TD_TBAS,
    TD_TTAP,
    TD_CW
};

tap_dance_action_t tap_dance_actions[] = {
    [TD_TBAS] = ACTION_TAP_DANCE_LAYER_TOGGLE(KC_ESC, _TAP),
    [TD_TTAP] = ACTION_TAP_DANCE_LAYER_TOGGLE(KC_NO, _TAP),
};

// Welcome to good keyboard, home of the good keyboard, can I take your order?
// Combos
//
//  ,-----------------------------.     ,-----------------------------.
//  |  F  |  D  /  L  |  B  |  V  |     |  J  |  G  |  O  \  U  |  ,  |
//  |-----+-----+-----+-----+-----|     |-----+-----+-----+-----+-----|
//  |  S  |  T  |  R  :  N  <  K  |     |  Y  >  M  =  A  |  E  |  I  |
//  |-----+-----+-----+-----+-----|     |-----+-----+-----+-----+-----|
//  |  Z  |  Q  |  X  -  H  |  P  |     |  W  |  C  _  '  |  ;  |  .  |
//  `-----------------------------'     `-----------------------------'
//               .-----------------.   .------------------.
//               | ESC | TAB | SPC HYPER ENT | BSPC | DEL |
//               '-----------------'   '------------------'

enum combos {
    OU_BSLS,
    NK_LESS,
    YM_GRTR,
    XH_DASH,
    CQ_UNDS,
    DL_SLSH,
    TE_HYPR,
    RN_COLN,
    MA_EQL
};

const uint16_t PROGMEM ou_combo[] = {KC_O, KC_U, COMBO_END};
const uint16_t PROGMEM nk_combo[] = {HOME_N, KC_K, COMBO_END};
const uint16_t PROGMEM ym_combo[] = {KC_Y, HOME_M, COMBO_END};
const uint16_t PROGMEM xh_combo[] = {KC_X, KC_H, COMBO_END};
const uint16_t PROGMEM cq_combo[] = {KC_C, KC_Q, COMBO_END};
const uint16_t PROGMEM dl_combo[] = {KC_D, KC_L, COMBO_END};
const uint16_t PROGMEM te_combo[] = {LT(_MOU, KC_TAB), LT(_SYM, KC_ENT), COMBO_END};
const uint16_t PROGMEM rn_combo[] = {HOME_R, HOME_N, COMBO_END};
const uint16_t PROGMEM ma_combo[] = {HOME_M, HOME_A, COMBO_END};

combo_t key_combos[] = {
    [OU_BSLS] = COMBO(ou_combo, KC_BSLS),
    [NK_LESS] = COMBO(nk_combo, KC_LT),
    [YM_GRTR] = COMBO(ym_combo, KC_GT),
    [XH_DASH] = COMBO(xh_combo, KC_MINS),
    [CQ_UNDS] = COMBO(cq_combo, KC_UNDS),
    [DL_SLSH] = COMBO(dl_combo, KC_SLSH),
    [TE_HYPR] = COMBO(te_combo, OSM(MOD_HYPR)),
    [RN_COLN] = COMBO(rn_combo, KC_COLN),
    [MA_EQL] = COMBO(ma_combo, KC_EQL),
};

const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
    LAYOUT_split_3x5_3(
        'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R',
                  'L', 'L', 'L', 'R', 'R', 'R'
    );

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Keymap 0: Alpha layer
     *
     * ,----------------------------------------.      ,-----------------------------------------.
     * |   F    |   D   |   L    |    B   |  V  |      |  J  |    G    |    O   |   U   |   ,    |
     * |--------+-------+--------+--------+-----|      |-----+---------+--------+-------+--------|
     * | GUI/S  | ALT/T | CTRL/R | SHFT/N |  K  |      |  Y  | SHIFT/M | CTRL/A | ALT/E | GUI/I  |
     * |--------+-------+--------+--------+-----|      |-----+---------+--------+-------+--------|
     * | SGUI/Z |   Q   |   X    |   H    |  P  |      |  W  |    C    |    '   |   ;   | SGUI/. |
     * `----------------------------------------'      `-----------------------------------------'
     *                         .-----------------.    .------------------.
     *                         | ESC | SPC | TAB |    | ENT | BSPC | DEL |
     *                         '-----------------'    '------------------'
     */
    [_BAS] = LAYOUT_split_3x5_3(
         KC_F,   KC_D,   KC_L,    KC_B,    KC_V,      KC_J,    KC_G,    KC_O,    KC_U,    KC_COMM,
         HOME_S, HOME_T, HOME_R,  HOME_N,  KC_K,      KC_Y,    HOME_M,  HOME_A,  HOME_E,  HOME_I,
         HOME_Z, KC_Q,   KC_X,    KC_H,    KC_P,      KC_W,    KC_C,    KC_QUOT, KC_SCLN, HOME_DT,
                         MED_ESC, NAV_SPC, MOU_TAB,   SYM_ENT, NUM_BSP, FUN_DEL),

    /* Keymap 1: Media layer
     *
     * ,-----------------------------.      ,---------------------------------.
     * | t   |  t  |  t   |  t   |   |      |   |      |       |       |      |
     * |-----+-----+------+------+---|      |---+------+-------+-------+------|
     * | GUI | ALT | CTRL | SHFT |   |      |   | Prev | Vol D | Vol U | Next |
     * |-----+-----+------+------+---|      |---+------+-------+-------+------|
     * |     |     |  t   |  t   |   |      |   |      |       |       |      |
     * `-----------------------------'      `---------------------------------'
     *                    .-----------.    .--------------------.
     *                    | x |   |   |    | Stop | Play | Mute |
     *                    '-----------'    '--------------------'
     */
    [_MED] = LAYOUT_split_3x5_3(
         KC_NO,   KC_NO,   KC_NO,   TG_TAP,  KC_NO,      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
         KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_NO,      KC_NO,   KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT,
         KC_NO,   KC_NO,   QK_LLCK, CW_TOGG, KC_NO,      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                           KC_NO,   KC_NO,   KC_NO,      KC_MSTP, KC_MPLY, KC_MUTE),

    /* Keymap 2: Navigation layer
     *
     * ,---------------------------.      ,----------------------------------------.
     * |  t  |  t  |  t  |  t  |   |      | Redo   | Paste | Copy   | Cut  | Undo  |
     * |-----+-----+-----+-----+---|      |--------+-------+--------+------+-------|
     * | GUI | ALT | CTL | SFT |   |      | Caps   | Left  | Down   | Up   | Right |
     * |-----+-----+-----+-----+---|      |--------+-------+--------+------+-------|
     * |     |     |  t  |  t  |   |      | Insert | Home  | PgDown | PgUp | End   |
     * `---------------------------'      `----------------------------------------'
     *                  .-----------.    .------------------.
     *                  |   | x |   |    | ENT | BSPC | DEL |
     *                  '-----------'    '------------------'
     */
    [_NAV] = LAYOUT_split_3x5_3(
         KC_NO,   KC_NO,   KC_NO,   TG_TAP,  KC_NO,      MAC_RDO, MAC_PST, MAC_CPY, MAC_CUT, MAC_UDO,
         KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_NO,      CW_TOGG, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,
         KC_NO,   KC_NO,   QK_LLCK, CW_TOGG, KC_NO,      KC_INS,  KC_HOME, KC_PGDN, KC_PGUP, KC_END,
                           KC_NO,   KC_NO,   KC_NO,      KC_ENT,  KC_BSPC, KC_DEL),

    /* Keymap 3: Mouse layer
     *
     * ,---------------------------.      ,-----------------------.
     * | t   | t   | t   | t   |   |      | t | t  | t  | t  | t  |
     * |-----+-----+-----+-----+---|      |---+----+----+----+----|
     * | GUI | ALT | CTL | SFT |   |      |   | L  | D  | U  | R  |
     * |-----+-----+-----+-----+---|      |---+----+----+----+----|
     * |     |     | t   | t   |   |      |   | WL | WD | WU | WR |
     * `---------------------------'      `-----------------------'
     *                  .-----------.    .-----------------.
     *                  |   |   | x |    | RMB | LMB | MMB |
     *                  '-----------'    '-----------------'
     */
    [_MOU] = LAYOUT_split_3x5_3(
         KC_NO,   KC_NO,   KC_NO,   TG_TAP,  KC_NO,      MAC_RDO, MAC_PST, MAC_CPY, MAC_CUT, MAC_UDO,
         KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_NO,      KC_NO,   MS_LEFT, MS_DOWN, MS_UP,   MS_RGHT,
         KC_NO,   KC_NO,   QK_LLCK, CW_TOGG, KC_NO,      KC_NO,   MS_WHLL, MS_WHLD, MS_WHLU, MS_WHLR,
                           KC_NO,   KC_NO,   KC_NO,      MS_BTN2, MS_BTN1, MS_BTN3),

    /* Keymap 4: Symbol layer
     *
     * ,-----------------------------.      ,---------------------------.
     * |  {  |  &  |  *  |  (  |  }  |      |   | t   | t   | t   | t   |
     * |-----+-----+-----+-----+-----|      |---+-----+-----+-----+-----|
     * |  ?  |  $  |  %  |  ^  |  +  |      |   | SFT | CTL | ALT | GUI |
     * |-----+-----+-----+-----+-----|      |---+-----+-----+-----+-----|
     * |  ~  |  !  |  @  |  #  |  |  |      |   | t   | t   |     |     |
     * `-----------------------------'      `---------------------------'
     *                    .-----------.    .-----------.
     *                    | ( | ) | _ |    | x |   |   |
     *                    '-----------'    '-----------'
     */
    [_SYM] = LAYOUT_split_3x5_3(
         KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR,      KC_NO, TG_TAP,  KC_NO,   KC_NO,   KC_NO,
         KC_QUES, KC_DLR,  KC_PERC, KC_CIRC, KC_PLUS,      KC_NO, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
         KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_PIPE,      KC_NO, QK_LLCK, CW_TOGG, KC_NO,   KC_NO,
                           KC_LPRN, KC_RPRN, KC_UNDS,      KC_NO, KC_NO,   KC_NO),

    /* Keymap 5: Number layer
     *
     * ,-----------------------------.      ,---------------------------.
     * |  [  |  7  |  8  |  9  |  ]  |      |   | t   | t   | t   | t   |
     * |-----+-----+-----+-----+-----|      |---+-----+-----+-----+-----|
     * |  /  |  4  |  5  |  6  |  =  |      |   | SFT | CTL | ALT | GUI |
     * |-----+-----+-----+-----+-----|      |---+-----+-----+-----+-----|
     * |  `  |  1  |  2  |  3  |  \  |      |   | t   | t   |     |     |
     * `-----------------------------'      `---------------------------'
     *                    .-----------.    .-----------.
     *                    | . | 0 | - |    |   | x |   |
     *                    '-----------'    '-----------'
     */
    [_NUM] = LAYOUT_split_3x5_3(
         KC_LBRC, KC_7, KC_8,   KC_9, KC_RBRC,      KC_NO, TG_TAP,  KC_NO,   KC_NO,   KC_NO,
         KC_SLSH, KC_4, KC_5,   KC_6, KC_EQL,       KC_NO, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
         KC_GRV,  KC_1, KC_2,   KC_3, KC_BSLS,      KC_NO, QK_LLCK, CW_TOGG, KC_NO,   KC_NO,
                        KC_DOT, KC_0, KC_MINS,      KC_NO, KC_NO,   KC_NO),


    /* Keymap 6: Function layer
     *
     * ,------------------------.      ,---------------------------.
     * | F12 | F7 | F8 | F9 |   |      |   | t   | t   | t   | t   |
     * |-----+----+----+----+---|      |---+-----+-----+-----+-----|
     * | F11 | F4 | F5 | F6 |   |      |   | SFT | CTL | ALT | GUI |
     * |-----+----+----+----+---|      |---+-----+-----+-----+-----|
     * | F10 | F1 | F2 | F3 |   |      |   | t   | t   |     |     |
     * `------------------------'      `---------------------------'
     *         .-----------------.    .-----------.
     *         | App | TAB | SPC |    |   |   | x |
     *         '-----------------'    '-----------'
     */
    [_FUN] = LAYOUT_split_3x5_3(
         KC_F12, KC_F7, KC_F8,   KC_F9,  KC_NO,       KC_NO, TG_TAP,  KC_NO,   KC_NO,   KC_NO,
         KC_F11, KC_F4, KC_F5,   KC_F6,  KC_NO,       KC_NO, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
         KC_F10, KC_F1, KC_F2,   KC_F3,  KC_NO,       KC_NO, QK_LLCK, CW_TOGG, KC_NO,   KC_NO,
                        RAYCAST, KC_TAB, KC_SPC,      KC_NO, KC_NO,   KC_NO),

    /* Keymap 7: Tap layer
     *
     * ,-----------------------------.      ,-----------------------------.
     * |  F  |  D  |  L  |  B  |  V  |      |  J  |  G  |  O  |  U  |  ,  |
     * |-----+-----+-----+-----+-----|      |-----+-----+-----+-----+-----|
     * |  S  |  T  |  R  |  N  |  K  |      |  Y  |  M  |  A  |  E  |  I  |
     * |-----+-----+-----+-----+-----|      |-----+-----+-----+-----+-----|
     * |  Z  |  Q  |  X  |  H  |  P  |      |  W  |  C  |  '  |  ;  |  .  |
     * `-----------------------------'      `-----------------------------'
     *              .-----------------.    .------------------.
     *              | ESC | TAB | SPC |    | ENT | BSPC | DEL |
     *              '-----------------'    '------------------'
     */
    [_TAP] = LAYOUT_split_3x5_3(
         KC_F, KC_D, KC_L,    KC_B,   KC_V,      KC_J,   KC_G,    KC_O,     KC_U,    KC_COMMA,
         KC_S, KC_T, KC_R,    KC_N,   KC_K,      KC_Y,   KC_M,    KC_A,     KC_E,    KC_I,
         KC_Z, KC_Q, KC_X,    KC_H,   KC_P,      KC_W,   KC_C,    KC_QUOTE, KC_SCLN, KC_DOT,
                     TG_BASE, KC_TAB, KC_SPC,    KC_ENT, KC_BSPC, KC_DEL),
};
