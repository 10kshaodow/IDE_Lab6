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
	uint16_t period = SystemCoreClock / 10000;
	uart0_init();

	// Print welcome over serial
	uart0_put("Running... \n\r");
	
	/* Part 1 - UNCOMMENT THIS
	// Generate 20% duty cycle at 10kHz
	// INSERT CODE HERE */
	TIMER_A0_PWM_Init(period, 0.2, 1);
	TIMER_A0_PWM_Init(period , 10, 4);
	TIMER_A0_PWM_Init(period , 0.2, 2);
	TIMER_A0_PWM_Init(period , 10, 3);
	TIMER_A2_PWM_Init(50, (1-0.075), 1); // 50Hz frequency, 7.5% duty cycle (1.5ms pulse width)

	for(;;)  //loop forever
	{
		// Change the pulse width back to 1.5ms (7.5% duty cycle)
		//TIMER_A2_PWM_DutyCycle(1-0.075, 1);
		//delay(1);

		// Uncomment below for second signoff
		
		// Change the pulse width to 2ms (10% duty cycle)
		//TIMER_A2_PWM_DutyCycle(1-0.1, 1);
		//delay(1);

		// Change the pulse width to 1ms (5% duty cycle)
		//TIMER_A2_PWM_DutyCycle(1-0.05, 1);
		//delay(1);
	}

	return 0;
}



