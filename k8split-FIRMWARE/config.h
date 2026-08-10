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
#ifndef CONFIG_H
#define CONFIG_H

/* USB Device descriptor parameter */
#define VENDOR_ID       0xC81D
#define PRODUCT_ID      0xC868
#define DEVICE_VER      0x0002
#define MANUFACTURER    Ckat 
#define PRODUCT         k8split
#define DESCRIPTION     rev0.2

/* key matrix size */
#define MATRIX_ROWS 6
#define MATRIX_COLS 16

/* ROW/COL MASKS */
#define ROW_MASK  0b00111111 /* PD0-PD5 row0-row5 */
#define COLB_MASK 0b11111111 /* PB0-PB7 col0-col7 */
#define COLF_MASK 0b11110000 /* PF4-PF6 col8-col11 */
#define COLC_MASK 0b11000000 /* PC6-PF7 col12-col13 */
#define COLD_MASK 0b11000000 /* PD6-PD7 col14-col15 */

/* can get away with lower since silent choc v2 */
#define DEBOUNCE 3

/* disable action features */
#define NO_ACTION_LAYER
#define NO_ACTION_TAPPING
#define NO_ACTION_ONESHOT
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION

#endif
