/*
 * utils.c
 *
 *  Created on: Sep 27, 2024
 *      Author: karim
 */

#include <stm32l4xx_hal.h>
#include "utils.h"
#define ARRAY_SIZE 20


void setup()
{
	int i ;
    int array[ARRAY_SIZE];
    int min , max;
    float moy;
    for (i=0;i<ARRAY_SIZE;i++)
    {
    array[i]=i;
    }
    caracArray(array,&min,&max,&moy);
    dispCaracArray(min, max, moy);

}
void caracArray(int array[ARRAY_SIZE],int* pmin, int* pmax, float* pmoy)
{
	int i;
	int s =0;
	*pmin=array[0];
	*pmax=array[0];
	for (i=0;i<ARRAY_SIZE;i++)
	{
		s=s+array[i];
		if (array[i]<*pmin)
		{
			*pmin=array[i];
		}
		if ( array[i] > *pmax )
		{
			*pmax=array[i];
		}

	}
	*pmoy=(float)s/ARRAY_SIZE;

}
void dispCaracArray(int mini, int maxi, float moy)
{
 printf("voici le minimum %d \t et ainsi le maximum %d \t de plus de la moyenne demande %2.f\n",mini,maxi,moy); // @suppress("Float formatting support")
}//LA MOYENNE N4APPARAIT PAS

void loop()
{



}


