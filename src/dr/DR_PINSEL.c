/*
 * DR_PINSEL.c
 *
 *  Created on: 27 Sep 2019
 *      Author: rnsavinelli (R. Nicolás Savinelli)
 */

#include "DR_PINSEL.h"
#include "DR_Variables.h"

#define PINS_PER_REGISTER 16

void SetPINSEL( uint8_t port, uint8_t pin, uint8_t function) {
	uint32_t index = 2 * port;
	/* Each port ranges from 0 to 31. For every port we have two
	 * PINSEL register (thus index = 2 * port). If the pin is
	 * greater or equal than PINS_PER_REGISTER then we need to
	 * increment the index to suit its "upper" PINSEL.
	 *
	 * PINSEL[0] takes care of PINS 0 to 15 from PORT0
	 * PINSEL[1] takes care of PINS 16 to 31 from PORT0
	 * And so on...
	 */

	if(pin >= PINS_PER_REGISTER) {
		index++;
		pin = pin - PINS_PER_REGISTER;
	}

	/* Since each PINSEL gets configure using 2 bits shifting
	 * the pin twice is needed before cleaning the register
	 * and turning the bits on */
	PINSEL[index] &= ~(0x03 << (2 * pin));
	PINSEL[index] |= (function << (2 * pin));
}
