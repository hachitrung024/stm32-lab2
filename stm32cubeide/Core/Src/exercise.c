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

const int MAX_LED_MATRIX = 8;
int index_led_matrix = 0;
uint8_t matrix_buffer[8] = {0x18,0x3C,0x66,0x66,0x7E,0x7E,0x66,0x66};
//{0x00,0x66,0xFF,0xFF,0x7E,0x3C,0x18,0x00};

void timer0_run(){

}
void timer1_run(){
	shiftLeftWithWrap(matrix_buffer);
}
void timer2_run(){
	if(index_led_matrix >= 0){
		if(index_led_matrix >= MAX_LED_MATRIX) index_led_matrix =0;
		updateLEDMatrix(index_led_matrix++);
	}
}

void disableMatrix(){
	HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin, SET);
	HAL_GPIO_WritePin(ENM1_GPIO_Port, ENM1_Pin, SET);
	HAL_GPIO_WritePin(ENM2_GPIO_Port, ENM2_Pin, SET);
	HAL_GPIO_WritePin(ENM3_GPIO_Port, ENM3_Pin, SET);
	HAL_GPIO_WritePin(ENM4_GPIO_Port, ENM4_Pin, SET);
	HAL_GPIO_WritePin(ENM5_GPIO_Port, ENM5_Pin, SET);
	HAL_GPIO_WritePin(ENM6_GPIO_Port, ENM6_Pin, SET);
	HAL_GPIO_WritePin(ENM7_GPIO_Port, ENM7_Pin, SET);
}
void updateLEDMatrix(int index){
	switch (index) {
		case 0:
			disableMatrix();
			HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin, RESET);
			displayROW(0x80);
			break;
		case 1:
			disableMatrix();
			HAL_GPIO_WritePin(ENM1_GPIO_Port, ENM1_Pin, RESET);
			displayROW(0x40);
			break;
		case 2:
			disableMatrix();
			HAL_GPIO_WritePin(ENM2_GPIO_Port, ENM2_Pin, RESET);
			displayROW(0x20);
			break;
		case 3:
			disableMatrix();
			HAL_GPIO_WritePin(ENM3_GPIO_Port, ENM3_Pin, RESET);
			displayROW(0x10);
			break;
		case 4:
			disableMatrix();
			HAL_GPIO_WritePin(ENM4_GPIO_Port, ENM4_Pin, RESET);
			displayROW(0x08);
			break;
		case 5:
			disableMatrix();
			HAL_GPIO_WritePin(ENM5_GPIO_Port, ENM5_Pin, RESET);
			displayROW(0x04);
			break;
		case 6:
			disableMatrix();
			HAL_GPIO_WritePin(ENM6_GPIO_Port, ENM6_Pin, RESET);
			displayROW(0x02);
			break;
		case 7:
			disableMatrix();
			HAL_GPIO_WritePin(ENM7_GPIO_Port, ENM7_Pin, RESET);
			displayROW(0x01);

			break;
		default:
			disableMatrix();
			break;
	}
}
void displayROW(uint8_t state){
	HAL_GPIO_WritePin(ROW0_GPIO_Port, ROW0_Pin, (state & matrix_buffer[0]) ? RESET : SET);
	HAL_GPIO_WritePin(ROW1_GPIO_Port, ROW1_Pin, (state & matrix_buffer[1]) ? RESET : SET);
	HAL_GPIO_WritePin(ROW2_GPIO_Port, ROW2_Pin, (state & matrix_buffer[2]) ? RESET : SET);
	HAL_GPIO_WritePin(ROW3_GPIO_Port, ROW3_Pin, (state & matrix_buffer[3]) ? RESET : SET);
	HAL_GPIO_WritePin(ROW4_GPIO_Port, ROW4_Pin, (state & matrix_buffer[4]) ? RESET : SET);
	HAL_GPIO_WritePin(ROW5_GPIO_Port, ROW5_Pin, (state & matrix_buffer[5]) ? RESET : SET);
	HAL_GPIO_WritePin(ROW6_GPIO_Port, ROW6_Pin, (state & matrix_buffer[6]) ? RESET : SET);
	HAL_GPIO_WritePin(ROW7_GPIO_Port, ROW7_Pin, (state & matrix_buffer[7]) ? RESET : SET);
}

void disable7SEG(){
	HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
	HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
	HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
	HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
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
			disable7SEG();
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, RESET);
			display7SEG(led_buffer[0]);
			break;
		case 1:
			disable7SEG();
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET);
			display7SEG(led_buffer[1]);
			break;
		case 2:
			disable7SEG();
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, RESET);
			display7SEG(led_buffer[2]);
			break;
		case 3:
			disable7SEG();
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, RESET);
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
void shiftLeftWithWrap(uint8_t *matrix_buffer) {
    for (int i = 0; i < 8; i++) {
        // Lấy bit trái nhất của hàng
        uint8_t left_most_bit = (matrix_buffer[i] & 0x80) >> 7;
        // Dịch bit sang trái và đưa bit trái nhất về bên phải
        matrix_buffer[i] = (matrix_buffer[i] << 1) | left_most_bit;
    }
}
