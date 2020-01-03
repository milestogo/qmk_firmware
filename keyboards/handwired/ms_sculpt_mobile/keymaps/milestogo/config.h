#pragma once

// depends on the FFC connectors used. 
//#define FLIP_ROW_PINS

// if the leds are RGB define, else assume GRB
#undef RGB

// Expect to get errors if you comment a feature out and leave it in your keymap.
#define USE_BABLPASTE


#define RGBLED_NUM 3
#define RGBLIGHT_LIMIT_VAL 100

#ifdef RGBLIGHT_ENABLE
#define LAYER_LED 0
#define STATUS_LED 1
#define BABL_LED_INDEX 2 // set to 0 to set all LEDs , or set to # of LED to be used as BABL updaters
#endif

#ifdef USE_BABLPASTE

#ifdef RGBLIGHT_ENABLE

#ifdef RGB 

#define RGBLIGHT_COLOR_MS 0x00,0x27,0x88 // blue screen?
#define RGBLIGHT_COLOR_MAC 0x30,0x30,0x30 // grey
#define RGBLIGHT_COLOR_LINUX 0xF4,0xAA,0x90 // ubuntu orange?
#define RGBLIGHT_COLOR_EMACS 0x00,0x00,0x00
#define RGBLIGHT_COLOR_VI 0x00,0x90,0x00
#define RGBLIGHT_COLOR_READMUX 0x33,0xFF,0x33 // green screen
#define RGBLIGHT_COLOR_CHROMEOS 0xf4,0xc2,0xd // google yellows

#else // GRB 

#define RGBLIGHT_COLOR_MS 0x00,0x27,0x88 // blue screen?
#define RGBLIGHT_COLOR_MAC 0x10,0x10,0x10 // grey
#define RGBLIGHT_COLOR_LINUX 0x8A,0xCA,0x60 // ubuntu orange?
#define RGBLIGHT_COLOR_EMACS 0x00,0x00,0x00
#define RGBLIGHT_COLOR_VI 0x00,0x90,0x00
#define RGBLIGHT_COLOR_READMUX 0xC0,0x00,0x13 // green screen
#define RGBLIGHT_COLOR_CHROMEOS 0xf4,0xd,0xc2 // google yellows

#endif // rgb
#endif // rgblight enable

#endif // bablpaste



// place overrides here

#ifdef RGBLIGHT_ENABLE

#ifdef RGB
#define RGBLIGHT_COLOR_LAYER_0 0x00, 0x50, 0x00 // qwerty
#define RGBLIGHT_COLOR_LAYER_1 0x00, 0x99, 0x99 // cdh
#define RGBLIGHT_COLOR_LAYER_2 0xFF, 0x00, 0x00  // symbol
#define RGBLIGHT_COLOR_LAYER_3 0x00, 0xFF, 0xFF  // move
#define RGBLIGHT_COLOR_LAYER_4 0xFF, 0x00, 0xFF  // delmove
#define RGBLIGHT_COLOR_LAYER_5 0x00, 0xFF, 0xFF 
#else // GRB
#define RGBLIGHT_COLOR_LAYER_0 0x30, 0x00, 0x00 // qwerty
#define RGBLIGHT_COLOR_LAYER_1 0x50, 0x00, 0x50 // cdh
#define RGBLIGHT_COLOR_LAYER_2 0x90, 0x00, 0x90  // symbol
#define RGBLIGHT_COLOR_LAYER_3 0x00, 0x50, 0x50  // move
#define RGBLIGHT_COLOR_LAYER_4 0x00, 0x90, 0x00  // delmove
#define RGBLIGHT_COLOR_LAYER_5 0xFF, 0x00, 0xFF 
#endif 

#define RGBLIGHT_ANIMATIONS
#define RGB_LIGHT_EFFECT_BREATHE_MAX 200
#define RGBLIGHT_RAINBOW_SWIRL_RANGE 127
#endif // rgblight

#define TAPPING_TERM 200
#define TAPPING_TERM_PER_KEY
#define RETRO_TAPPING
//#define PERMISSIVE_HOLD
