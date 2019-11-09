/*
 * SM_blinking.h
 *
 *  Created on: 8 Oct 2019
 *      Author: rnsavinelli (R. Nicolás Savinelli)
 */

#ifndef SM_BLINKING_H_
#define SM_BLINKING_H_

#include "DR_Variables.h"

/* BLINKING STATUS */
#define RUN		1
#define STOP	0

/* LED STATUS */
#define IS_OFF		0
#define IS_ON		1
#define FIRST_RUN	2

void Blinking(uint8_t status);

#endif /* SM_BLINKING_H_ */
