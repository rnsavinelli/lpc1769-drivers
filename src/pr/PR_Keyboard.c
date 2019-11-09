/*
 * PR_Keyboard.c
 *
 *  Created on: 5 Oct 2019
 *      Author: rnsavinelli (R. Nicolás Savinelli)
 */

#include "DR_Keyboard.h"
#include "PR_Keyboard.h"
#include "DR_Variables.h"

uint8_t GetKey (void) {
	uint8_t key = NO_KEY;

	if (g_keyboardBuffer != NO_KEY) {
		key = g_keyboardBuffer;
		g_keyboardBuffer = NO_KEY;
	}

	return key;
}

