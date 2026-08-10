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
#include <stdint.h>
#include <stdbool.h>
#include <avr/io.h>
#include <util/delay.h>
#include "timer.h"
#include "matrix.h"

/* debouncing */
static bool debouncing = false;
static uint16_t debouncing_time = 0;

/* matrix state tracking */
static matrix_row_t matrix[MATRIX_ROWS];
static matrix_row_t matrix_debouncing[MATRIX_ROWS];

/* col/row reading macros */
#define SELECT_ROW(r) PORTD = (PORTD | ROW_MASK) & ~(1 << r)
#define UNSELECT_ROWS() PORTD |= ROW_MASK
#define READ_COLS() ~((PINB & COLB_MASK) | \
                     ((PINF & COLF_MASK) << 4) | \
                     ((PINC & COLC_MASK) << 6) | \
                     ((PIND & COLD_MASK) << 8))


void matrix_init(void)
{
	/* init io */
    UNSELECT_ROWS();
    /* set all cols as inputs with pullup */
    DDRB &= (uint8_t) ~COLB_MASK;
    DDRF &= (uint8_t) ~COLF_MASK;
    DDRC &= (uint8_t) ~COLC_MASK;
    DDRD &= (uint8_t) ~COLD_MASK;
    PORTB |= COLB_MASK;
    PORTF |= COLF_MASK;
    PORTC |= COLC_MASK;
    PORTD |= COLD_MASK;

    /* initialize matrix state: all keys off */
    for (uint8_t i=0; i < MATRIX_ROWS; i++) {
        matrix[i] = 0;
        matrix_debouncing[1] = 0;
    }
}

uint8_t matrix_scan(void)
{
    for (uint8_t i = 0; i < MATRIX_ROWS; i++) {
        SELECT_ROW(i);
        _delay_us(5); /* delay for settling */
        matrix_row_t cols = READ_COLS();
        if (matrix_debouncing[i] != cols) {
            matrix_debouncing[i] = cols;
            debouncing = true;
            debouncing_time = timer_read();
        }
        UNSELECT_ROWS();
    }

    if (debouncing && timer_elapsed(debouncing_time) >= DEBOUNCE) {
        for (uint8_t i = 0; i < MATRIX_ROWS; i++) {
            matrix[i] = matrix_debouncing[i];
        }
        debouncing = false;
    }

    return 1;
}

inline
matrix_row_t matrix_get_row(uint8_t row)
{
    return matrix[row];
}
