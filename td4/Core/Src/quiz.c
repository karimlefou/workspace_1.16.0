/*
 * quiz.c
 *
 *  Created on: Oct 7, 2024
 *      Author: karim
 */

#include <stm32l4xx_hal.h>
#include "quiz.h"
#define ARRAY_SIZE 15

int arrayTest[ARRAY_SIZE]={0, 1,-3, 10,-1, 0, 0, 0, 0, 12, 1024, 10, 45, 6, 4};

void setup2()
{
	tri_insertion(arrayTest,ARRAY_SIZE);
	displayArray(arrayTest,ARRAY_SIZE);

}
void  tri_insertion(int * array, int size )
{
	int i,x;
	for(i=1;i<size;i++)
	{
		x=array[i];
		int j=i;
		while (j>0 && array[j-1]>x )
		{
			array[j]=array[j-1];
			j=j-1;
		}
		array[j]=x;


	}

}
void displayArray(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);  // Affiche chaque élément du tableau
    }
    printf("\n");  // Retour à la ligne après avoir affiché tous les éléments
}
void loop2()
{

}
