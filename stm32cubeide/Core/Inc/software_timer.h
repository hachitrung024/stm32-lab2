/*
 * software_timer.h
 *
 *  Created on: Nov 5, 2024
 *      Author: hachi
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

extern int timer0_flag;
void setTimer0(int duration);

extern int timer1_flag;
void setTimer1(int duration);

void timerRun();


#endif /* INC_SOFTWARE_TIMER_H_ */
