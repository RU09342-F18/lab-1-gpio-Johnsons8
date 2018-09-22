#include <msp430.h> 
#include <msp430G2553.h>

/*
 * main.c
 */

void main(void)
{
    WDTCTL = WDTPW + WDTHOLD;                 // Stop watchdog timer
     P1DIR |= BIT0;                            // Set P1.0 to output direction
     P1DIR |= BIT6;                            // Set P1.6 to output direction
     for(;;)                                    // infinite loop
     {
       volatile unsigned int i;
         i = 350000;
     while(i != 0)                          
      {
       i--;
       if( i % 5000 == 0 ) {                    //Everytime counter goes down to something divisible by 5000 LED1 toggles
            P1OUT ^= BIT0;
         }
         if( i % 7000 == 0 ){                   //Everytime counter goes down to something divisible by 7000 LED2 toggles
             P1OUT ^= BIT6;
         }
      }
     }
}

