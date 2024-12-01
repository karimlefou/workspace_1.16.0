/*
 * utils.c
 *
 *  Created on: Sep 13, 2024
 *      Author: karim
 */

#include <stm32l4xx_hal.h>
#include "utils.h"

void setup(){

}
int i=1;
void loop(){
	  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5,GPIO_PIN_RESET);
	  printf("clignot %d \r\n", i);
	  HAL_Delay(250);
	  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5,GPIO_PIN_SET);
	  HAL_Delay(250);
	  i=i+1;
}
