/*
 * utils.c
 *
 *  Created on: Sep 13, 2024
 *      Author: karim
 */

#include <stm32l4xx_hal.h>
#include "utils.h"
int etat_led = 0;

void setup(){


}
GPIO_PinState PinState; //déclare une variable PinState de type GPIO_PinState. Voici à quoi elle sert et comment elle est utilisée dans votre code
GPIO_PinState previousState = GPIO_PIN_SET; // Initialisé à "non pressé" (état haut)

void loop(){
    PinState = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13);
    static int i = 1;

    // Vérifie si le bouton vient d'être pressé (transition de "haut" à "bas")
    if (PinState == GPIO_PIN_RESET && previousState == GPIO_PIN_SET) {
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET); // Allume la LED
        etat_led = 1 - etat_led;
        printf("Switch pressed %d times, LED state: %d \r\n", i , etat_led);
        i++; // Incrémente le compteur uniquement au changement d'état
        HAL_Delay(200); // Délai anti-rebond
    } else if (PinState == GPIO_PIN_SET && previousState == GPIO_PIN_RESET) {
        // Le bouton vient d'être relâché, on éteint la LED
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET); // Éteint la LED
        etat_led = 1 - etat_led;

        printf("Switch pressed %d times, LED state: %d \r\n", i-1,etat_led );
    }

    previousState = PinState;

}
