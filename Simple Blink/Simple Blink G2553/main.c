#include <msp430.h> 
#include <msp430G2553.h>                    //This board specifically

void main(void)
{
    WDTCTL = WDTPW + WDTHOLD;                 // Stop watchdog timer
     P1DIR |= 0x01;                            // Tells P1 to be an output
     for(;;)                                   //Infinite loop
     {
       volatile unsigned int i;                 // makes a variable, unsigned so it can be larger and it is not expected to go negative
         P1OUT ^= 0x01;                        // Toggles LED using XOR statement
      i = 20000;                                // resetting i to 200000, which is how many cycles of do while loop will run before next reset
      do(i--);                                  // beginning of do while loop, incrementing i to be 1 less each time
      while(i != 0);
     }
}_
