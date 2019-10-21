/*
 * SM_operating.c
 *
 *  Created on: 8 Oct 2019
 *      Author: rnsavinelli
 */

#include "SM_operating.h"
#include "SM_blinking.h"

void SystemOperating(uint8_t status) {
	switch (status) {
		case RUNNING:
			Blinking(RUN);
			break;

		case STOP:
			Blinking(STOP);
			break;

		default:
			break;
	}

	return;
}
