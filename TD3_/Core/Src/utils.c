/*
 * utils.c
 *
 *  Created on: Oct 6, 2024
 *      Author: karim
 */
#include <stm32l4xx_hal.h>
#include "utils.h"
#include <stdio.h>
#define ARRAY_SIZE 15

int arrayTest[ARRAY_SIZE]={0, 1,-3, 10,-1, 0, 0, 0, 0, 12, 1024, 10, 45, 6, 4};

void setup()
{
	 int ignored[ARRAY_SIZE]={0};
	 int index,min;
	 getMinPosition(arrayTest, ignored, ARRAY_SIZE,&index,&min);
	 printf("First min at : %d \n\r",index);
	 ignored[index]=1;
	 getMinPosition(arrayTest, ignored, ARRAY_SIZE,&index,&min);
	 printf("Second min at : %d \n\r",index);
	 int sorted[ARRAY_SIZE]={0};
	 long start=HAL_GetTick();
	 sortArray(arrayTest, sorted, ARRAY_SIZE);
	 long stop=HAL_GetTick();
	 printf("Solved in %ld milliseconds\n\r", stop-start);
	 displayArray(sorted, ARRAY_SIZE);


}
void loop()
{


}
void getMinPosition(int * array, int * toBeIgnored, int size,int * index,int * min)
{
	int i;
	*index=-1;
    for (i = 0; i < size; i++)
    {
        if (toBeIgnored[i] != 1)
        {
            *min = array[i];
            *index = i;
            break;
        }
    }
    if (*index == -1)
    {
        return;
    }
	for (i=*index +1;i< size; i++ )
	{
		if((toBeIgnored[i]!=1)&&(array[i]<*min))
		{
			*min=array[i];
			*index=i;
		}
	}
}
int sortArray(int * toSort, int * sorted, int size)
{
	int sortedPosition[ARRAY_SIZE]={0};
	int i,min,index;
	for(i=0;i<size;i++)
	{
		getMinPosition(arrayTest,sortedPosition,ARRAY_SIZE,&index,&min);
		sortedPosition[index]=1;
		sorted[i]=min;
	}
		return 0;

}
void displayArray(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);  // Affiche chaque élément du tableau
    }
    printf("\n");  // Retour à la ligne après avoir affiché tous les éléments
}

