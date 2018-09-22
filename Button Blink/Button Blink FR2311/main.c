#include <msp430.h> 
#include <msp430FR2311.h>

/*
 * main.c
 */

void main(void)
{
    WDTCTL = WDTPW + WDTHOLD;               // Stop watchdog timer

            P1REN |= 0x02;                          //Turn on PullUp on????? How do you turn it off?

            P1DIR &= ~BIT1;                         // Push Port 1 P1.3 (push button) as input
            P1REN &= ~0x02;                         // Pull down resistor???
            P1DIR |= BIT3;                          // Set P1.6 (LED) to output direction
   //         P1SEL &= ~(BIT1 | BIT3);                // Select Port 1 P1.3 (push button)

            P1OUT &= ~BIT3;                         // Set the LED off


            while( 1 ) {
                int value = P1IN & BIT1;
                    if( value == 0)         // Push button down when bit 3 == 0
                            P1OUT |= BIT3;          // Set LED on when button down
                    else
                            P1OUT &= ~BIT3;         // Set LED off when button off
            }
} // CCR0_ISR
