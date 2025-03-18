/*
 * Main module for testing the PWM Code for the K64F
 * 
 * Author:  
 * Created:  
 * Modified: Carson Clarke-Magrab <ctc7359@rit.edu> 
 * LJBeato
 * 2021
 */

#include "msp.h"
#include "uart.h"
#include "TimerA.h"

/**
 * Waits for a delay (in milliseconds)
 * 
 * del - The delay in milliseconds
 */
void delay(int del){
	volatile int i;
	for (i=0; i<del*50000; i++){
		;// Do nothing
	}
}

int main(void) {
	// Initialize UART and PWM
	// INSERT CODE HERE
	uart0_init();

	// Print welcome over serial
	uart0_put("Running... \n\r");
	
	/* Part 1 - UNCOMMENT THIS
	// Generate 20% duty cycle at 10kHz
	// INSERT CODE HERE */
	TIMER_A0_PWM_Init(10000, 0.2, 1);
	TIMER_A0_PWM_Init(10000 , 0, 4);
	
	for(;;) {
		int forward = 1;
		int phase = 0;
		while (TRUE){
			// Turn off all coils , Set GPIO pins to 0
			// Set one pin high at a time
			if ( forward ) {
			if ( phase == 0) { /* turn on coil A */ ; phase ++;} // A ,1 a
			else if ( phase == 1) { /* turn on coil B */ ; phase ++;} // B ,2 a
			else if ( phase == 2) { /* turn on coil C */ ; phase ++;} // C ,1 b
			else { /* turn on coil D */ ; phase =0;} // D ,2 b
			}
			else { // reverse
			if ( phase == 0) { /* turn on coil D */ ; phase ++;} // D ,2 b
			else if ( phase == 1) { /* turn on coil C */ ; phase ++;} // C ,1 b
			else if ( phase == 2) { /* turn on coil B */ ; phase ++;} // B ,2 a
			else { /* turn on coil A */ ; phase =0;} // A ,1 a
			}
			// Note - you need to write your own delay function
			delay (10); // smaller values = faster speed
		}
	}
	
	return 0;
}



