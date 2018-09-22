#include "msp.h"
#include <msp432P401R.h>

/*
 * main.c
 */

void main(void)
{
    WDTCTL = WDTPW + WDTHOLD;                 // Stop watchdog timer
     P1DIR |= BIT0;                            // Set P1.0 to output direction
     P2DIR |= BIT0;
     for(;;)
     {
       volatile unsigned int i;
         i = 350000;


      while(i != 0)
      {
       i--;
       if( i % 5000 == 0 ) {
            P1OUT ^= BIT0;
         }
         if( i % 7000 == 0 ){
             P2OUT ^= BIT0;
         }

      }





     }

}
