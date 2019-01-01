#pragma once
#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x6464
#define DEVICE_VER      0x0001
/* in python2: list(u"whatever".encode('utf-16-le')) */
/*   at most 32 characters or the ugly hack in usb_main.c works */

//  Modified by Xydane
#define MANUFACTURER "QMK"
#define USBSTR_MANUFACTURER    'Q', '\x00', 'M', '\x00', 'K', '\x00', ' ', '\x00', '\xc6', '\x00'
#define PRODUCT "8x18"
#define USBSTR_PRODUCT         'Q', '\x00', 'M', '\x00', 'K', '\x00'
#define DESCRIPTION "QMK keyboard firmware with AVR"

/* key matrix size */
#define MATRIX_ROWS 8
#define MATRIX_COLS 18
#define DIODE_DIRECTION ROW2COL

// Iso fix for Space Cadet, comment for ANSI layouts
#define LSPO_KEY KC_8
#define RSPC_KEY KC_9 


/* teensy 2++ on 8x18 pcb */
#define MATRIX_ROW_PINS { D1,D2, D3, D4, D5, D6,D7,E0} 
#define MATRIX_COL_PINS { E1, C0, C1, C2, C3, C4, B7, B3, B2, B1, B0, E7, E6, F0, F1, F2, F3, F4}
#define UNUSED_PINS { D0, C7,F5, F6, F7, B4,B5,B6 }
