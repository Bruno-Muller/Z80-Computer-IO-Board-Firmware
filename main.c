/* 
 * File:   newmain.c
 * Author: Bruno
 *
 * Created on 18 décembre 2014, 21:00
 */

#include <xc.h>

#include "conf.h"
#include "decoder.h"
#include "init.h"
#include "spi.h"

#define EVENT_NONE          0x00
#define EVENT_RUN           0x01
#define EVENT_PROGRAM       0x02
#define EVENT_EXAMINE       0x03
#define EVENT_EXAMINE_NEXT  0x04
#define EVENT_DEPOSIT       0x05
#define EVENT_DEPOSIT_NEXT  0x06
#define EVENT_CLEAR         0x07
#define EVENT_RESET         0x08
#define EVENT_HALT          0x09

#define EVENT_ERROR     0x80

/* STATUS bits
 * Clear
 * Reset
 * Halt
 * Program
 * Examine
 * Examine Next
 * Deposit
 * Deposit Next
 */
unsigned char last_status, status, low, high;

void update() {
    unsigned char temp;

    last_status = status;
    status = 0;
    low = 0;
    high = 0;

    decoder_select(0);
    temp = PORTB & 0x1F;
    decoder_unselect();
    low = temp;

    decoder_select(1);
    temp = PORTB & 0x1F;
    decoder_unselect();
    low = low | (temp << 5);
    high = temp >> 3;

    decoder_select(2);
    temp = PORTB & 0x1F;
    decoder_unselect();
    high = high | (temp << 2);

    decoder_select(3);
    temp = PORTB & 0x1F;
    decoder_unselect();
    high = high | ((temp & 0x01) << 7);
    status = (temp << 3) & 0xE0;

    decoder_select(4);
    temp = PORTB & 0x1F;
    decoder_unselect();
    status = status | temp;
}

void main(void) {
    init();
    update();

    while (1) {
        update();

        if (last_status != status) {

            interrupt_assert();

            spi_write(~status);
            spi_write(~low);
            spi_write(~high);

            interrupt_disassert();
        }
    }

}