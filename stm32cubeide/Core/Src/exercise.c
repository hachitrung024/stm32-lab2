/*
 * exercise.c
 *
 *  Created on: Sep 13, 2024
 *      Author: hachi
 */

#include "exercise.h"
const int MAX_LED = 4;
int index_led = 0;
int led_buffer [4] = {1, 2, 3, 4};
int hour = 15, minute = 8, second = 50;
void timer0_run(){
	second++;
	if ( second >= 60) {
	  second = 0;
	  minute ++;
	}
	if( minute >= 60) {
	  minute = 0;
	  hour ++;
	}
	if( hour >=24){
	  hour = 0;
	}
	updateClockBuffer();
	HAL_GPIO_TogglePin(DOT_GPIO_Port, DOT_Pin);
}
void timer1_run(){
	if(index_led >= 0){
		if(index_led >3) index_led =0;
		update7SEG(index_led++);
	}
}
void updateClockBuffer(){
	led_buffer[0] = hour/10;
	led_buffer[1] = hour%10;
	led_buffer[2] = minute/10;
	led_buffer[3] = minute%10;
}
void update7SEG (int num){
	switch (num) {
		case 0:
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, RESET);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
			display7SEG(led_buffer[0]);
			break;
		case 1:
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET);
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
			display7SEG(led_buffer[1]);
			break;
		case 2:
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, RESET);
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
			display7SEG(led_buffer[2]);
			break;
		case 3:
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, RESET);
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
			display7SEG(led_buffer[3]);
			break;
		default:
			break;
	}
}
void display7SEG(int num){
  switch(num){
  case 0:
	  HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, RESET);
	  HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, RESET);
	  HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET);
	  HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, RESET);
	  HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, RESET);
	  HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, RESET);
	  HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, SET);
	  break;
  case 1:
	  HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, SET);
	  HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, RESET);
	  HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET);
	  HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, SET);
	  HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, SET);
	  HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, SET);
	  HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, SET);
	  break;
  case 2:
	  HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, RESET);
	  HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, RESET);
	  HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, SET);
	  HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, RESET);
	  HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, RESET);
	  HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, SET);
	  HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, RESET);
	  break;
  case 3:
	  HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, RESET);
	  HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, RESET);
	  HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET);
	  HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, RESET);
	  HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, SET);
	  HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, SET);
	  HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, RESET);
	  break;
  case 4:
	  HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, SET);
	  HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, RESET);
	  HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET);
	  HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, SET);
	  HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, SET);
	  HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, RESET);
	  HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, RESET);
	  break;
  case 5:
	  HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, RESET);
	  HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, SET);
	  HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET);
	  HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, RESET);
	  HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, SET);
	  HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, RESET);
	  HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, RESET);
	  break;
  case 6:
	  HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, RESET);
	  HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, SET);
	  HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET);
	  HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, RESET);
	  HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, RESET);
	  HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, RESET);
	  HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, RESET);
	  break;
  case 7:
	  HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, RESET);
	  HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, RESET);
	  HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET);
	  HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, SET);
	  HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, SET);
	  HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, SET);
	  HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, SET);
	  break;
  case 8:
	  HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, RESET);
	  HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, RESET);
	  HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET);
	  HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, RESET);
	  HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, RESET);
	  HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, RESET);
	  HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, RESET);
	  break;
  case 9:
	  HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, RESET);
	  HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, RESET);
	  HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET);
	  HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, RESET);
	  HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, SET);
	  HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, RESET);
	  HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, RESET);
	  break;
  default:
	  HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, SET);
	  HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, SET);
	  HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, SET);
	  HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, SET);
	  HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, SET);
	  HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, SET);
	  HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, SET);
	  break;
  }
}
