/*
 * utils.c
 *
 *  Created on: Sep 13, 2024
 *      Author: karim
 */

#include <stm32l4xx_hal.h>
#include "utils.h"
#define ARRAY_SIZE 10
 void setup(void){
	 setvbuf(stdin, NULL, _IONBF, 0);
	 // Ce setup est indispensable au fonctionnement du scanf.
 }
 void displayArray(int array[ARRAY_SIZE]){
	 int i;
	 for (i=0;i<ARRAY_SIZE;i++){
		 printf("array[%d]=%d\n\r", i, array[i]);
	 }
 }
 void loop(void){
	 int array[ARRAY_SIZE]={0};
	 int index;
	 while (1){
		 scanf("%d", &index);
		 array[index]=1;
		 displayArray(array);
	 }
 }

