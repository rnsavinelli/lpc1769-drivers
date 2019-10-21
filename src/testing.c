/*
===============================================================================
 Name        : testing.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
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
    	//ReceiveData();

    	SystemInterrupts();
    }

    return 0 ;
}
