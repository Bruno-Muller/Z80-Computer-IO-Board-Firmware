/* 
 * File:   conf.h
 * Author: Bruno
 *
 * Created on 18 décembre 2014, 20:46
 */

#ifndef CONF_H
#define	CONF_H

#include <xc.h>

#define _XTAL_FREQ 16000000

// Decoder
#define DECODER_SELECT_A    RA0 // output
#define DECODER_SELECT_B    RA1 // output
#define DECODER_SELECT_C    RA2 // output
#define DECODER_SELECT      RA3 // output

#define INT_IO          RC0 // output

// input/output configuration register
#define DEFAULT_PORTA   0b00001000
#define DEFAULT_ANSELA  0x00
#define DEFAULT_TRISA   0b00100000

#define DEFAULT_PORTB   0b00000000
#define DEFAULT_ANSELB  0x00
#define DEFAULT_TRISB   0b00011111

#define interrupt_assert()      INT_IO = 0
#define interrupt_disassert()   INT_IO = 1



/******************************
 * #pragma config Settings    *
 * Register: CONFIG1 @ 0x2007 *
 ******************************/

/*
 * BOREN =  Brown-out Reset Selection bits
 * OFF      BOR disabled
 * ON       BOR enabled
 * NSLEEP   BOR enabled during operation and disabled in Sleep
 */

#pragma config BOREN = ON

/*
 * PLLEN =  INTOSC PLL Enable bit
 * OFF      INTOSC Frequency is 500 kHz
 * ON       INTOSC Frequency is 16MHz (32x)
 */

#pragma config PLLEN = ON

/*
 * DEBUG =  In-Circuit Debugger Mode bit
 * OFF      In-circuit debugger disabled, RB6/ICSPCLK and RB7/ICSPDAT are general purpose I/O pins
 * ON       In-circuit debugger enabled, RB6/ICSPCLK and RB7/ICSPDAT are dedicated to the debugger
 */

#pragma config DEBUG = OFF

/*
 * FOSC =	Oscillator Selection bits
 * EXTRCCLK	RC oscillator: CLKOUT function on RA6/OSC2/CLKOUT pin, RC on RA7/OSC1/CLKIN
 * INTOSCCLK    INTOSC oscillator: CLKOUT function on RA6/OSC2/CLKOUT pin, I/O function on RA7/OSC1/CLKIN
 * XT           XT oscillator: Crystal/resonator on RA6/OSC2/CLKOUT and RA7/OSC1/CLKIN
 * LP           LP oscillator: Low-power crystal on RA6/OSC2/CLKOUT and RA7/OSC1/CLKIN
 * EXTRCIO	RCIO oscillator: I/O function on RA6/OSC2/CLKOUT pin, RC on RA7/OSC1/CLKIN
 * EC           EC: I/O function on RA6/OSC2/CLKOUT pin, CLKIN on RA7/OSC1/CLKIN
 * INTOSCIO	INTOSCIO oscillator: I/O function on RA6/OSC2/CLKOUT pin, I/O function on RA7/OSC1/CLKIN
 * HS           HS oscillator: High-speed crystal/resonator on RA6/OSC2/CLKOUT and RA7/OSC1/CLKIN
 */

#pragma config FOSC = INTOSCCLK

/*
 * BORV =   Brown-out Reset Voltage selection bit
 * 19       Brown-out Reset Voltage (VBOR) set to 1.9 V nominal
 * 25       Brown-out Reset Voltage (VBOR) set to 2.5 V nominal
 */

#pragma config BORV = 25

/*
 * MCLRE =  RE3/MCLR Pin Function Select bit
 * OFF      RE3/MCLR pin function is digital input, MCLR internally tied to VDD
 * ON       RE3/MCLR pin function is MCLR
 */

#pragma config MCLRE = ON

/*
 * WDTE =   Watchdog Timer Enable bit
 * OFF      WDT disabled and can be enabled by SWDTEN bit of the WDTCON register
 * ON       WDT enabled
 */

#pragma config WDTE = OFF

/*
 * CP = Code Protection bit
 * OFF	Program memory code protection is disabled
 * ON	Program memory code protection is enabled
 */

#pragma config CP = ON

/*
 * PWRTE =  Power-up Timer Enable bit
 * OFF      PWRT disabled
 * ON       PWRT enabled
 */

#pragma config PWRTE = ON

/******************************
 * Register: CONFIG2 @ 0x2008 *
 ******************************/

/*
 * VCAPEN = Voltage Regulator Capacitor Enable bits
 * RA5      VCAP functionality is enabled on RA5
 * DIS      All VCAP pin functions are disabled
 * RA6      VCAP functionality is enabled on RA6
 * RA0      VCAP functionality is enabled on RA0
 */

#pragma config VCAPEN = DIS

/*****************************
 * Register: IDLOC0 @ 0x2000 *
 * Register: IDLOC1 @ 0x2001 *
 * Register: IDLOC2 @ 0x2002 *
 * Register: IDLOC3 @ 0x2003 *
 *****************************/

#endif	/* CONF_H */

