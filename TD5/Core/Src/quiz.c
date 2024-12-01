/*
 * quiz.c
 *
 *  Created on: Oct 15, 2024
 *      Author: karim
 */

#include <stm32l4xx_hal.h>
#include "quiz.h"
//maitrejedi
int id; // l'identifiant du capteur
float  threshold,  value; // le seuil d'activation et la valeur
SENSOR_STATE state;
SENSOR SENSOR_ARRAY[SENSOR_NUMBER];

void init_system(SENSOR* system)
{
	int i;
	for(i=0; i<SENSOR_NUMBER; i++)
	{
		system[i].state=INACTIVE;
		system[i].id=i;
		system[i].value =0.0;
		system[i].threshold=(rand()%1001)/100.0;
	}
}
void displaysystem(SENSOR * system)
{
	int i;
	for(i=0; i<SENSOR_NUMBER; i++)
	{
		printf("voici la valeur de seuil du capteur %f \n\r",system[i].threshold);
	}

}
void readsensors(SENSOR * system)
{
	int i;
	for(i=0; i<SENSOR_NUMBER; i++)
	{
		system[i].value =(rand()%1001)/100.0;

	}

}
void checkthreshold(SENSOR * system)
{
	int i;
	for(i=0; i<SENSOR_NUMBER; i++)
	{
		if(system[i].value > system[i].threshold)
		{
			system[i].state= ACTIVE;
		}
		else
		{
			system[i].state= INACTIVE;
		}
		printf("%d \n\r",system[i].state);

	}
}


void setup1(void)
{
	 srand(123456);
	 init_system(SENSOR_ARRAY);
	 displaysystem(SENSOR_ARRAY);
	 readsensors(SENSOR_ARRAY);
	 checkthreshold(SENSOR_ARRAY);


}
void loop1(void)
{

}

