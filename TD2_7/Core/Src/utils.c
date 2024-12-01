/*
 * utils.c
 *
 *  Created on: Sep 13, 2024
 *      Author: karim
 */

#include <stm32l4xx_hal.h>
#include "utils.h"
#define ARRAY_SIZE 20
void setup(){

}
void fillArray(int * array, int size){
	 int i;
	 for (i=0;i<ARRAY_SIZE;i++){
		 printf("array[%d]=%d\n\r", i, array[i]);
	 }
GPIO_PinState PinState;
int i=0;
int j=0;

int array[ARRAY_SIZE]={0};
int index;
void loop(){
	    PinState = HAL_GPIO_ReadPin( GPIOC, GPIO_PIN_13);
	    if ( PinState == 0 )
	    {
	    	HAL_GPIO_WritePin( GPIOA, GPIO_PIN_5, 1);
	    	i=HAL_GetTick();
	    	array[j]=i;

	    	fillArray(array);
	    	j++;



	    }
	    else
	    {
	    	HAL_GPIO_WritePin( GPIOA, GPIO_PIN_5, 0);

	    }

}
