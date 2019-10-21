/*
 * SM_standby.h
 *
 *  Created on: 8 Oct 2019
 *      Author: rnsavinelli
 */

#ifndef SM_STANDBY_H_
#define SM_STANDBY_H_

#include "DR_Variables.h"

/* SM STATUS */
#define RUNNING	1
#define STOP	0

void SystemStandby(uint8_t status);

#endif /* SM_STANDBY_H_ */
