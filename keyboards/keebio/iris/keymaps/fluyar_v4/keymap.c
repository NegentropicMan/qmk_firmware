#include QMK_KEYBOARD_H
#include "keymap_german.h"

#define _ALNUM 0
#define _SHIFTMOD 1
#define _ALTGRMOD 2
#define _ALTGRSHIFTMOD 3
#define _FNMOD 4

//Tap Dance Declarations
enum {
  TD_ALT_ALTGR = 0
};

	// [_ALTGRMOD] = LAYOUT(
    //     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    //     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    //     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    //     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    //                                 KC_NO, KC_NO, KC_NO,     KC_NO, KC_NO, KC_NO
    //     ),

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_ALNUM] = LAYOUT(
        KC_ESC,        DE_1, DE_2, DE_3, DE_4, DE_5,                        DE_6, DE_7, DE_8,    DE_9,   DE_0,    KC_BSPC,
        KC_TAB,        DE_Q, DE_W, DE_E, DE_R, DE_T,                        DE_Z, DE_U, DE_I,    DE_O,   DE_P,    DE_SLSH,
        KC_LGUI,       DE_A, DE_S, DE_D, DE_F, DE_G,                        DE_H, DE_J, DE_K,    DE_L,   DE_HASH, DE_CIRC,
        MO(_SHIFTMOD), DE_Y, DE_X, DE_C, DE_V, DE_B, KC_MUTE,      KC_MPLY, DE_N, DE_M, DE_COMM, DE_DOT, DE_MINS, MO(_SHIFTMOD),
                                   KC_LALT, KC_LCTRL, KC_SPC,   KC_ENT, MO(_ALTGRMOD), TT(_FNMOD)
        ),
	[_SHIFTMOD] = LAYOUT(
        KC_NO,         DE_EXLM, DE_DQUO, DE_SECT, DE_DLR, DE_PERC,                        DE_AMPR, DE_SLSH, DE_LPRN,    DE_RPRN,   DE_EQL,    KC_NO,
        S(KC_TAB),        S(DE_Q), S(DE_W), S(DE_E), S(DE_R), S(DE_T),                        S(DE_Z), S(DE_U), S(DE_I),    S(DE_O),   S(DE_P),    DE_TILD,
        KC_NO,      S(DE_A), S(DE_S), S(DE_D), S(DE_F), S(DE_G),                        S(DE_H), S(DE_J), S(DE_K),    S(DE_L),   DE_HASH, DE_CIRC,
        KC_TRNS, S(DE_Y), S(DE_X), S(DE_C), S(DE_V), S(DE_B), KC_MUTE,      KC_MPLY, S(DE_N), S(DE_M), DE_SCLN, DE_COLN, DE_UNDS, KC_TRNS,
                                   KC_LALT, KC_LCTRL, S(KC_SPC),   S(KC_ENT), MO(_ALTGRMOD), KC_NO
        ),
	[_ALTGRMOD] = LAYOUT(
        KC_NO, KC_NO,   DE_SUP2, DE_SUP3, KC_NO,  KC_NO,                      KC_NO,   DE_LCBR, DE_LBRC, DE_RBRC, DE_RCBR, KC_DEL,
        KC_NO, DE_AT,   KC_NO,   DE_EURO, KC_NO,  KC_NO,                      KC_NO,   DE_UDIA, KC_NO,   DE_ODIA, KC_NO,   DE_BSLS,
        KC_NO, DE_ADIA, DE_SS,   KC_NO,   KC_NO,  KC_NO,                      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   DE_ACUT,
        MO(_SHIFTMOD), KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO,    KC_NO,     KC_NO, KC_NO,   DE_MICR, KC_NO,   KC_NO,   DE_PLUS, MO(_SHIFTMOD),
                                          KC_LALT, KC_LCTRL, KC_NO,     KC_NO, KC_TRNS, KC_NO
        ),
    [_ALTGRSHIFTMOD] = LAYOUT(
        KC_NO,   KC_NO,      KC_NO, KC_NO, KC_NO,  KC_NO,                     KC_NO,   KC_NO,      DE_LABK, DE_RABK,    DE_QUES, KC_INS,
        KC_NO,   KC_NO,      KC_NO, KC_NO, KC_NO,  KC_NO,                     KC_NO,   S(DE_UDIA), KC_NO,   S(DE_ODIA), KC_NO,   DE_PIPE,
        KC_NO,   S(DE_ADIA), KC_NO, KC_NO, KC_NO,  KC_NO,                     KC_NO,   KC_NO,      KC_NO,   KC_NO,      KC_NO,   DE_GRV,
        KC_TRNS, KC_NO,      KC_NO, KC_NO, KC_NO,  KC_NO,    KC_NO,    KC_NO, KC_NO,   DE_MICR,    KC_NO,   KC_NO,      DE_ASTR, KC_TRNS,
                                           KC_LALT, KC_LCTRL, KC_NO,    KC_NO, KC_TRNS, KC_NO
        ),
    [_FNMOD] = LAYOUT(
        KC_NO,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                      KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10, KC_NO,
        KC_NO,   KC_F11,  KC_F12,  KC_NO, KC_NO, KC_NO,                    KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_PSCR,  KC_SLCK,
        KC_LGUI, RGB_HUI, RGB_SAI, RGB_VAI, KC_NO, RGB_MOD,                    KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_UP,  KC_PAUS,
        KC_LSFT, RGB_HUD, RGB_SAD, RGB_VAD, KC_NO,   RGB_TOG, KC_NO,      KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_LEFT,   KC_DOWN,  KC_RGHT,
                                           KC_LALT, KC_LCTRL, KC_SPC,     KC_ENT, KC_NO, KC_TRNS
        ),
};

// Encode definitions.
// Left encoder: Volume up/down
// Right encoder Prev/Next title
void encoder_update_user(uint8_t index, bool clockwise) {
  if (index == 0) { /* First encoder */
    // Apparently, clockwise is anti-clockwise
    if (!clockwise) {
      tap_code(KC_VOLU);
    } else {
      tap_code(KC_VOLD);
    }
  } else if (index == 1) { /* Second encoder */
    if (!clockwise) {
      tap_code(KC_MNXT);
    } else {
      tap_code(KC_MPRV);
    }
  }
}

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap once for Esc, twice for Caps Lock
  [TD_ALT_ALTGR]  = ACTION_TAP_DANCE_DOUBLE(KC_LALT, KC_RALT)
// Other declarations would go here, separated by commas, if you have them
};

// Make _ALTGRMOD and SHIFTMOD a trilayer (switch to ALTGRSHIFTMOD if both are active)
layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _SHIFTMOD, _ALTGRMOD, _ALTGRSHIFTMOD);
}

// Combos for umlauts
enum combos {
  AE_AE,
  OE_OE,
  UE_UE,
  SZ_SZ
};

const uint16_t PROGMEM ae_combo[] = {KC_A, KC_E, COMBO_END};
const uint16_t PROGMEM oe_combo[] = {KC_O, KC_E, COMBO_END};
const uint16_t PROGMEM ue_combo[] = {KC_U, KC_E, COMBO_END};
const uint16_t PROGMEM sz_combo[] = {KC_S, KC_Z, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [AE_AE] = COMBO(ae_combo, DE_ADIA),
  [OE_OE] = COMBO(oe_combo, DE_ODIA),
  [UE_UE] = COMBO(ue_combo, DE_UDIA),
  [SZ_SZ] = COMBO(sz_combo, DE_SS)
};
