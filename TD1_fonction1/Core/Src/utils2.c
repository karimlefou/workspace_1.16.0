/*
 * utils.c
 *
 *  Created on: Sep 13, 2024
 *      Author: karim
 */

#include <stm32l4xx_hal.h>
#include "utils.h"

void setup1(){

}

void loop1(){
    // This code will run indefinitly.
	static int status_led=0;
	static int compteur=0;

	while(HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_13)==1){
	}
	status_led=1-status_led;
	compteur++;
	printf("Compteur = %d, led=%d \n\r",compteur,status_led);
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5,status_led);
	while(HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_13)==0){
	}



 //   HAL_UART_Transmit(&huart2,"Test \n\r",8,-1);
}
