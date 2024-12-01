/*
 * fonction_67.c
 *
 *  Created on: Oct 4, 2024
 *      Author: karim
 */
/*
 * utils.c
 *
 *  Created on: Oct 4, 2024
 *      Author: karim
 */

#include <stm32l4xx_hal.h>
#include "fonction_67.h"
#include "main.h"
#include "utils.h"
#include <stdio.h>
#include <string.h>
#include <math.h>
#define BUFFER_MAX_SIZE 128
char buffer[BUFFER_MAX_SIZE];
void setup1(){}
 extern UART_HandleTypeDef huart1;
 extern UART_HandleTypeDef huart2;
 // Fonction qui vérifie si la trame commence par "$GPGGA"
 int isGPGGA(char *frame) {
     if (strncmp(frame, "$GPGGA", 6) == 0) {
         return 1;
     } else {
         return -1;
     }
 }

 // Fonction qui extrait le checksum après '*'
 int extractChecksum(char *buffer) {
     // Parcours du buffer jusqu'à rencontrer le caractère '*'
     while (*buffer != '*') {
         buffer++;
     }

     // Extraction des deux caractères après '*', en considérant le checksum hexadécimal
     return (buffer[1] & 0x0F) * 16 + (buffer[2] & 0x0F);
 }

 // Fonction qui calcule le checksum en XOR
 int calculateChecksum(char *buffer) {
     int checksum = 0;

     // Ignorer le premier caractère '$'
     buffer++;

     // XOR chaque caractère jusqu'à rencontrer '*'
     while (*buffer != '*' && *buffer != '\0') {
         checksum ^= *buffer;
         buffer++;
     }

     return checksum;
 }

 // Fonction qui vérifie si la trame est valide en comparant le checksum et l'entête
 int checkFrame(char * buffer)
 {
 	if (isGPGGA(buffer) != 1) {
 	        return 0;
 	    }
 	    int extractedChecksum = extractChecksum(buffer);
 	    int calculatedChecksum = calculateChecksum(buffer);
 	 if (calculatedChecksum == extractedChecksum)
 	    {
 	        return 1;
 	    }
 	 else
 	    {
 	        return 0;
 	    }
 }


 void loop1()
 {
    int size = fillBuffer(buffer, BUFFER_MAX_SIZE);
    printf("Just received %d bytes \r\n", size);
    if (checkFrame(buffer) == 1) {
        printf("Frame is valid.\r\n");
    } else {
        printf("Frame is invalid.\r\n");
    }
 }




