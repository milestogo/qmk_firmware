#include QMK_KEYBOARD_H

#ifdef BOARD_GENERIC_STM32_F103
#include "8x18_arm.h"
#endif

#ifdef RAW_ENABLE
#include "raw_hid.h"
#endif

#include "virtser.h"

#include <print.h>
#define _QWR 0
#define _CDH 1
#define _SYM 2
#define _MOV 3
#define _TRAN 5


#define LAYOUT_local LAYOUT_mobile_XUW

enum layer_keycodes {
QWR,
CDH,
SYM,
MOV,
NUM,
TRAN
};


// Shorter spacing
#define XXXX  KC_NO
#define ____  KC_TRNS

// Custom macros

/* Fn Keys */
#define TT_SYM MO(_SYM)
#define TT_MOV KC_FN2
#define TT_NUM MO(_NUM)
#define SSFT ACTION_MODS_ONESHOT(MOD_LSFT)
#define SSYM LT(_SYM, KC_SPC)
#define MVTAB LT(_MOV,KC_TAB)
#define BKSYM LT(_SYM, KC_BSPC)

enum macro_keycodes {
DHPASTE=1,
VIBRK,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*  QWERTY
*
* |ESC | F1 | F2 | F3 | F4 | F5 | F6 | f7 | F8 | F9 | F10| F11| F12|Vol-|Vol+|_CDH|
*  -------------------------------------------------------------------------------'
* | ESC |  1 |  2 |  3 |  4 |  5 |  6 |  7 |  8 |  9 |  0 |  - |  = |Bakspace| Del|
* ---------------------------------------------------------------------------
* | tab  |  q |  w |  e |  r |  t |  y |  u |  i |  o |  p |  [ |  ] |  \    |    |
*  -------------------------------------------------------------------------------'
* |Bak/Mov|  a |  s |  d |  f |  g |  h |  j |  k |  l |  ; |  ' | enter     |PgUp|
* --------------------------------------------------------------------------------
* |Lsft    |  z |  x |  c |  v |  b |  n |  m |  , |  . |  / |      Rsft| Up| PgDn|
* ---------------------------------------------------------------------------------
* |Lctl   |Lgui  |Lalt |       Space/Sym      | GUI |  Sym |  Rctl |Left|Down|Rght|
* ---------------------------------------------------------------------------------
*/

[_QWR] = LAYOUT_local( \
   KC_ESC,   KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8,   KC_F9, KC_F10,    KC_F11,   KC_F12, KC_VOLD, KC_VOLU, TG(CDH),\
   KC_ESC,   KC_1, KC_2, KC_3 ,KC_4, KC_5, KC_6, KC_7, KC_8,   KC_9, KC_0,    KC_MINUS, KC_EQL, KC_BSPC, KC_DEL,\
   MVTAB,   KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I,   KC_O, KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,\
   BKSYM,  KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K,   KC_L, KC_SCLN, KC_QUOT,  KC_ENT, KC_PGUP,\
   KC_LSFT,  KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM,KC_DOT,KC_SLSH,KC_RSFT,  KC_UP,  KC_PGDN,\
   KC_LCTL,  KC_LGUI, KC_LALT, KC_SPC, KC_RGUI, TT_SYM,  KC_CAPS, KC_LEFT, KC_DOWN, KC_RIGHT
),


[_CDH] = LAYOUT_local(\
   ____,     ____, ____, ____, ____, ____, ____, ____, ____,   ____, ____,    ____,     ____,   ____,    ____,    ____,  \
   KC_ESC,     ____, ____, ____, ____, ____, ____, ____, ____,   ____, ____,    ____,     ____,   ____,    ____,   \
   ____,  KC_Q, KC_W, KC_F, KC_P, KC_B, KC_J, KC_L, KC_U,    KC_Y,   KC_SCLN, ____,    ____,   ____,\
   TT_MOV,  KC_A, KC_R, KC_S, KC_T, KC_G, KC_M, KC_N, KC_E,    KC_I,   KC_O,    KC_QUOT, KC_ENT, KC_2,\
   KC_LSFT, KC_Z, KC_X, KC_C, M(DHPASTE), KC_V, KC_K, KC_H, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, ____,   KC_1,\
  ____,     ____, ____ , KC_FN1, ____, ____, ____, ____, ____,   ____

),

/*  SYM
*
* |ESC | F1 | F2 | F3 | F4 | F5 | F6 | f7 | F8 | F9 | F10| F11| F12|Vol-|Vol+|_CDH|
*  -------------------------------------------------------------------------------'
* | ESC |  1 |  2 |  3 |  4 |  5 |  6 |  7 |  8 |  9 |  0 |  - |  = |Bakspace|Del |
*  --------------------------------------------------------------------------
* | ESC: | ^  |  { |  } |  @ |  % |    |   [ | ( | )  | _  |  [ |  ] |  \    |    |
*  -------------------------------------------------------------------------------'
* |Bak/Mov|  ! |  # |  0 | =  |  { |   } | -  | 1 |  + |  ] |  ` | enter     |PgUp|
* --------------------------------------------------------------------------------
* |Lsft    |  ; | ~ |  : | ~  | "|"|  $ | *   |    |  .  |  / |      Rsft| Up| PgDn|
* ---------------------------------------------------------------------------------
* |Lctl   |Lgui  |Lalt |       Space/Sym      | GUI |  Sym |  Rctl |Left|Down|Rght|
* ---------------------------------------------------------------------------------
*/

[_SYM] = LAYOUT_local(\
  ____,     ____, ____, ____, ____, ____, ____, ____, ____,   ____, ____,    ____,     ____,   ____,    ____,     ____,  \
  ____,     ____, ____, ____, ____, ____, ____, ____, ____,   ____, ____,    ____,     ____,   ____,    ____,   \
  ____,  KC_CIRC, KC_LCBR, KC_RCBR,KC_AT, KC_PERC,         ____,   KC_LBRC,KC_LPRN,KC_RPRN,KC_UNDS,   ____,   ____,   ____,\
  ____,    KC_EXLM, KC_HASH,  KC_0,  KC_EQL, KC_LCBR,            KC_RCBR,KC_MINS,KC_1,  KC_PLUS,KC_RBRC,  KC_GRV,   ____,  ____,\
  ____,    KC_SCLN, KC_TILDE,  KC_COLN,  KC_TILDE,  KC_PIPE,     KC_DLR, KC_ASTR, ____,  KC_DOT ,   KC_SLSH,     ____, ____, ____,\
  ____,     ____, ____, ____, ____, ____, ____, ____, ____,   ____
),
/* MOVE simple version

* |ESC | MAC| Win|RdLn| VI |    |    |    |    |    |    |    |    |    |    |    |
*  -------------------------------------------------------------------------------'
* |     |    |  2 |  3 |  4 |  5 |  6 |  7 |  8 |  9 |  0 |  - |  = |Bakspace| Del|
* ---------------------------------------------------------------------------
* | tab  |    |    |Find|    |pTab |DSOL|DelW| Up |DelW|DEOL|  [ |  ] |  \    |    |
*  -------------------------------------------------------------------------------'
* |Bak/Mov|    |    |    |    |nTab |GSOL| <- | Dwn | -> | EOL |  ' | enter   |PgUp|
* --------------------------------------------------------------------------------
* |Lsft    |Undo| Cut|Copy|Pste|    |    |    |    |    |  / |      Rsft| Up| PgDn|
* ---------------------------------------------------------------------------------
* |Lctl   |Lgui  |Lalt |       Space/Sym      | GUI |  Sym |  Rctl |Left|Down|Rght|
* ---------------------------------------------------------------------------------
*/

[_MOV] = LAYOUT_local(\
  ____,     ____, ____, ____, ____, ____, ____, ____, ____,   ____, ____,    ____,     ____,   ____,    ____,     ____,  \
  ____,     ____, ____, ____, ____, ____,      ____, ____, ____, ____, ____,    ____, ____,   ____, ____,   \
  ____,     ____, ____, ____, ____, ____,      ____, ____, KC_UP, ____, ____,    ____, ____,   ____, \
  ____,     ____, ____, ____, ____, ____,      ____,  KC_LEFT, KC_DOWN, KC_RIGHT,  ____,    ____, ____,   ____, \
  ____,     ____, ____, ____, ____, ____,      ____, ____, ____, ____, ____,    ____, ____,   ____, \
  ____,     ____, ____, ____, ____, ____,      ____, ____, ____, ____

)

/* MOVE babble version version

* |ESC | MAC| Win|RdLn| VI |    |    |    |    |    |    |    |    |    |    |    |
*  -------------------------------------------------------------------------------'
* |     |    |  2 |  3 |  4 |  5 |  6 |  7 |  8 |  9 |  0 |  - |  = |Bakspace| Del|
* ---------------------------------------------------------------------------
* | tab  |    |    |Find|    |pTab |DSOL|DelW| Up |DelW|DEOL|  [ |  ] |  \    |    |
*  -------------------------------------------------------------------------------'
* |Bak/Mov|    |    |    |    |nTab |GSOL| <- | Dwn | -> | EOL |  ' | enter   |PgUp|
* --------------------------------------------------------------------------------
* |Lsft    |Undo| Cut|Copy|Pste|    |    |    |    |    |  / |      Rsft| Up| PgDn|
* ---------------------------------------------------------------------------------
* |Lctl   |Lgui  |Lalt |       Space/Sym      | GUI |  Sym |  Rctl |Left|Down|Rght|
* ---------------------------------------------------------------------------------
*/
/*

[_MOV] = LAYOUT_local(\
  ____,    B_MAC,B_WIN,B_READ, B_VI, ____, ____, ____, ____,   ____, ____,    ____,     ____,   ____,    ____,     ____,  \
  ____,      ____, B_PAPP, B_NAPP, ____, ____,      ____, ____, ____,   ____, ____,    ____,     ____,   ____,    ____,   \
  ____,     B_UNDO, ____, B_BFND, ____, B_PTAB,     B_DSOL, B_DLW, B_UP,   B_DRW, B_DEOL,  ____,  ____,   ____, \
  ____,     B_SELA, B_BRLD, ____, ____, B_NXTB,     B_GSOL, B_L1C, B_DOWN, B_R1C,B_GEOL,   ____, ____, ____,\
  ____,     B_UNDO,B_CUT, B_COPY, B_PAST, B_PAST,    ____, ____, ____, ____, ____,       ____,  ____,   ____, \
  ____,     ____, ____, ____, ____, ____, ____, ____, ____,   ____
),


[_TRAN] = LAYOUT_local(\
  ____,     ____, ____, ____, ____, ____, ____, ____, ____,   ____, ____,    ____,     ____,   ____,    ____,     ____,  \
  ____,     ____, ____, ____, ____, ____,      ____, ____, ____, ____, ____,    ____, ____,   ____, ____,   \
  ____,     ____, ____, ____, ____, ____,      ____, ____, ____, ____, ____,    ____, ____,   ____, \
  ____,     ____, ____, ____, ____, ____,      ____, ____, ____, ____, ____,    ____, ____,   ____, \
  ____,     ____, ____, ____, ____, ____,      ____, ____, ____, ____, ____,    ____, ____,   ____, \
  ____,     ____, ____, ____, ____, ____,      ____, ____, ____, ____
)
*/
};

const uint16_t PROGMEM fn_actions[] = {
[1] = ACTION_LAYER_TAP_KEY(_SYM,KC_SPACE),
[2] = ACTION_LAYER_TAP_KEY(_MOV,KC_BSPC)
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  switch (keycode) {
    case QWR:
      if (record->event.pressed) {
        layer_off(_CDH);
      }
      return false;
      break;

    case CDH:
      if (record->event.pressed) {
        layer_on(_CDH);
      }
      return false;
      break;

    case SYM:
      if (record->event.pressed) {
        layer_on(_SYM);
      } else {
		    layer_off(_SYM);
      }
     return false;
     break;

   }
 return true;

}

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{

/* Any clever remapping with modifiers should happen here e.g. shift bablkey does opposite*/
#ifdef USE_BABLPASTE

   if( id >= BABL_START_NUM && id < (BABL_START_NUM + BABL_NUM_MACROS ) ) {
   		if (record->event.pressed)  { // is there a case where this isn't desired?

   			babblePaste ( record,  id );
   			return MACRO_NONE;
   		}
   	}
#endif


  // MACRODOWN only works in this function
      switch(id) {
        case 0:
          if (record->event.pressed) {
            register_code(KC_RSFT);
          } else {
            unregister_code(KC_RSFT);
          }
        break;

 /* Colemak mod-dh moves the D key to the qwerty V position
   This hack makes apple-V_position do what I mean */
 	case DHPASTE:
		if(keyboard_report->mods & MOD_BIT(KC_LGUI) ) {
			if (record->event.pressed) {
	  	 		clear_keyboard_but_mods();
		 		register_code(KC_V);
	     	} else {
		 		unregister_code(KC_V);
	    	}
		} else {
            if (record->event.pressed) {
          		register_code(KC_D);
            } else {
           		unregister_code(KC_D);
	   		}
		}
	break;

	case VIBRK: // vi esc:
		 if (record->event.pressed) {
			return MACRO( T(ESC),D(LSFT),T(SCLN),U(LSFT), END );
		 }
	break;




	default:
    	return MACRO_NONE;
    }


return MACRO_NONE;
};


void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  debug_enable=true;
  //debug_matrix=true;
  //debug_keyboard=true;
  //debug_mouse=true;
}


void matrix_init_user(void) {
    #ifdef RGB_MATRIX_ENABLE
    rgblight_setrgb(RGB_GREEN);
    #endif //RGB_matrix  
}


void matrix_scan_user(void) {
  
}


void led_set_user(uint8_t usb_led) {
#ifdef BOARD_GENERIC_STM32_F103
    if (usb_led & (1<<USB_LED_CAPS_LOCK)) {
        LED_ON();
    } else {
        LED_OFF();
    }
#endif
}





// Runs whenever there is a layer state change.
layer_state_t layer_state_set_user(layer_state_t state) {

  uint8_t layer = get_highest_layer(state);
  switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #else
          #ifdef RGBLIGHT_ENABLE
            rgblight_init();
          #endif
        #endif
        break;
      case 1:
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case 3:
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      default:
       break;
    }
    #ifdef VIRTSER_ENABLE
          virtser_send('l'); // ascii 0 is 48
            virtser_send(layer + 48); // ascii 0 is 48
            virtser_send(' '); // space
    #endif
  return state;
};

// custom tapping term lengths. 
uint16_t get_tapping_term(uint16_t keycode) {
  switch (keycode) {
    case LT(_MOV, KC_TAB):
      return TAPPING_TERM /2 ;
    default:
      return TAPPING_TERM;
  }
}



#ifdef VIRTSER_ENABLE
uint8_t ser_rgbval[18] ; //ascii string 

uint8_t ser_cmd_started =0 ; // are we in process
uint8_t ser_rgb_bytes = 0 ; // exit process after this many bytes. 


void virtser_recv(uint8_t serIn) 
{
 
  if (1 == ser_cmd_started) {
    if ( (serIn <= '9') && (serIn >='0') ) { //ascii only 
        if (ser_rgb_bytes <8) {
        ser_rgbval[ser_rgb_bytes] = serIn;
        ser_rgb_bytes++;
         virtser_send(serIn);
      //   virtser_send('|');
      } else {
          ser_cmd_started =0 ;
          ser_rgbval[ser_rgb_bytes] = serIn;
          virtser_send(serIn);
          virtser_send('|');
          rgblight_setrgb( // todo - find the function for tuple to int that already exists // BUG, not checking for 0-255
            (ser_rgbval[0] -'0')*100 + (ser_rgbval[1] -'0')*10 + (ser_rgbval[2] -'0' ),
            (ser_rgbval[3] -'0')*100 + (ser_rgbval[4] -'0')*10 + (ser_rgbval[5] -'0' ),
            (ser_rgbval[6] -'0')*100 + (ser_rgbval[7] -'0')*10 + (ser_rgbval[8] -'0' ) );
      }
    }
  } else {

    switch (serIn) {
     case 'c': { // color switch
        ser_cmd_started=1;
        ser_rgb_bytes=0;
         virtser_send(serIn);
        break;
      }
      case 'r': {//red
       rgblight_setrgb(RGB_RED);
       break;
      } 
      case 'g': {
         rgblight_setrgb(RGB_GREEN);
         break;
      } 
      case 'b': { // color switch
         rgblight_setrgb(RGB_BLUE);
         break;
      } 
       case 'w': { // color switch
         rgblight_setrgb(RGB_WHITE);
         break;
      } 
       case 'o': { // color black/off
         rgblight_setrgb(0,0,0);
         break;
      } 
      case 'T': { // toggle
         rgblight_toggle();
         break;
      } 
        case 'P': { // 
         rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING);
         break;
      } 
        case 'S': { // 
         rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
         break;
      } 
        case 'U': { // 
         rgblight_mode_noeeprom(RGBLIGHT_MODE_RAINBOW_MOOD);
         break;
      } 
      default: {
        virtser_send(serIn);
        break;
      }
    }
  }

}
     
#endif


#ifdef RAW_ENABLE

void raw_hid_receive( uint8_t *data, uint8_t length )
{
//print("enterd hid");
 // uint8_t *reportID = &(data[0]);
  //uint8_t *command_id = &(data[1]);
 // uint8_t *command_data = &(data[2]);
/*
  uint8_t *red =&(data[3]);
  uint8_t *blue =&(data[4]);
  uint8_t *green =&(data[5]);
*/
/* 
// Blink(1) APIcommands 
  https://github.com/todbot/blink1/blob/master/hardware/firmware_mk2/main.c

Copyright (c) ThingM, 2012-2018
'blink(1)' is a trademark of ThingM Corporation
LICENSE:  
Creative Commons - Attribution - ShareAlike 3.0 
http://creativecommons.org/licenses/by-sa/3.0/

// Available commands in blink(1):
//    - Fade to RGB color       format: { 1, 'c', r,g,b,     th,tl, ledn }
//    - Set RGB color now       format: { 1, 'n', r,g,b,       0,0, ledn } (*)
//    - Read current RGB color  format: { 1, 'r', n,0,0,       0,0, ledn } (2)
//    - Serverdown tickle/off   format: { 1, 'D', {1/0}, th,tl,  {1/0},sp,ep } (*)
//    - PlayLoop                format: { 1, 'p', on,sp,ep,c,    0, 0 } (2)
//    - Playstate readback      format: { 1, 'S', 0,0,0,       0,0, 0 } (2)
//    - Set color pattern line  format: { 1, 'P', r,g,b,     th,tl, p }
//    - Save color patterns     format: { 1, 'W', 0,0,0,       0,0, 0 } (2)
//    - read color pattern line format: { 1, 'R', 0,0,0,       0,0, p }
//    - Set ledn                format: { 1, 'l', n,0,0,       0,0, 0 } (2+)
//    - Read EEPROM location    format: { 1, 'e', ad,0,0,      0,0, 0 } (1)
//    - Write EEPROM location   format: { 1, 'E', ad,v,0,      0,0, 0 } (1)
//    - Get version             format: { 1, 'v', 0,0,0,       0,0, 0 }
//    - Test command            format: { 1, '!', 0,0,0,       0,0, 0 }
*/
  /*
// assume result ID = 1? 
  switch ( *command_id )
  {
    case 'n':
    case 'c':
    {
   //   uint8_t ledn = data[7];          // which LED to address
    //  if ( (ledn > 0)  && (ledn < RGBLED_NUM) ) {
      //  rgblight_setrgb_at(data[2],data[3],data[4], data[7]);
     // } else {
        rgblight_setrgb(0xFF,0xFF,0xFF);
     // }
      break;
    }
  //    - Get version             format: { 1, 'v', 0,0,0,       0,0, 0 }
    case 'v':
    {
      data[3] = '2' ;
      data[4] = '7' ;
      break;
    }

    default:
    {
      // Unhandled message.
      data[0] = 0;
      break;
    }
  }
 

  // Return same buffer with values changed
  raw_hid_send( data, length );
  // rgblight_setrgb(0,255,127);
  */
}

#endif


