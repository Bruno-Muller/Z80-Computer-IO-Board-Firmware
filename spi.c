#include "spi.h"

void spi_init() {
    // Init PORTC
    TRISC4 = 1; // SDI configured as input
    TRISC5 = 0; // SDO configured as output
    TRISC3 = 1; // SCK configured as input

    /* Init SSP
     * SSPEN = 1 : Enables serial port and configures SCK, SDO and SDI as serial port pins
     * CKP = 0 : Clock Polarity Select bit = Idle state for clock is a low level
     * Synchronous Serial Port Mode : Master Mode FOSC/4 (4 MHz)
     */
    SSPBUF = 0xFF;
    SSSEL = 0; // SS function is on RA5/AN4/CPS7/SS/VCAP
    SSPSTAT = 0x40; // CKE = 1
    SSPCON = 0x24; // SSPEN = 1; CKP = 0; SPI Slave mode, clock = SCK pin. SS pin control enabled
}

unsigned char spi_write(unsigned char data) {
    SSPBUF = data;
    while (!BF);
    return SSPBUF;
}

unsigned char spi_read() {
    SSPBUF = 0x00;
    while (!BF);
    return SSPBUF;
}