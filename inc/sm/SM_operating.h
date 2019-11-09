/*
 * SM_operating.h
 *
 *  Created on: 8 Oct 2019
 *      Author: rnsavinelli (R. Nicolás Savinelli)
 */

#ifndef SM_OPERATING_H_
#define SM_OPERATING_H_

#include "DR_Variables.h"

/* SM STATUS */
#define RUNNING	1
#define STOP	0

void SystemOperating(uint8_t status);

#endif /* SM_OPERATING_H_ */
