#include <msp430.h> 
#include <msp430G2553.h>

/*
 * main.c
 */

void main(void)
{
    WDTCTL = WDTPW + WDTHOLD;               // Stop watchdog timer

            P1REN |= 0x08;                          //Turn on PullUp on????? How do you turn it off?

            P1DIR &= ~BIT3;                         // Push Port 1 P1.3 (push button) as input
            P1REN &= ~0x08;                         // Pull down resistor???
            P1DIR |= BIT6;                          // Set P1.6 (LED) to output direction
            P1SEL &= ~(BIT3 | BIT6);                // Select Port 1 P1.3 (push button)

            P1OUT &= ~BIT6;                         // Set the LED off


            while( 1 ) {
                int value = P1IN & BIT3;
                    if( value == 0)         // Push button down when bit 3 == 0
                            P1OUT |= BIT6;          // Set LED on when button down
                    else
                            P1OUT &= ~BIT6;         // Set LED off when button off
            }
} // CCR0_ISR
