/*
 * quiz.h
 *
 *  Created on: Oct 15, 2024
 *      Author: karim
 */

#ifndef INC_QUIZ_H_
#define INC_QUIZ_H
#define SENSOR_NUMBER 5
#include <stdlib.h>
#include <stdio.h>

// Définition de l'énumération
typedef enum {
    INACTIVE,   // Valeur 0
    ACTIVE      // Valeur 1
} SENSOR_STATE;
typedef struct {
    SENSOR_STATE state;   // Etat actif ou inactif du capteur
    int id;               // Identifiant unique du capteur
    float value;          // Valeur mesurée par le capteur (par exemple une température, une distance, etc.)
    unsigned long threshold;  // Horodatage de la dernière mise à jour de la mesure
} SENSOR;

void init_system(SENSOR* system);
void displaysystem(SENSOR * system);
void setup1(void);
void loop1(void);


#endif /* INC_QUIZ_H_ */
