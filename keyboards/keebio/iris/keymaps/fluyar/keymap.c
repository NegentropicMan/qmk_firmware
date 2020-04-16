#include QMK_KEYBOARD_H
#include "keymap_german.h"

#define _ALNUM 0
#define _ALTGRMOD 1
#define _FNMOD 2


	// [_ALTGRMOD] = LAYOUT(
    //     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    //     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    //     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    //     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    //                                 KC_NO, KC_NO, KC_NO,     KC_NO, KC_NO, KC_NO
    //     ),

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_ALNUM] = LAYOUT(
        KC_ESC,        DE_1, DE_2, DE_3, DE_4, DE_5,                        DE_6, DE_7, DE_8,    DE_9,   DE_0,    KC_INS,
        KC_TAB,        DE_Q, DE_W, DE_E, DE_R, DE_T,                        DE_Z, DE_U, DE_I,    DE_O,   DE_P,    DE_PLUS,
        KC_LGUI,       DE_A, DE_S, DE_D, DE_F, DE_G,                        DE_H, DE_J, DE_K,    DE_L,   DE_LABK, DE_CIRC,
        OSM(MOD_LSFT), DE_Y, DE_X, DE_C, DE_V, DE_B, KC_MUTE,      KC_MPLY, DE_N, DE_M, DE_COMM, DE_DOT, DE_MINS, OSM(MOD_RSFT),
                                   KC_LALT, KC_LCTRL, MO(_FNMOD),      KC_SPC, MO(_ALTGRMOD), KC_BSPC
        ),
	[_ALTGRMOD] = LAYOUT(
        KC_NO,   S(DE_SS),      ALGR(DE_2), ALGR(DE_3), KC_NO,   KC_NO,                     KC_NO,   ALGR(DE_7), ALGR(DE_8), ALGR(DE_9), ALGR(DE_0),    KC_DEL,
        KC_NO,   ALGR(DE_Q), KC_NO,      ALGR(DE_E), KC_NO,   KC_NO,                     KC_NO,   DE_UDIA,    KC_NO,      DE_ODIA,    KC_NO,         ALGR(DE_PLUS),
        KC_NO,   DE_ADIA,    DE_SS,      KC_NO,      KC_NO,   KC_NO,                     KC_NO,   KC_NO,      KC_NO,      KC_NO,      ALGR(DE_LABK), DE_ACUT,
        KC_TRNS, KC_NO,      KC_NO,      KC_NO,      KC_NO,   KC_NO,   KC_NO,     KC_NO, KC_NO,   ALGR(DE_M),    KC_NO,      ALGR(DE_SS),      DE_HASH,       KC_TRNS,
                                                     KC_TRNS, KC_TRNS, KC_NO,     KC_NO, KC_TRNS, KC_DEL
        ),
  [_FNMOD] = LAYOUT(
        KC_NO,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                      KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10, KC_INS,
        KC_NO,   KC_F11,  KC_F12,  KC_NO, KC_NO, KC_NO,                    KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_PSCR,  KC_SLCK,
        KC_LGUI, RGB_HUI, RGB_SAI, RGB_VAI, KC_NO, RGB_MOD,                    KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_UP,  KC_PAUS,
        KC_LSFT, RGB_HUD, RGB_SAD, RGB_VAD, KC_NO,   RGB_TOG, KC_NO,      KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_LEFT,   KC_DOWN,  KC_RGHT,
                                           KC_LALT, KC_LCTRL, KC_TRNS,     KC_ENT, KC_NO, KC_DEL
        ),
};

// Encode definitions.
// Left encoder: Volume up/down
// Right encoder Prev/Next title
void encoder_update_user(uint8_t index, bool clockwise) {
  if (index == 0) { /* First encoder */
    if (clockwise) {
      tap_code(KC_VOLU);
    } else {
      tap_code(KC_VOLD);
    }
  } else if (index == 1) { /* Second encoder */
    if (clockwise) {
      tap_code(KC_MNXT);
    } else {
      tap_code(KC_MPRV);
    }
  }
}


// // Make _ALTGRMOD and SHIFTMOD a trilayer (switch to ALTGRSHIFTMOD if both are active)
// layer_state_t layer_state_set_user(layer_state_t state) {
//   return update_tri_layer_state(state, _SHIFTMOD, _ALTGRMOD, _ALTGRSHIFTMOD);
// }

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

// RGB on layer change
layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
    case _ALTGRMOD:
        rgblight_setrgb (0x00,  0x00, 0xFF);
        break;
    case _FNMOD:
        rgblight_setrgb (0xFF,  0x00, 0x00);
        break;
    default: //  for any other layers, or the default layer
        rgblight_setrgb (0x00,  0x00, 0x00);
        break;
    }
  return state;
}
