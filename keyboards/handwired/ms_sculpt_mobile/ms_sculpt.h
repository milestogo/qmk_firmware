#pragma once 
#include "quantum.h"

#define LAYOUT_mobile( \
                k7Q, k6O, k6P,  k6Q, k5O, k5P, k5Q, k7A, k7B, k7C, k7D, k7E, k7F, k1O, k1K, k1L, \
                k5A,  k5K,  k5L, k5M, k5N, k5H, k5I, k2A, k2B, k2C, k2D, k5B, k5C, k5J, k2E, \
                k6R,  k6D,  k6E, k6F, k7I, k7J, k4A, k4B, k4C, k4D, k3A, k3B, k3C, k3D, \
                k0J, k6A, k6B, k6C, k7H, k1A, k1B, k5D, k5E, k5F, k5G, k1C, k7P,   k2G, \
                k2P, k7K, k7L, k7M, k7O, k0A, k0B, k0C, k0D, k0E, k0F, k2L, k6G, k1P,\
                k1Q, k4N, k3O,k6N, k3K, k0R, k1M, k6H, k6I, k6J \
) \
{ \
        {k0A, k0B, k0C, k0D, k0E, k0F, KC_NO, KC_NO, KC_NO, k0J, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,KC_NO, KC_NO, k0R},\
        {k1A, k1B, k1C, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, k1K, k1L, k1M, KC_NO, k1O, k1P, k1Q, KC_NO},\
        {k2A, k2B, k2C, k2D, k2E, KC_NO, k2G, KC_NO, KC_NO, KC_NO, KC_NO, k2L, KC_NO, KC_NO, KC_NO, k2P, KC_NO, KC_NO},\
        {k3A, k3B, k3C, k3D, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, k3K, KC_NO, KC_NO, KC_NO, k3O, KC_NO, KC_NO, KC_NO},\
        {k4A, k4B, k4C, k4D, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, k4N, KC_NO,KC_NO, KC_NO, KC_NO},\
        {k5A, k5B, k5C, k5D, k5E, k5F, k5G, k5H, k5I, k5J, k5K, k5L, k5M, k5N, k5O, k5P, k5Q, KC_NO },\
        {k6A, k6B, k6C, k6D, k6E, k6F, k6G, k6H, k6I, k6J, KC_NO, KC_NO, KC_NO, k6N, k6O, k6P, k6Q, k6R},\
        {k7A, k7B, k7C, k7D, k7E, k7F, KC_NO, k7H, k7I, k7J, k7K, k7L, k7M, KC_NO, k7O, k7P, k7Q, KC_NO},\
}
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
    // GRV,  1,   2,   3,  4,   5,   6,   7,   8,   9,  0,  MINS, EQL, BSPC, HOME,
    // TAB,  Q,   W,   E,  R,   T,   Y,   U,   I,    O,  P,  LBRC,RBRC,BSLS,DEL,  END,
    // CAPS, A,   S,   D,   F,   G,   H,   J,    K,  L,  SCLN, QUOT,ENT, INS, PGUP,
    // LSFT, Z,   X,   C,   V,   B,   N,   M,  COMM, DOT,SLSH, RSFT, UP, PGDN,
    // LCTL, LGUI, LALT,LSPC,RSPC, RALT, RGUI,RCTL,LEFT,DOWN,RGHT
#define LAYOUT_ergonomic( \
        k4N,  k7M, k7L, k1L, k4L, k1K, k1P, k6J, k7H, k7F, k7I, k7D, k1D, k7B, k3B, k0B, k2D,\
        k7N,  k0N, k0M, k2N, k1N, k7K, k7P, k0J, k0H, k0F, k0E, k1F, k7E, k0I, k2B, \
        k0K,  k0L, k1M, k2L, k2K, k2P, k1J, k2J, k2H, k2F, k2E, k1E, k1H, k3I, k0D, k5B,\
        k2M,  k3N, k4M, k3L, k3K, k3K, k3J, k3J, k3H, k3F, k3E, k4F, k3D, k1I, k1B,\
        k4O,  k5N, k5M, k4L, k5K, k6K, k6J, k5J, k5H, k5F, k4E, k5C, k6D, k5D, \
        k6A,  k3P, k4Q, k6L, k6I, k4G,   k4D, k6R, k4I, k6E, k6B \
) \
{ \
        {KC_NO, k0B, KC_NO, k0D, k0E, k0F, KC_NO, k0H, k0I, k0J, k0K, k0L, k0M, k0N, KC_NO, KC_NO, KC_NO, KC_NO},\
        {KC_NO, k1B, KC_NO, k1D, k1E, k1F, KC_NO, k1H, k1I, k1J, k1K, k1L, k1M, k1N, KC_NO, k1P, KC_NO, KC_NO},\
        {KC_NO, k2B, KC_NO, k2D, k2E, k2F, KC_NO, k2H, KC_NO, k2J, k2K, k2L, k2M, k2N, KC_NO, k2P, KC_NO, KC_NO},\
        {KC_NO, k3B, KC_NO, k3D, k3E, k3F, KC_NO, k3H, k3I, k3J, k3K, k3L, k3M, k3N, KC_NO, k3P, KC_NO, KC_NO},\
        {KC_NO, KC_NO, KC_NO, k4D, k4E, k4F, k4G, KC_NO, k4I, k4J, k4K, k4L, k4M, k4N, KC_NO, KC_NO, k4Q, KC_NO},\
        {KC_NO, k5B, k5C, k5D, k5E, k5F, KC_NO, k5H, KC_NO, k5J, k5K, k5L, k5M, k5N, k5O, KC_NO, KC_NO, KC_NO},\
        {k6A, k6B, KC_NO, k6D, k6E, KC_NO, KC_NO, KC_NO, k6I, k6J, k6K, k6L, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, k6R},\
        {KC_NO, k7B, KC_NO, k7D, k7E, k7F, KC_NO, k7H, k7I, k7J, k7K, k7L, k7M, k7N, KC_NO, k7P, KC_NO, KC_NO},\
}


