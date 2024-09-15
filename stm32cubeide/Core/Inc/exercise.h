/*
 * exercise.h
 *
 *  Created on: Sep 13, 2024
 *      Author: hachi
 */

#ifndef INC_EXERCISE_H_
#define INC_EXERCISE_H_

#include "main.h"

void timer0_run();
void timer1_run();
void timer2_run();

void disable7SEG();
void display7SEG(int num);
void update7SEG (int num);
void updateClockBuffer();

void disableMatrix();
void updateLEDMatrix(int index);
void displayROW(uint8_t state);

void shiftLeftWithWrap(uint8_t *matrix_buffer);
#endif /* INC_EXERCISE_H_ */
