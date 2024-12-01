/*
 * utils.h
 *
 *  Created on: Oct 4, 2024
 *      Author: karim
 */

#ifndef INC_UTILS_H_
#define INC_UTILS_H_
void setup(void);
void loop(void);
int fillBuffer(char *buffer, int size);
float getLatitude(char * frame);
int Recherche_virgule(char* frame,int nb_virgule) ;
getLongitude(char * frame);
extern UART_HandleTypeDef huart1;



#endif /* INC_UTILS_H_ */
