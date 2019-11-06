/*
 * SM_system.c
 *
 *  Created on: 8 Oct 2019
 *      Author: rnsavinelli
 */

#include "SM_LPC1769.h"
#include "DR_LPC1769.h"
#include "PR_LPC1769.h"

uint8_t only_once = 1;
int8_t *ptr = "h";

uint8_t g_systemState = STANDBY;

void SystemInitialize(void) {
	/* Drivers */
	PLL_Initialize();
	SysTick_Initialize();
	Keyboard_Initialize();
	//NVIC_EINT_Enable(NVIC_EINT3, EXT_MODE_LEVEL, EXT_LEVEL_LOW);
	UARTn_Initialize(UART1);

	/* Primitives */
	Timers_Initialize();
	ALL_LEDS_Initialize();

	return;
}

void SystemConfigure(void) {
	g_systemState = STANDBY;
	return;
}

void SystemRun(void) {
	if (only_once) {
		SendData(1, ptr, 1);
		only_once = 0;
	}

	if (U0LSR & 0x20) {
		LED_ON(BLUE);
	}

    switch (g_systemState) {
    	case STANDBY:
    		SystemStandby(RUNNING);
    		if (GetKey() == EINT0) {
    			SystemStandby(STOP);
    			g_systemState = OPERATING;
    		}
    		break;

    	case INTERRUPTED:
    		break;

   		case OPERATING:
    		SystemOperating(RUNNING);
    		if (GetKey() == EINT0) {
    			SystemOperating(STOP);
    			g_systemState = STANDBY;
    		}
    		break;

    	default:
    		SystemConfigure();
			break;
    }

    return;
}

void SystemInterrupts(void) {
	if(flag_EXTINT0 == INTERRUPTED) {
		/* TODO: PERFORM INTERRUPTION */
		flag_EXTINT0 = NOT_INTERRUPTED;
	}

	if(flag_EXTINT1 == INTERRUPTED) {
		/* TODO: PERFORM INTERRUPTION */
		flag_EXTINT1 = NOT_INTERRUPTED;
	}

	if(flag_EXTINT2 == INTERRUPTED) {
		/* TODO: PERFORM INTERRUPTION */
		flag_EXTINT2 = NOT_INTERRUPTED;
	}

	if(flag_EXTINT3 == INTERRUPTED) {
		/* TODO: PERFORM INTERRUPTION */
		flag_EXTINT3 = NOT_INTERRUPTED;
	}

	return;
}
