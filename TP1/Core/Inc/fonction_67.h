/*
 * fonction_67.h
 *
 *  Created on: Oct 4, 2024
 *      Author: karim
 */
#ifndef INC_FONCTION_67_H_
#define INC_FONCTION_67_H_
void setup1(void);
void loop1(void);
int isGPGGA(char *frame);
int extractChecksum(char * buffer);
extern UART_HandleTypeDef huart1;



#endif /* INC_FONCTION_67_H_ */
