# Microsoft Sculpt Mobile

This is a way to take a Microsoft ergonomic bluetooth keyboard, and make it 
into a hard-wired keyboard running QMK. 

The keyboard is known under several different names:
Mobile Bluetooth 5000, Mobile 6000, Sculpt mobile, and Asus rebranded.  Yours may have a different matrix. 
The keyboards are cheap on ebay, travel well, and are just ergo enough.


In addition to the original handwired build, I've built an 8x18 FFC PCB I will open source. 
 
For handwiring:
If you don't have hot air tools, cut the original ribbon cable sockets off the bluetooth board using a razor.
The factory sockets allow the cable to be inserted on top or bottom.
The ribbon cable is 1mm pitch. 

As I was debugging the matrix, I started to get random failures. Ribbon cable
 connections can get worn. Shave a half millimeter off the end of the ribbon cable & the errors go away.

There are multiple hardware versions, each with a different matrix. 

Liteon model XUA
|   | A  | B  | C  | D   | E   | F   | G    | H    | I    | J     | K    | L      | M    | N     | O    | P      | Q    | R   |
|:-:|:--:|:--:|:--:|:---:|:---:|:---:|:----:|:----:|:----:|:-----:|:----:|:------:|:----:|:-----:|:----:|:------:|:----:|:---:|
| 0 | b  | n  | m  | ,   | .   | /   |      |      |      | Caps  |      |        |      |       |      |        |      | Fn  |
| 1 | g  | h  | "  |     |     |     |      |      |      |       | Vol+ | Mute   | RCtl |       | Vol- | PgDn   | LCtl |     |
| 2 | 7  | 8  | 9  | 0   | Del |     | PgUp |      |      |       |      | RShift |      |       |      | LShift |      |     |
| 3 | p  | [  | ]  | \   |     |     |      |      |      |       | RAlt |        |      |       | LAlt |        |      |     |
| 4 | y  | u  | i  | o   |     |     |      |      |      |       |      |        |      | LGUI  |      |        |      |     |
| 5 | ~  | -  | += | j   | k   | l   | ;    | 5    | 6    | Bksp  | 1    | 2      | 3    | 4     | F4   | F5     | F6   |     |
| 6 | a  | s  | d  | q   | w   | e   | Up   | Left | Down | Right |      |        |      | Space | F1   | F2     | F3   | Tab |
| 7 | F7 | F8 | F9 | F10 | F11 | F12 |      | f    | r    | t     | z    | x      | c    |       | v    | Enter  | Esc  |     |


Liteon model XUW
|   | A  | B  | C  | D   | E   | F   | G    | H    | I    | J     | K    | L      | M    | N     | O    | P      | Q    | R   |
|:-:|:--:|:--:|:--:|:---:|:---:|:---:|:----:|:----:|:----:|:-----:|:----:|:------:|:----:|:-----:|:----:|:------:|:----:|:---:|
| 0 |    |    |    |  b  |  n  |     |      |   /  | spc  | Right | Down |        | left | ralt  |      |        |      |     |
| 1 | z  | x  |  c |  v  |  m  |  ,  |   .  |      | ent  |       |      |        |      |       | rsft | rCtl   |   fn |     |
| 2 |ESC | s  | F4 |  g  |  h  |  F6 |      |   "  | f5   |       |      |        | up   | lalt  |      |        |      |     |
| 3 | a  |    |  d |  f  |  j  |  k  |   l  |   ;  |   \  |       |      |        |      |       |      |        |      | LGUI|
| 4 |tab | w  | f3 |  t  |  y  |  ]  |  F7  |   [  | Bspc |       |      |        |      |       | lsft |        |      |     |
| 5 | q  |Caps|  e |  r  |  u  |  i  |   o  |   p  |      |       |      |        |      |       |      |        |      |     |
| 6 | 1  | 2  |  3 |  4  |  7  |  8  |   9  |   0  | F10  | F12   |  F11 | PgUp   | mute | vol+  |      |        |      |     |
| 7 | ~  | F1 | F2 |  5  |  6  |  =  |  F8  |   -  | F9   |       |  Del | PgDn   | home |       |      | lCtl   |      |     |


iso Spanish keyboard liteon 29W, using UK ISO layout for ease in comparion. Basically same as XUW, with iso1 = <> , iso2=] 
|   | A0 | B  | C2 | D   | E4  | F   | G6   | H    | I8   | J     | K10  | L      | M12  | N     | O14  | P      | Q16  | R   |
|:-:|:--:|:--:|:--:|:---:|:---:|:---:|:----:|:----:|:----:|:-----:|:----:|:------:|:----:|:-----:|:----:|:------:|:----:|:---:|
| 0 |    |    |    |  B  | N   |     |      |  /   | SPC  |RIGHT  | DOWN |        | Left  | AltGr|      |        |      |     |
| 1 |  Z |  X | C  |  V  | M   | ,   |   .  | ISO2 | ENTR |       |      |        |      |       |RSFT  | RCTL   |  FN  |     |
| 2 | Esc| S  | F4 |  G  | H   | F6  |      |  ""  |  F5  |       |      |        |  Up  |  LAlt |      |        |      |     |
| 3 | A  |ISO1| D  |  F  | J   |  K  |  L   |   ;  |      |       |      |        |      |       |      |        |      |LGUI |
| 4 |Tab | W  | F3 |  T  | Y   |  ]  |  F7  |   [  | BACK |       |      |        |      |       |LSFT  |        |      |     |
| 5 | Q  |Caps| E  |  R  | U   | I   |  O   |  P   |      |       |      |        |      |       |      |        |      |     |
| 6 | 1  | 2  | 3  |  4  | 7   | 8   |  9   |  0   |  F10 |   F12 | F11  |  PGDN  | End  |PrntScn|      |        |      |     |
| 7 |Grve| F1 | F2 |  5  | 6   | =   |  F8  |  -   |  F9  |       | DEL  | PGUP   | Home |       |      | LCTL   |      |     |


My method for discovering the matrix was to set up a keymap that has all printable symbols
in all rows. Load the matrix keymap, start hid_listen, fill in the blanks. 

Huge thanks to the bluepill controller work of [FPazos](https://github.com/fpazos), and the original [KC64 of Xydane](https://github.com/Xydane/qmk_firmware). I've shamelessly copied from their work. 


Building

Make examples for this keyboard (after setting up your build environment):

    make handwired/ms_sculpt_mobile/handwired:default

    to use a generic STM32F103C8T6 (bluepill)) on an 8x18 board
    make handwired/ms_sculpt_mobile/8x18_arm:default
    then st-flash write ./handwired_ms_sculpt_mobile_8x18_arm_keymap.bin 0x8000000 (no arduino/maple mini bootloader), or
     dfu-util -d 1eaf:0003 -a 2 -D ./handwired_ms_sculpt_mobie_8x18_arm_keymap.bin (using arduino botloader)

    to use the original handwired teensy 2++ version
    	make handwired/ms_sculpt_mobile/handwired:default
    to use the ASTAR mini mcu, add ASTAR=1 to the make options in the handwired rules.mk. 

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).
