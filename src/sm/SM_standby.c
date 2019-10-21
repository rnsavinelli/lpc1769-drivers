/*
 * SM_standby.c
 *
 *  Created on: 8 Oct 2019
 *      Author: rnsavinelli
 */

#include "SM_standby.h"

void SystemStandby(uint8_t status) {
	switch (status) {
		case RUNNING:
			break;

		case STOP:
			break;

		default:
			break;
	}

	return;
}
