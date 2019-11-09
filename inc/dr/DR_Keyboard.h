/*
 * DR_Keyboard.h
 *
 *  Created on: 3 Oct 2019
 *      Author: rnsavinelli (R. Nicolás Savinelli)
 */

#ifndef DR_KEYBOARD_H_
#define DR_KEYBOARD_H_

#include "DR_Variables.h"

/* Frequently used keys */
#define		EINT0_PIN		2, 10
#define		EINT1_PIN		0, 18
#define		EINT2_PIN		0, 11
#define		EINT3_PIN		2, 13

#define DEBOUNCE_COUNT 5

#define NO_KEY 0
#define EINT0	1
#define EINT1	2
#define EINT2	3
#define EINT3	4

extern volatile uint8_t g_keyboardBuffer;

void Keyboard_Initialize(void);

/* Deals with electric noise and key input */
void Keyboard_Daemon(void);

/* Returns the identifier of the key that was pressed */
uint8_t KeyPressed(void);

#endif /* DR_KEYBOARD_H_ */
