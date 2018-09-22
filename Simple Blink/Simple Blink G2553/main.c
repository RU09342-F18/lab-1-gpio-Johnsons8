#include <msp430.h> 
#include <msp430G2553.h>

/*
 * main.c
 */

void main(void)
{
    WDTCTL = WDTPW + WDTHOLD;                 // Stop watchdog timer
     P1DIR |= 0x01;                            // Set P1.0 to output direction
     for(;;)
     {
       volatile unsigned int i;
         P1OUT ^= 0x01;                        // if P1.4 set, set P1.0
      i = 20000;
      do(i--);
      while(i != 0);
     }
} // CCR0_
