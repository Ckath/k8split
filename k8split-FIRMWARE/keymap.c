/* MIT License

Copyright (c) 2026 Ckat <Ckath@yandex.ru>

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
#include "keymap.h"
#define KC_AUDIO_MMUTE KC_F20
#define KC_COMP KC_APP

/* LEFT                                                                                               RIGHT
   +---------------------------------------+                      +---------------------------------------+
   | ESC| F1 | F2 | F3 | F4 | F5 | F6 |MUTE|                      | F7 | F8 | F9 | F10| F11| F12| INS|PSCR|
   +---------------------------------------|                 +--------------------------------------------|
   | `  | 1  | 2  | 3  | 4  | 5  | 6  |MMIC|                 | DEL| 7  | 8  | 9  | 0  | -  | =  |  BCKSPC |
   +-----------------------------------------+               +--------------------------------------------|
   | TAB  | q  | w  | e  | r  | t  | JP | MWU|                  | y  | u  | i  | o  | p  | [  | ]  |   \  |
   +------------------------------------------+             +---------------------------------------------|
   | CTRL  | a  | s  | d  | f  | g  |COMP| MWD|             |PGUP| h  | j  | k  | l  | ;  | '  |    ENTER |
   +---------------------------------------------|        +-----------------------------------------------|
   | SHIFT    | z  | x  | c  | v  | b  | F13| F14|        |HOME|PGDN| n  | m  | ,  | .  | /  |      SHIFT |
   +-------------------------------------------------+  +-------------------------------------------------+
   | CTRL |CAPS|SUPR| ALT |   SPACE   | F15| F16| F17|  | END|   SPACE   | ALT | <- | ↓  | ↑  | -> | CTRL |
   +-------------------------------------------------+  +-------------------------------------------------+ */

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* 0: qwerty */
{
    { KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_AUDIO_MUTE, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_INS, KC_PSCR },
    { KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_AUDIO_MMUTE, KC_DEL, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC },
    { KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_INT5, KC_MS_WH_UP, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS },
    { KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G, KC_COMP, KC_MS_WH_DOWN, KC_PGUP, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENTER },
    { KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_F13, KC_F14, KC_HOME, KC_PGDN, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT },
    { KC_LCTL, KC_CAPS, KC_LGUI, KC_LALT, KC_SPC, KC_F15, KC_F16, KC_F17, KC_END, KC_SPC, KC_RALT, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_RCTL }
}
};

/* required even if not used */
const action_t fn_actions[] PROGMEM = {};
