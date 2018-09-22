To make this program run you must build the program in CCS and then once it builds successfully, then plug in the appropiate micro-controller and then load the .out file onto the board and the lights will start blinking.

This program works by having an infinite loop that counts down on a number and every time that count reaches a number divisible by a given value for each LED, that LED is toggled on/off, whichever is opposite its last state. Each board was slightly different in this because for the G2553 the LEDs were P1.0 and P1.6 whereas the P401R board was P1.0 and P2.0.
