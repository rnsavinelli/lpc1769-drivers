/*
 * PR_LEDS.h
 *
 *  Created on: 27 Sep 2019
 *      Author: rnsavinelli
 */

#ifndef PR_LEDS_H_
#define PR_LEDS_H_

#include "DR_Variables.h"

#define RED_LED_PIN		0, 22
#define GREEN_LED_PIN	3, 25
#define BLUE_LED_PIN	3, 26

#define RED			0
#define GREEN		1
#define BLUE 		2

void LED_Initialize (uint8_t colour);
void ALL_LEDS_Initialize (void);

void LED_ON (uint8_t colour);
void LED_OFF (uint8_t colour);

uint8_t LED_Status (uint8_t colour);

#endif /* PR_LEDS_H_ */
