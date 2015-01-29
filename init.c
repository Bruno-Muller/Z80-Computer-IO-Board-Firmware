#include "init.h"

void init() {

    /*  Oscillator :
     *  16 MHz
     */
    OSCCON = 0x30;

    /* Option :
     * PORTB pull-ups are disabled
     * Interrupt on falling edge of INT pin
     * Internal instruction cycle clock (FOSC/4)
     * Increment on low-to-high transition on T0CKI pin
     * Prescaler is assigned to the Timer0 module
     * Prescaler Rate Select bits Timer0 1:2
     */
    OPTION_REG = 0x80;

    // Init ports
    PORTA = DEFAULT_PORTA;
    ANSELA = DEFAULT_ANSELA;
    TRISA  = DEFAULT_TRISA;

    PORTB = DEFAULT_PORTB;
    ANSELB = DEFAULT_ANSELB;
    TRISB  = DEFAULT_TRISB;

    INT_IO = 1;
    TRISC0 = 0; // INT_IO

    // Internal configuration
    spi_init();
 
}