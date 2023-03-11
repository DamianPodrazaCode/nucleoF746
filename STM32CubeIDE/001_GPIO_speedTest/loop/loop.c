/*
 * loop.c
 *
 *  Created on: Mar 9, 2023
 *      Author: ZoMbiE
 */

#include "loop.h"

void setup() {
}

void loop() {
//	HAL_GPIO_TogglePin(TEST_GPIO_Port, TEST_Pin);  // 145ns
//	HAL_GPIO_TogglePin(TEST_GPIO_Port, TEST_Pin);
//	HAL_GPIO_TogglePin(TEST_GPIO_Port, TEST_Pin);
//	HAL_GPIO_TogglePin(TEST_GPIO_Port, TEST_Pin);

//	HAL_GPIO_WritePin(TEST_GPIO_Port, TEST_Pin, 0); // 120ns
//	HAL_GPIO_WritePin(TEST_GPIO_Port, TEST_Pin, 1);
//	HAL_GPIO_WritePin(TEST_GPIO_Port, TEST_Pin, 0);
//	HAL_GPIO_WritePin(TEST_GPIO_Port, TEST_Pin, 1);
//	HAL_GPIO_WritePin(TEST_GPIO_Port, TEST_Pin, 0);
//	HAL_GPIO_WritePin(TEST_GPIO_Port, TEST_Pin, 1);

	TEST_GPIO_Port->BSRR |= TEST_Pin;			//45ns
	TEST_GPIO_Port->BSRR |= TEST_Pin << 16;
	TEST_GPIO_Port->BSRR |= TEST_Pin;
	TEST_GPIO_Port->BSRR |= TEST_Pin << 16;
	TEST_GPIO_Port->BSRR |= TEST_Pin;
	TEST_GPIO_Port->BSRR |= TEST_Pin << 16;
	TEST_GPIO_Port->BSRR |= TEST_Pin;
	TEST_GPIO_Port->BSRR |= TEST_Pin << 16;
}


