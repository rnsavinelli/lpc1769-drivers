/*
 * DR_Keyboard.c
 *
 *  Created on: 3 Oct 2019
 *      Author: rnsavinelli
 */

#include "DR_Keyboard.h"
#include "DR_PINSEL.h"
#include "DR_GPIO.h"

volatile uint8_t g_keyboardBuffer;

void Keyboard_Initialize(void) {
	g_keyboardBuffer = NO_KEY;

	/* EINT0 BUTTON */
	SetPINSEL(EINT0_PIN, PINSEL_GPIO);
	SetMODE(EINT0_PIN, PULLUP);
	SetDIR(EINT0_PIN, INPUT);

	/* EINT1 BUTTON */
	SetPINSEL(EINT1_PIN, PINSEL_GPIO);
	SetMODE(EINT1_PIN, PULLUP);
	SetDIR(EINT1_PIN, INPUT);

	/* EINT2 BUTTON */
	SetPINSEL(EINT2_PIN, PINSEL_GPIO);
	SetMODE(EINT2_PIN, PULLUP);
	SetDIR(EINT2_PIN, INPUT);

	/* EINT3 BUTTON */
	SetPINSEL(EINT3_PIN, PINSEL_GPIO);
	SetMODE(EINT3_PIN, PULLUP);
	SetDIR(EINT3_PIN, INPUT);

	return;
}

/* If the key is pressed returns the key identifier */
/* NOT THE VALUE */
uint8_t KeyPressed(void) {
	uint8_t status = NO_KEY;

	if(LOW == GetPIN(EINT0_PIN)) {
		status = EINT0;
	}

	if(LOW == GetPIN(EINT1_PIN)) {
		status = EINT1;
	}

	if(LOW == GetPIN(EINT2_PIN)) {
		status = EINT2;
	}

	if(LOW == GetPIN(EINT3_PIN)) {
		status = EINT3;
	}

	return status;
}

void Keyboard_Daemon(void) {
	static uint8_t last_key = NO_KEY;
	static uint8_t count;
	uint8_t key;

	key = KeyPressed();

	if(key == last_key && count < DEBOUNCE_COUNT) {
		count++;

		if (count == DEBOUNCE_COUNT){
			g_keyboardBuffer = key;
		}
	}

	else if (key != last_key){
		count = 0;
	}

	last_key = key;
}

