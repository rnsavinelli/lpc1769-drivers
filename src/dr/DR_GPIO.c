/*
 * DR_GPIO.c
 *
 *  Created on: 27 Sep 2019
 *      Author: rnsavinelli (R. Nicolás Savinelli)
 */

#include "DR_GPIO.h"
#include "DR_Variables.h"

#define PINS_PER_REGISTER 16

/* IF NOMENCLATURE NOT CLEAR SEE: DR_GPIO.h*/

/* SETS PIN DIRECTION: INPUT / OUTPUT */
void SetDIR (uint8_t port, uint8_t pin, uint8_t dir) {
	if (dir == INPUT) {
		GPIO[8 * port] &= ~(1 << pin);
	}

	/* DEFAULTS TO OUTPUT */
	else {
		GPIO[8 * port] |= (1 << pin);
	}
}

void SetMODE (uint8_t port, uint8_t pin, uint8_t mode) {
	uint32_t index = 2 * port;

	if (pin >= PINS_PER_REGISTER) {
		index++;
		pin = pin - PINS_PER_REGISTER;
	}

	/* Since each PINMODE gets configure using 2 bits shifting
	 * the pin twice is needed before cleaning the register
	 * and turning the bits on */
	GPIO[index] &= ~(0x03 << (2 * pin));
	GPIO[index] |= (mode << (2 * pin));
}

/* SETS PIN TO HIGH OR LOW */
void SetPIN(uint8_t port, uint8_t pin, uint8_t state)
{
	/* SETS THE PIN TO HIGH USING THE FIOPIN REGISTER */
    if (state == HIGH) {
    	GPIO[5 + 8 * port] |= (1 << pin);
    }

    /* DEFAULTS TO LOW USING THE FIOPIN REGISTER */
    else{
        GPIO[5 + 8 * port] &= ~(1 << pin);
    }
}

/* SETS PIN TO HIGH OR LOW (LEGACY FUNCTION) */
void SetPIN_ALT (uint8_t port, uint8_t pin, uint8_t state) {
	/* SETS THE PIN TO HIGH USING THE FIOSET REGISTER */
	if (state == HIGH) {
		GPIO[6 + (8 * port)] |= (TRUE << pin);
	}

	/* DEFAULTS TO LOW USING THE FIOCLR REGISTER */
	else {
		GPIO[7 + (8 * port)] |= (TRUE << pin);
	}
}

/* RETURNS CURRENT PIN STATE USING FIOPIN */
uint8_t GetPIN (uint8_t port, uint8_t pin) {
	/* Returns one or zero */
	return (( GPIO[5 + 8 * port] & ( 1 << pin ) ) >> pin);
}
