# Microsoft Sculpt Mobile

This is a way to take a Microsoft ergonomic bluetooth keyboard, and make it 
into a hard-wired keyboard running QMK. 

The keyboard is known under several different names:
Mobile Bluetooth 5000, Mobile 6000, Sculpt mobile, and Asus rebranded.  Yours may have a different matrix. 
The keyboards are cheap on ebay, travel well, and are just ergo enough.


In addition to the original handwired build, I've built an 8+18 FFC PCB I hope to sell or open source. 
 to use a BluePill (generic STM32F103C8T6) on an 8x18 board
    make handwired/ms_sculpt_mobile/8x18_arm:mobile
 to use a teensy 2++ 8x18 board
    make handwired/ms_sculpt_mobile/8x18_avr:mobile
 to use the original handwired teensy 2++
    make handwired/ms_sculpt_mobile/handwired:mobile
 to use the ASTAR mini mcu, add ASTAR=1 to the make options in the handwired rules.mk. 

For handwiring:
If you don't have hot air tools, cut the original ribbon cable sockets off the bluetooth board using a razor.
The factory sockets allow the cable to be inserted on top or bottom.
The ribbon cable is 1mm pitch,I used a cheap set of 
"pitch adapter" boards https://www.amazon.com/Double-Sided-0-4mm-1-0-Adapter-60mmx38mm/dp/B00OK42118 to handwire. 

As I was debugging the matrix, I started to get random failures. Ribbon cable
 connections can get worn. Shave a half millimeter off the end of the ribbon cable & the errors go away.


The full original keymap for the Sculpt is 

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

some (spanish?  windows labeled?) units have a different layout 
|   | A  | B  | C  | D   | E   | F   | G    | H    | I    | J     | K    | L      | M    | N     | O    | P      | Q    | R   |
|:-:|:--:|:--:|:--:|:---:|:---:|:---:|:----:|:----:|:----:|:-----:|:----:|:------:|:----:|:-----:|:----:|:------:|:----:|:---:|
| 0 |    |    |    |  b  |  n  |     |      |   /  | spc  | Right | Down |        | left | ralt  |      |        |      |     |
| 1 | z  | x  |  c |  v  |  m  |  ,  |   .  |      | ent  |       |      |        |      |       | rsft | lCtl   |   fn |     |
| 2 |ESC | s  | F4 |  g  |  h  |  F6 |      |  ''  | f5   |       |      |        | up   | lalt  |      |        |      |     |
| 3 | a  |    |    |  f  |  j  |  k  |   l  |   ;  |   \  |       |      |        |      |       |      |        |      | LGUI|
| 4 |tab | w  | f3 |  t  |  y  |  ]  |  F7  |   [  | Bspc |       |      |        |      |       | lsft |        |      |     |
| 5 | q  |caps|  e |  r  |  u  |  i  |   o  |   p  |      |       |      |        |      |       |      |        |      |     |
| 6 | 1  | 2  |  3 |  4  |  7  |  8  |   9  |   0  | F10  | F12   |  F11 | PgUp   | mute | vol+  |      |        |      |     |
| 7 | ~  | F1 | F2 |  5  |  6  |  =  |  F8  |   -  | F9   |       |  Del | PgDn   | home |       |      | lCtl   |      |     |


If you want a speaker, LEDs, etc., you'll need to free up a pin.  I recommend joining columns
R and L to the same pin.

My method for discovering the matrix was to set up a LAYOUT macro that included all pins.
See MATRIX_TESTING_LAYOUT if you need it. Then set up a keymap that has all printable symbols
in the first 4 rows. test each key & record output. Then switch the printable symbols to the
bottom 4 rows & repeat. This was enough to show the matrix.


Huge thanks to the bluepill controller work of [FPazos](https://github.com/fpazos), and the original [KC64 of Xydane](https://github.com/Xydane/qmk_firmware). I've shamelessly copied from their work. 


Building 

Make examples for this keyboard (after setting up your build environment):

    make handwired/ms_sculpt_mobile/handwired:default

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).
