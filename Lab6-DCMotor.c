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
	int forward = 1;
	int phase = 0;
	// Initialize UART and PWM
	// INSERT CODE HERE
	uart0_init();

	// Print welcome over serial
	// uart0_put("Running... \n\r");
	
	/* Part 1 - UNCOMMENT THIS
	// Generate 20% duty cycle at 10kHz
	// INSERT CODE HERE */
	// TIMER_A0_PWM_Init(10000, 0.2, 1);
	// TIMER_A0_PWM_Init(10000 , 0, 4);

	P4->SEL0 &= ~BIT1;
	P4->SEL1 &= ~BIT1;
	P4->SEL0 &= ~BIT2;
	P4->SEL1 &= ~BIT2;
	P4->SEL0 &= ~BIT3;
	P4->SEL1 &= ~BIT3;
	P4->SEL0 &= ~BIT4;
	P4->SEL1 &= ~BIT4;
	
	P4->DIR |= BIT1;
	P4->DIR |= BIT2;
	P4->DIR |= BIT3;
	P4->DIR |= BIT4;

	while (TRUE){
		// Turn off all coils , Set GPIO pins to 0
		P4->OUT &= ~BIT1;
		P4->OUT &= ~BIT2;
		P4->OUT &= ~BIT3;
		P4->OUT &= ~BIT4;

		// Set one pin high at a time
		if ( forward ) {
		if ( phase == 0) { /* turn on coil A */ P4->OUT |= BIT1; phase ++; uart0_put("Phase1\r\n"); } // A ,1 a
		else if ( phase == 1) { /* turn on coil B */ P4->OUT |= BIT2; phase++; uart0_put("Phase2\r\n"); } // B ,2 a
		else if ( phase == 2) { /* turn on coil C */ P4->OUT |= BIT3; phase++; uart0_put("Phase3\r\n"); } // C ,1 b
		else { /* turn on coil D */ P4->OUT |= BIT4; phase = 0; uart0_put("Phase4\r\n");} // D ,2 b
		}
		//else { // reverse
		//if ( phase == 0) { /* turn on coil D */ P4->OUT |= BIT4; phase ++;} // D ,2 b
		//else if ( phase == 1) { /* turn on coil C */ P4->OUT |= BIT3; phase ++;} // C ,1 b
		//else if ( phase == 2) { /* turn on coil B */ P4->OUT |= BIT2; phase ++;} // B ,2 a
		//else { /* turn on coil A */ P4->OUT |= BIT1; phase =0;} // A ,1 a
		//}
		// Note - you need to write your own delay function
		delay(5); // smaller values = faster speed
	}
}



