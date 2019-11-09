/*
 * PR_LEDS.c
 *
 *  Created on: 27 Sep 2019
 *      Author: rnsavinelli (R. Nicolás Savinelli)
 */

#include "PR_LEDS.h"
#include "DR_GPIO.h"
#include "DR_PINSEL.h"

/* A FLAG FOR EACH INDIVIDUAL COLOUR TO AVOID NON INITIALIZED LEDS */
static uint8_t LED_FLAG[3] = {FALSE, FALSE, FALSE};

void LED_Initialize (uint8_t colour) {
	switch (colour) {
		case RED:
			SetPINSEL(RED_LED_PIN, PINSEL_GPIO);
			SetDIR(RED_LED_PIN, OUTPUT);
			SetPIN(RED_LED_PIN, HIGH);
			LED_FLAG[colour] = TRUE;
			break;

		case GREEN:
			SetPINSEL(GREEN_LED_PIN, PINSEL_GPIO);
			SetDIR(GREEN_LED_PIN, OUTPUT);
			SetPIN(GREEN_LED_PIN, HIGH);
			LED_FLAG[colour] = TRUE;
			break;

		case BLUE:
			SetPINSEL(BLUE_LED_PIN, PINSEL_GPIO);
			SetDIR(BLUE_LED_PIN, OUTPUT);
			SetPIN(BLUE_LED_PIN, HIGH);
			LED_FLAG[colour] = TRUE;
			break;
	}
}

void ALL_LEDS_Initialize (void) {
	for(uint8_t i = 0; i < 3; i++){
		LED_Initialize(i);
	}
}

void LED_ON  (uint8_t colour) {
	if (LED_FLAG[colour] == FALSE && colour >= RED && colour <= BLUE) {
		LED_Initialize(colour);
	}

	if (colour == RED) {
		SetPIN(RED_LED_PIN, LOW);
	}

	else if (colour == GREEN) {
		SetPIN(GREEN_LED_PIN, LOW);
	}

	else if (colour == BLUE) {
		SetPIN(BLUE_LED_PIN, LOW);
	}
}

void LED_OFF (uint8_t colour) {
	if (LED_FLAG[colour] == FALSE && colour >= RED && colour <= BLUE) {
		LED_Initialize(colour);
	}

	if (colour == RED) {
		SetPIN(RED_LED_PIN, HIGH);
	}

	else if (colour == GREEN) {
		SetPIN(GREEN_LED_PIN, HIGH);
	}

	else if (colour == BLUE) {
		SetPIN(BLUE_LED_PIN, HIGH);
	}
}

uint8_t LED_Status (uint8_t colour) {
	if (colour == RED) {
	    return GetPIN(RED_LED_PIN);
	}

	else if (colour == GREEN) {
		return GetPIN(GREEN_LED_PIN);
	}

	else if (colour == BLUE) {
		return GetPIN(BLUE_LED_PIN);
	}
	
	else {
	    /* DEFAULTS TO -1 IF COLOUR IS NOT VALID*/
	    return -1;
	}
}
