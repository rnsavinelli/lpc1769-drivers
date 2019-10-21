/*
 * SM_system.h
 *
 *  Created on: 8 Oct 2019
 *      Author: rnsavinelli
 */

#ifndef SM_SYSTEM_H_
#define SM_SYSTEM_H_

#include "SM_system.h"
#include "DR_Variables.h"

/* SYSTEM STATES */
#define STANDBY		0
#define INTERRUPTED	1
#define OPERATING	2

/* SM STATUS */
#define RUNNING	1
#define STOP	0

extern uint8_t g_systemState;

void SystemInitialize(void);
void SystemConfigure(void);
void SystemRun(void);
void SystemInterrupts(void);

#endif /* SM_SYSTEM_H_ */
