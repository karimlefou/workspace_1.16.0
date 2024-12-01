/*
 * utils.c
 *
 *  Created on: Oct 4, 2024
 *      Author: karim
 */

#include <stm32l4xx_hal.h>
#include "utils.h"
#include "fonction_67.h"
#include "main.h"
#include <stdio.h>
#include <string.h>

#define BUFFER_MAX_SIZE 128

 extern UART_HandleTypeDef huart1;
 extern UART_HandleTypeDef huart2;


 int fillBuffer(char *buffer, int size) {
     int i, total = 0;
     char received_char;

     for (i = 0; i < size; i++) {
         buffer[i] = 0;
     }

     HAL_UART_Abort(&huart1);

     do {
         HAL_UART_Receive(&huart1, (uint8_t *)&received_char, 1, HAL_MAX_DELAY);
     } while (received_char != '$');

     do {
         HAL_UART_Receive(&huart1, (uint8_t *)&received_char, 1, HAL_MAX_DELAY);
         *buffer = received_char;
         total++;
         buffer++;
     } while (received_char != '\n');

     return total;
 }
 //6.8
 int Recherche_virgule(char* frame,int nb_virgule) {
     int pos=0;
     while (nb_virgule > 0 && *frame != '\0') {
         if (*frame == ',') {
             nb_virgule--;
         }
         frame++;
         pos++;
     }
     return pos;
 }

 float getLatitude(char * frame)
 {
	 int i;
	 float l,L; //ALLTITUDE en absolue
	 i=Recherche_virgule(frame,2);


	    l = 10 * (frame[i ] & 0xf) + (frame[i +1] & 0xf) +
	        (10 * (frame[i + 2] & 0xf) + (frame[i + 3] & 0xf) +
	         0.1f * (frame[i + 5] & 0xf) + 0.01f * (frame[i + 6] & 0xf) +
	         0.001f * (frame[i + 7] &0xf)) / 60.0;
	 if (frame[i+9]== 0x4E)
	 {
		 L=l;
	 }
	 else
	 {
		 L=-l;
	 }
	 printf("Latitude: %f \n\r", L);
	 return L;


 }
 getLongitude(char * frame)
 {
	 int i;
	 float l,L; //ALLTITUDE en absolue
	 i=Recherche_virgule(frame,4);


	    l = 10 * (frame[i ] & 0xf) + (frame[i +1] & 0xf) +
	        (10 * (frame[i + 2] & 0xf) + (frame[i + 3] & 0xf) +
	         0.1f * (frame[i + 5] & 0xf) + 0.01f * (frame[i + 6] & 0xf) +
	         0.001f * (frame[i + 7] &0xf)) / 60.0;
	 if (frame[i+9]== 0x4E)
	 {
		 L=l;
	 }
	 else
	 {
		 L=-l;
	 }
	 printf("LONGETITUDE: %f \n\r", L);
	 return L;


 }

 void setup()
 {
	  char received_char;
		  while(HAL_UART_Receive(&huart1, (uint8_t *)&received_char, 1, 0)!=HAL_OK){}
		  HAL_UART_Transmit( &huart2, (uint8_t *) &received_char, 1, HAL_MAX_DELAY);
		      char buffer[BUFFER_MAX_SIZE];

		      // Remplir le buffer avec les données NMEA
		      int size = fillBuffer(buffer, BUFFER_MAX_SIZE);

		      // Vérifier que la trame a bien été reçue
		      if (size > 0) {
		          printf("Trame NMEA reçue: %s\n\r", buffer);

		          // Extraire la latitude à partir du buffer
		          getLatitude(buffer);
		          getLongitude(buffer);
		      } else {
		          printf("Erreur de réception de la trame NMEA\n\r");
		      }
		  }
 // insert the setup here, it will be run once.

 void loop()
 {
	  char received_char;
	  while(HAL_UART_Receive(&huart1, (uint8_t *)&received_char, 1, 0)!=HAL_OK){}
	  HAL_UART_Transmit( &huart2, (uint8_t *) &received_char, 1, HAL_MAX_DELAY);
	  char buffer[BUFFER_MAX_SIZE];
	   int size;
	   while(1)
	   {
	   size=fillBuffer(buffer,BUFFER_MAX_SIZE);
	   printf("Received %d char : %s \n\r",size,buffer);
	   }

 }
