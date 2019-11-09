/*
===============================================================================
 Name        : testing.c
 Author      : rnsavinelli (R. Nicolás Savinelli)
 Version     : 1.0
 License     : GPL-3.0
 Description : main file
===============================================================================
*/

#ifdef __USE_CMSIS
#include "LPC17xx.h"
#endif

#include <cr_section_macros.h>
#include "SM_system.h"

int main(void) {

	SystemInitialize();
	SystemConfigure();

    while(1) {
    	SystemRun();
    	SystemInterrupts();
    }

    return 0 ;
}
