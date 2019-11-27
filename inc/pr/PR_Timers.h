/*
 * PR_Timers.h
 *
 *  Created on: 27 Sep 2019
 *      Author: rnsavinelli (R. Nicolás Savinelli)
 */

#ifndef PR_TIMERS_H_
#define PR_TIMERS_H_

#include "DR_SysTick.h"

/* TIMER VARIABLE RELATED DEFINES */
#define MAX_TIMERS 8

/* TIMER MACROS */
#define TIMER0 0
#define TIMER1 1
#define TIMER2 2
#define TIMER3 3
#define TIMER4 4
#define TIMER5 5
#define TIMER6 6
#define TIMER7 7
#define TIMER8 8

/* HANDLER function variable type */
typedef void (*Timer_Handler)(void);

typedef struct timer {
	uint32_t time;
	uint8_t flag;
	Timer_Handler handler;
} timer_t;

#define TIMER_RESET 	0
#define TIMER_OFF	-1
#define TIMER_PAUSE	2
#define TIMER_RUNNING	0
#define TIMER_COMPLETED	1

#define INTERRUPTION_FREQUENCY 1

/* BASES FOR TIMER TIME */
#define SEG 0
#define MIN 1
#define MSEG 2

/* Global variables */
extern volatile timer_t g_timer[MAX_TIMERS];

/* Initialization of timer[] */
void Timers_Initialize(void);
void Timers_Daemon(void);

void TimerSet(uint8_t index, uint32_t time, Timer_Handler handler , uint8_t base);
void TimerStart(uint8_t index);
void TimerStop(uint8_t index);
void TimerPause(uint8_t index);
void TimerResume(uint8_t index);

uint32_t GetTimerTime(uint8_t index);
uint32_t GetTimerFlag(uint8_t index);

uint8_t TimerEvent(uint8_t index);

void TimerClear(uint8_t index);
void TimersClear(void);

#endif /* PR_TIMERS_H_ */
