/*
 * DR_NVIC.c
 *
 *  Created on: 5 Oct 2019
 *      Author: rnsavinelli (R. Nicolás Savinelli)
 */

#include "DR_NVIC.h"
#include "DR_Keyboard.h"
#include "DR_GPIO.h"
#include "DR_PINSEL.h"
#include "DR_Variables.h"

uint8_t flag_EXTINT0 = NOT_INTERRUPTED;
uint8_t flag_EXTINT1 = NOT_INTERRUPTED;
uint8_t flag_EXTINT2 = NOT_INTERRUPTED;
uint8_t flag_EXTINT3 = NOT_INTERRUPTED;

void NVIC_EINT_Enable(uint8_t interrupt, uint8_t mode, uint8_t polarity) {
	/* Sets up the pin responsible for triggering the interruption */
	switch (interrupt) {
		case NVIC_EINT0:
			SetPINSEL(EINT0_PIN, PINSEL_ALT1);
			break;
		case NVIC_EINT1:
			SetPINSEL(EINT1_PIN, PINSEL_ALT1);
			break;
		case NVIC_EINT2:
			SetPINSEL(EINT2_PIN, PINSEL_ALT1);
			break;
		case NVIC_EINT3:
			SetPINSEL(EINT3_PIN, PINSEL_ALT1);
			break;
		default:
			/* if interrupt is not an External Interrupt the quit */
			return;
	}

	if (mode == EXT_MODE_EDGE) {
		EXTMODE |= 1 << (interrupt - NVIC_EINT0);
	}

	else if (mode == EXT_MODE_LEVEL) {
		EXTMODE &= ~( 1 << (interrupt - NVIC_EINT0));
	}

	if ((polarity == EXT_LEVEL_HIGH) || (polarity == EXT_EDGE_RISING)) {
		EXTPOLAR |= 1 << (interrupt - NVIC_EINT0);
	}

	if ((polarity == EXT_LEVEL_LOW) || (polarity == EXT_EDGE_FALLING)) {
		EXTPOLAR &= ~( 1 << (interrupt - NVIC_EINT0));
	}

	ISER[0] |= (1 << interrupt);

	return;
}

void NVIC_Enable(uint8_t interrupt) {
	ISER[0] |= (1 << interrupt);
	return;
}

void NVIC_Disable(uint8_t interrupt) {
	ICER[0] |= (1 << interrupt);
	return;
}

/* EINTx_IRQHandlers */
void EINT0_IRQHandler(void) {
	EXTINT |= (1 << 0);
	flag_EXTINT0 = INTERRUPTED;
	return;
}

void EINT1_IRQHandler(void) {
	EXTINT |= (1 << 1);
	flag_EXTINT1 = INTERRUPTED;
	return;
}

void EINT2_IRQHandler(void) {
	EXTINT |= (1 << 2);
	flag_EXTINT2 = INTERRUPTED;
	return;
}

void EINT3_IRQHandler(void) {
	EXTINT |= (1 << 3);
	flag_EXTINT3 = INTERRUPTED;
	return;
}
