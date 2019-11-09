/*
 * DR_SysTick.c
 *
 *  Created on: 22 Sep 2019
 *      Author: rnsavinelli (R. Nicolás Savinelli)
 */

#include "DR_SysTick.h"
#include "PR_LPC1769.h"
#include "DR_LPC1769.h"

/* Timer for interruptions */

void SysTick_Initialize(void) {
    /* Initially disabled for a cleaner SysTick start */
    STCTRL = SysTick_CTRL_DISABLE;
    /* Sets reload register with STCALIB = 10 ms */
	STRELOAD = (STCALIB+1)/10 - 1;
	/* Resets the SysTick counter value since it has a random value on reset */
	STCURR = 0;

	/* Selects processor clock: 1 = processor clock; 0 = external clock */
	// STCTRL |= SysTick_CTRL_CLKSOURCE;
	/* Enables SysTick interrupt: 1 = enable; 0 = disable */
	// STCTRL |= SysTick_CTRL_TICKINT;
	/* Enable SysTick */
	// STCTRL |= SysTick_CTRL_ENABLE;

	/* Does all the steps mentioned above in one operation */
	STCTRL |= SysTick_CTRL_ENABLE_ALL;
}

void SysTick_Handler(void) {
	Timers_Daemon();
	Keyboard_Daemon();
}
