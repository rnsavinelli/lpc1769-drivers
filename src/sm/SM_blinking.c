/*
 * SM_blinking.c
 *
 *  Created on: 8 Oct 2019
 *      Author: rnsavinelli (R. Nicolás Savinelli)
 */

#include "SM_blinking.h"
#include "PR_LPC1769.h"

void Blinking(uint8_t status) {
	// Avoids using a global variable
	static volatile uint8_t led_state = FIRST_RUN;

	if (status == RUN)	{
		switch (led_state) {
			case IS_OFF:
				if(GetTimerFlag(TIMER0) == TIMER_COMPLETED){
					LED_ON(RED);
					TimerSet(TIMER0, 1, NULL, SEG);
					TimerStart(TIMER0);
					led_state = IS_ON;
				}
				break;

			case IS_ON:
				if(GetTimerFlag(TIMER0) == TIMER_COMPLETED){
					LED_OFF(RED);
					TimerSet(TIMER0, 1, NULL, SEG);
					TimerStart(TIMER0);
					led_state = IS_OFF;
				}
				break;

			/* FIRST TIME */
			case FIRST_RUN:
				LED_ON(RED);
				TimerSet(TIMER0, 1, NULL, SEG);
				TimerStart(TIMER0);
				led_state = IS_ON;
				break;

			/* SAME AS BLINKING(STOP) */
			default:
				TimerClear(TIMER0);
				LED_OFF(RED);
				led_state = FIRST_RUN;
		}
	}

	else if (status == STOP){
		TimerClear(TIMER0);
		LED_OFF(RED);
		led_state = FIRST_RUN;
	}

	return;
}
