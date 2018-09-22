#include "msp.h"
#include <msp432P401R.h>

void main(void)
{
    WDTCTL = WDTPW + WDTHOLD;                 // Stop watchdog timer
     P1DIR |= BIT0;                            // Set P1.0 to output direction
     P2DIR |= BIT0;                            // Set P2.0 to output direction
     for(;;)
     {
       volatile unsigned int i;
         i = 350000;
      while(i != 0)
      {
       i--;
       if( i % 5000 == 0 ) {                //Everytime counter goes down to a number divisible by 5000 LED1.0 toggles
            P1OUT ^= BIT0;
         }
         if( i % 7000 == 0 ){               //Everytime counter goes down to a number divisible by 7000 LED2.0 toggles
             P2OUT ^= BIT0;
        }
      }
     }
}
