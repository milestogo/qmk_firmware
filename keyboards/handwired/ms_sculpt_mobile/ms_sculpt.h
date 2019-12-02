#pragma once 
#include "quantum.h"
 
#define XXX KC_NO
#define NNN KC_NO

/* sculpt ergonomic desktop. 
  [0] = (\
    KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,       KC_PSCR, KC_SLCK, KC_PAUS, KC_CALC,
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,               KC_HOME,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,      KC_DEL,  KC_END,
    KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,       KC_INS,  KC_PGUP,
    KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT,      KC_UP,   KC_PGDN,
    KC_LCTL, KC_LGUI, KC_LALT,                   KC_SPC,  KC_SPC,                             KC_RALT, KC_RGUI,          KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
  )
};
*/

// huge thanks to https://github.com/blttll/tmk_keyboard/tree/master/keyboard/sculpt
// us layout below, nuhs(5E) and nubs (3M)not defined. 

#define LAYOUT_ergonomic( \
        k4N,  k7M, k7L, k1L, k4L, k1K, k1P, k7J, k7H, k7F, k7I, k7D, k1D, k7B, k3B, k0B, k2D,\
        k7N,  k0N, k0M, k2N, k1N, k7K, k7P, k0J, k0H, k0F, k0E, k1F, k7E, k0I, k2B, \
        k0K,  k0L, k1M, k2L, k2K, k2P, k1J, k2J, k2H, k2F, k2E, k1E, k1H, k3I, k0D, k5B,\
        k2M,  k3N, k4M, k3L, k3K, k4K, k4J, k3J, k3H, k3F, k3E, k4F, k3D, k1I, k1B,\
        k4O,  k5N, k5M, k5L, k5K, k6K, k6J, k5J, k5H, k5F, k4E, k5C, k6D, k5D, \
        k6A,  k3P, k4Q, k6L, k6I, k4G,   k4D, k6R, k4I, k6E, k6B \
) \
{ \
        {XXX, k0B, XXX, k0D, k0E, k0F, XXX, k0H, k0I, k0J, k0K, k0L, k0M, k0N, XXX, XXX, XXX, XXX},\
        {XXX, k1B, XXX, k1D, k1E, k1F, XXX, k1H, k1I, k1J, k1K, k1L, k1M, k1N, XXX, k1P, XXX, XXX},\
        {XXX, k2B, XXX, k2D, k2E, k2F, XXX, k2H, XXX, k2J, k2K, k2L, k2M, k2N, XXX, k2P, XXX, XXX},\
        {XXX, k3B, XXX, k3D, k3E, k3F, XXX, k3H, k3I, k3J, k3K, k3L, k3M, k3N, XXX, k3P, XXX, XXX},\
        {XXX, XXX, XXX, k4D, k4E, k4F, k4G, XXX, k4I, k4J, k4K, k4L, k4M, k4N, XXX, XXX, k4Q, XXX},\
        {XXX, k5B, k5C, k5D, k5E, k5F, XXX, k5H, XXX, k5J, k5K, k5L, k5M, k5N, k5O, XXX, XXX, XXX},\
        {k6A, k6B, XXX, k6D, k6E, XXX, XXX, XXX, k6I, k6J, k6K, k6L, XXX, XXX, XXX, XXX, XXX, k6R},\
        {XXX, k7B, XXX, k7D, k7E, k7F, XXX, k7H, k7I, k7J, k7K, k7L, k7M, k7N, XXX, k7P, XXX, XXX},\
}


