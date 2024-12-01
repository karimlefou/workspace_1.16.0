/*
 * task.h
 *
 *  Created on: Nov 6, 2024
 *      Author: karim
 */

#ifndef INC_TASK_H_
#define INC_TASK_H_
#include <stdio.h>
#include "led.h"
typedef struct motif_type{
	int size;
	int * motif;
	char * name; }MOTIF_TYPE;

void setup(void);
void loop(void);
extern int upDownMotif[];
extern int chenillardUpMotif[];
extern int chenillardDownMotif[];
extern const MOTIF_TYPE upDown;
extern const MOTIF_TYPE chenillardUp;
extern const MOTIF_TYPE chenillardDown;
extern const MOTIF_TYPE* tableau_motif[3];

void taskLED();
void taskButton();
void taskScreen();

#endif /* INC_TASK_H_ */
