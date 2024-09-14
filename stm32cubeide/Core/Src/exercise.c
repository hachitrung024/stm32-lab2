/*
 * exercise.c
 *
 *  Created on: Sep 13, 2024
 *      Author: hachi
 */

#include "exercise.h"
void timer0_run(){
	HAL_GPIO_TogglePin(DOT_GPIO_Port, DOT_Pin);
}
void timer1_run(){
	HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, RESET);
	HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
	HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
	HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
	display7SEG(1);
}
void timer2_run(){
	HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
	HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET);
	HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
	HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
	display7SEG(2);
}
void timer3_run(){
	HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
	HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
	HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, RESET);
	HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
	display7SEG(3);
}
void timer4_run(){
	HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
	HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
	HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
	HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, RESET);
	display7SEG(0);
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
