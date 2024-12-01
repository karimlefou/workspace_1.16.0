/*
 * utils.c
 *
 *  Created on: Sep 26, 2024
 *      Author: karim
 */

#include <stm32l4xx_hal.h>
#include "utils.h"
#include <stdio.h>
#define ARRAY_SIZE 20
GPIO_PinState PinState;

void setup(){
 // insert the setup here, it will be run once.
 }
void fillArray(int* array, int size) //CALCULER LE TEMPS D4UN APPUIS
{
    int i = 0, d = 0, f = 0;  // Variables pour stocker le temps d'appui et de relâche
    GPIO_PinState cour, prec;  // `cour` pour la valeur courante et `prec` pour la précédente

    prec = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13);  // Initialiser l'état précédent du bouton

    while (i < size) {
        cour = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13);  // Lire l'état courant du bouton

        // Si le bouton est appuyé (transition de 1 à 0)
        if (cour == GPIO_PIN_RESET && prec == GPIO_PIN_SET) {
            d = HAL_GetTick();  // Temps où le bouton est pressé
        }

        // Si le bouton est relâché (transition de 0 à 1)
        if (cour == GPIO_PIN_SET && prec == GPIO_PIN_RESET) {
            f = HAL_GetTick();  // Temps où le bouton est relâché
            array[i] = f - d;   // Calculer la durée de l'appui
            printf("array[%d] = %d ms\n\r", i + 1, array[i]);  // Afficher la durée
            i++;  // Passer à l'élément suivant du tableau
        }

        prec = cour;  // Mettre à jour l'état précédent
    }
}
void fillArray1(int * tab, int size )//CALCULER LE TEMPS D4UN APPUIS
{
    int i;
    uint32_t d = 0, f = 0;
    GPIO_PinState cour, prec;

    // Initialiser l'état précédent du bouton
    prec = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13);

    for (i = 0; i < size; ) {  // `i` ne doit être incrémenté que lorsqu'une durée valide est stockée
        // Lire l'état courant du bouton
        cour = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13);

        // Détection de l'appui sur le bouton (transition de 1 -> 0)
        if (cour == 0 && prec == 1) {
            d = HAL_GetTick(); // Marquer le début de l'appui
            prec = cour;       // Mettre à jour `prec` pour refléter l'état actuel
        }

        // Détection du relâchement du bouton (transition de 0 -> 1)
        else if (cour == 1 && prec == 0) {
            f = HAL_GetTick(); // Marquer la fin de l'appui
            prec = cour;       // Mettre à jour `prec` pour refléter l'état actuel

            // Calculer la durée en prenant en compte le débordement potentiel
            if (d != 0) {
                tab[i] = (f >= d) ? (f - d) : (f + (UINT32_MAX - d + 1));
                printf("tab[%d] = %d ms\n\r", i, tab[i]);
                i++;  // Incrémenter `i` pour stocker la prochaine mesure
            }
        }

        // Pause pour éviter la surcharge CPU dans la boucle
        HAL_Delay(10);
    }
}
int getMeanValue(int * array, int size)
{
	int s=0;
	int i;
	for (i=0;i< size;i++){
		s=s+array[i];
	}
	return (size > 0) ? s / size : 0;

}

void calculate_press_intervals(int *tab, int size) {
    int i = 0;
    uint32_t last_press_time = 0, current_press_time;
    GPIO_PinState cour, prec;

    // Initialiser `prec` avec l'état initial du bouton
    prec = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13);

    while (i < size) {
        // Lire l'état courant du bouton
        cour = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13);

        // Détection d'un appui sur le bouton (transition de 1 -> 0)
        if (cour == 0 && prec == 1) {
            // Enregistrer l'heure de l'appui actuel
            current_press_time = HAL_GetTick();

            // Si ce n'est pas le premier appui, calculer l'intervalle depuis le dernier appui
            if (last_press_time != 0) {
                tab[i] = current_press_time - last_press_time;
                printf("Intervalle entre appui %d et %d = %d ms\n\r", i, i + 1, tab[i]);
                i++;  // Passer au prochain intervalle
            }

            // Mettre à jour `last_press_time` pour l'appui suivant
            last_press_time = current_press_time;
        }

        // Mettre à jour `prec` pour le prochain tour de boucle
        prec = cour;

        // Petite pause pour éviter la surcharge CPU dans la boucle
        HAL_Delay(10);
    }
}
void loop(){
	 int array[ARRAY_SIZE];
	 int tab[ARRAY_SIZE];

	 //fillArray(array,ARRAY_SIZE);
	 //fillArray1(tab,ARRAY_SIZE);  // LE I N4EST PAS INCREMENTE
	 calculate_press_intervals(tab,ARRAY_SIZE);

	 //int c=getMeanValue(array,ARRAY_SIZE);

	 //printf("%d",c);
 // This code will run indefinitly.
 }
