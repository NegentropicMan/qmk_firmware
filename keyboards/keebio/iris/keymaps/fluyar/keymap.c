#include QMK_KEYBOARD_H

#define _ALNUM 0
#define _ALTGR 1
#define _FUNCTIONS 2

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_ALNUM] = LAYOUT(
        KC_TAB,        KC_1, KC_2, KC_3, KC_4, KC_5,                        KC_6, KC_7, KC_8,    KC_9,   KC_0,    KC_MINS,
        KC_ESC,        KC_Q, KC_W, KC_E, KC_R, KC_T,                        KC_Y, KC_U, KC_I,    KC_O,   KC_P,    KC_LBRC,
        KC_LCTL,       KC_A, KC_S, KC_D, KC_F, KC_G,                        KC_H, KC_J, KC_K,    KC_L,   KC_SCLN, KC_QUOT,
        OSM(MOD_LSFT), KC_Z, KC_X, KC_C, KC_V, KC_B, KC_MUTE,      KC_MPLY, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, OSM(MOD_RSFT),
                                   KC_LGUI, KC_LALT, TT(_ALTGR),   KC_SPC, TT(_FUNCTIONS), KC_BSPC
        ),
	[_ALTGR] = LAYOUT(
        RESET,   RALT(KC_1), RALT(KC_2), RALT(KC_3), RALT(KC_4), RALT(KC_5),                    RALT(KC_6), RALT(KC_7),    RALT(KC_8), RALT(KC_9), RALT(KC_0), RALT(KC_MINS),
        KC_NO,   RALT(KC_Q), KC_NO,      KC_NO,      KC_NUBS,    LSFT(KC_8),                    LSFT(KC_9), LSFT(KC_NUBS), KC_NO,      KC_NO,      KC_NO,      RALT(KC_RBRC),
        KC_LCTL, KC_NO,      KC_NO,      KC_NO,      KC_NO,      RALT(KC_8),                    RALT(KC_9), KC_RBRC,       KC_BSLS,    KC_EQL,     KC_NUBS,    RALT(KC_NUBS),
        KC_LSFT, KC_NO,      KC_NO,      KC_NO,      KC_NO,      RALT(KC_7), KC_NO,      KC_NO, RALT(KC_0), KC_NO,         KC_NO,      KC_NO,      KC_NO,      KC_RSFT,
                                                           KC_NO, KC_LALT, KC_TRNS,      KC_ENT, KC_RALT, KC_RCTL
        ),
	[_FUNCTIONS] = LAYOUT(
        KC_NO,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                      KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10, RGB_TOG,
        KC_NO,   KC_F11,  KC_F12,  KC_MPRV, KC_MPLY, KC_MNXT,                    KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_NO,  KC_INS,
        KC_LCTL, RGB_HUI, RGB_SAI, RGB_VAI, KC_MUTE, KC_VOLU,                    KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_NO,  KC_NO,
        KC_LSFT, RGB_HUD, RGB_SAD, RGB_VAD, KC_NO,   KC_VOLD, KC_NO,      KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_RSFT,
                                           KC_NO,   KC_LALT, KC_LGUI,     KC_NO, KC_TRNS, KC_DEL
        )
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
