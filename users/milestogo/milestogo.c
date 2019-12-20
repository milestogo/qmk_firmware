// based on drashna's but I think at this point it's a new axe

#include QMK_KEYBOARD_H
#include "milestogo.h"
#include <print.h>

__attribute__ ((weak))
bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  return true;
}

bool move_is_on =false; // track if we are in _MOV layer
bool sym_is_on =false; // track if we are in _SYM layer

// Defines actions for global custom keycodes
// Then runs the _keymap's record handier if not processed here
bool process_record_user(uint16_t keycode, keyrecord_t *record) {

static uint16_t altmov_timer; // timer for altmov key
static uint16_t guimov_timer; // timer for guimov key
//static uint16_t spcmov_timer; // timer for spcmov key

#ifdef USE_BABBLEPASTE
     if( keycode > BABBLE_START && keycode < BABBLE_END_RANGE )  {
        if (record->event.pressed)  { // is there a case where this isn't desired?
          babblePaste ( keycode );
        } else{
          return true;
        }
      }   
#endif

    switch (keycode) {
        case _QWERTY:
        if (record->event.pressed) {
          set_single_persistent_default_layer(_QWERTY);
        }
        break;

        case _CDH:
        if (record->event.pressed) {
          set_single_persistent_default_layer(_CDH);
        }
        break;

        case TMUX: // ctl-B
         if (record->event.pressed) {
              SEND_STRING(SS_DOWN(X_LCTRL)SS_TAP(X_B)SS_DOWN(X_LCTRL));
         }
        break;

    /* Colemak mod-dh moves the D key to the qwerty V position
                This hack makes apple-V_position do what I mean */
        case DHPASTE:
            if(get_mods() & MOD_BIT(KC_LGUI) ) {
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
            return false;
            break;

    case ALTSYM: 
        if (record->event.pressed) {
            altmov_timer = timer_read();
            register_code(KC_LALT);
     } else {
        unregister_code(KC_LALT);

        if (timer_elapsed(altmov_timer) < TAPPING_TERM) {
          if(sym_is_on  == true) {
            layer_off(_SYM);
            sym_is_on = false ;
          } else {
            layer_on(_SYM);
            sym_is_on = true;
          }
        }
     }
     return false;
  break;

    case GUISYM: 
        if (record->event.pressed) {
            guimov_timer = timer_read();
            register_code(KC_RGUI);
        } else {
            unregister_code(KC_RGUI);
            if (timer_elapsed(guimov_timer) < TAPPING_TERM) {
               if(sym_is_on  == true) {
                    layer_off(_SYM);
                    sym_is_on = false ;
                } else {
                    layer_on(_SYM);
                    sym_is_on = true;
                }
            }
        }
        return false;
        break;

    default:
    return true;
    }

  // normal keycode
 return process_record_keymap(keycode, record); 
}


void babble_led_user(void) {
#ifdef USE_BABLPASTE
    extern uint8_t babble_mode;

    #ifdef BABL_WINDOWS
        if (babble_mode == BABL_WINDOWS_MODE) {
            if (BABL_LED_INDEX >0) {   
                rgblight_setrgb_at(RGBLIGHT_COLOR_MS,BABL_LED_INDEX);
            } else {
                rgblight_setrgb(RGBLIGHT_COLOR_MS);
            }
        }
    #endif
    #ifdef BABL_READMUX
        if (babble_mode == BABL_READMUX_MODE){
            if (BABL_LED_INDEX >0) {   
                rgblight_setrgb_at(RGBLIGHT_COLOR_READMUX,BABL_LED_INDEX);
            } else {
                rgblight_setrgb(RGBLIGHT_COLOR_READMUX);
            }
        }
    #endif 
    #ifdef BABL_MAC
        if ( babble_mode == BABL_MAC_MODE) {
            if (BABL_LED_INDEX >0) {   
                rgblight_setrgb_at(RGBLIGHT_COLOR_MAC,BABL_LED_INDEX);
            } else {
                rgblight_setrgb(RGBLIGHT_COLOR_MAC);
            }
        }
    #endif
    #ifdef BABL_VI
        if (babble_mode == BABL_VI_MODE){
            if (BABL_LED_INDEX >0) {   
                rgblight_setrgb_at(RGBLIGHT_COLOR_VI,BABL_LED_INDEX);
            } else {
                rgblight_setrgb(RGBLIGHT_COLOR_VI);
            }
        }
    #endif
    #ifdef BABL_EMACS
        if (babble_mode == BABL_EMACS_MODE){
            if (BABL_LED_INDEX >0) {   
                rgblight_setrgb_at(RGBLIGHT_COLOR_EMACS,BABL_LED_INDEX);
            } else {
                rgblight_setrgb(RGBLIGHT_COLOR_EMACS);
            }
        }
    #endif
    #ifdef BABL_CHROMEOS
         if (babble_mode == BABL_CHROMEOS_MODE) {
            if (BABL_LED_INDEX >0) {   
                rgblight_setrgb_at(RGBLIGHT_COLOR_CHROMEOS,BABL_LED_INDEX);
            } else {
                rgblight_setrgb(RGBLIGHT_COLOR_CHROMEOS);
            }
        }
    #endif
    #ifdef BABL_LINUX 
        if (babble_mode == BABL_LINUX_MODE){
            if (BABL_LED_INDEX >0) {   
                rgblight_setrgb_at(RGBLIGHT_COLOR_LINUX,BABL_LED_INDEX);
            } else {
                rgblight_setrgb(RGBLIGHT_COLOR_LINUX);
            }
        }
    #endif
#endif  // bablepaste
}



#ifdef TAP_DANCE_ENABLE
uint8_t cur_dance (qk_tap_dance_state_t *state);

// thanks to http://thedarnedestthing.com/planck%20qmk for these ideas
static uint8_t mods = 0;

void tap_mods(keyrecord_t *record, uint16_t keycode)
{
  if (record->event.pressed) {
    register_code  (keycode);
    mods |= MOD_BIT(keycode);
  }
  else {
    unregister_code(keycode);
    mods &= ~(MOD_BIT(keycode));
  }
}

// straight from https://beta.docs.qmk.fm/features/feature_tap_dance

static babblespace_state bstate = {
 .is_press_action = false,
 .state = 0,
 .insideLayer = 0,
 .sticky = false
} ;

//Tap Dance Definitions
uint8_t cur_dance (qk_tap_dance_state_t *state) {
  if (state->count == 1) {
    if (state->interrupted || !state->pressed)  return SINGLE_TAP;
    else return SINGLE_HOLD;
  }
  else if (state->count == 2) {
    if (state->pressed) return DOUBLE_HOLD ;
    if (state->interrupted) return DOUBLE_SINGLE_TAP;
    else return DOUBLE_TAP;
  }
 if (state->count == 3) {
    if (state->interrupted || !state->pressed)  return TRIPLE_TAP;
    else return TRIPLE_HOLD;
  }
  else return 8; // magic - should not be possible given the timeout.  
}

uint8_t multi_tap(uint16_t keycode, uint8_t count) {
  uint8_t x;
  for ( x=0; x< count ; x++ ) {
    register_code(keycode);
    unregister_code(keycode);
  }
 return x;
}


qk_tap_dance_action_t tap_dance_actions[] = {
 //[CT_CLN] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_cln_finished, dance_cln_reset)
};

//babblespace. 
// thanks to https://github.com/algernon/ergodox-layout/keymap.c
//////
// hold -> layer shift
// tap & hold -> held spacebar. 
// tap -> unlock layer, or keycode
// typing fast -> keycode * taps, following key. 

void dance_bablespace_finished (qk_tap_dance_state_t *state, void *user_data) {
  
  // algernon's version uses the user data format. The doc example uses a global. Why. 
  // babblespace_state *bstate = (babblespace_state *) user_data;
  bstate.state =  cur_dance(state);
  
  switch (bstate.state){
    case SINGLE_HOLD: layer_on(_MOV); break;
    case SINGLE_TAP: register_code(KC_SPACE); break;
    case TAP_TAP_TYPE: 
       register_code(KC_SPACE);
       unregister_code(KC_SPACE);
       register_code(KC_SPACE);
      break;
    case TAP_TAP_HOLD:  // we want a lot of spaces. 
      //multi_tap(KC_SPACE,bstate.state); // drop a few, but that's ok. 
      register_code(KC_SPACE);
      break;
    case MULTI_TAP:
      multi_tap(KC_SPACE,bstate.state);
      register_code(KC_SPACE);
      break;
  }  
}

void dance_bablespace_reset(qk_tap_dance_state_t *state, void *user_data) {

  switch (bstate.state){
    case SINGLE_HOLD:layer_off(_MOV); break;
    case SINGLE_TAP: unregister_code(KC_SPACE); break;
    case TAP_TAP_TYPE: unregister_code(KC_SPACE); break;
    case TAP_TAP_HOLD: unregister_code(KC_SPACE); break;
    case MULTI_TAP: unregister_code(KC_SPACE);  break;
  }
 bstate.state=0;
}

#endif //TAP_DANCE_ENABLE

  
