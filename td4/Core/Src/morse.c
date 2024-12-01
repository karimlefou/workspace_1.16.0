/*
 * morse.c
 *
 *  Created on: Oct 7, 2024
 *      Author: karim
 */

#include <stm32l4xx_hal.h>
#include "morse.h"
const MORSE_LETTRE alphabet[ALPHABET_SIZE]={{'A', ".-"},{'B', "-..."},{'C', "-.-."},{'D', "-.."},{'E', "."},{'F', "..-."},{'G', "--."},{'H', "...."}, {'I', ".."},
		{'J', ".---"},     {'K', "-.-"},        {'L', ".-.."},
		{'M', "--"},       {'N', "-."},         {'O', "---"},
		{'P', ".--."},     {'Q', "--.-"},       {'R', ".-."},
		{'S', "..."},      {'T', "-"},          {'U', "..-"},
		{'V', "...-"},    { 'W', ".--"},        {'X', "-..-"},
		{'Y', "-.--"},     {'Z', "--.."},
		{'.', ".-.-.-"},
		{'0', "-----"},    {'1', ".----"},      {'2', "..---"},
		{'3', "...--"},    {'4', "....-"},      {'5', "....."},
		{'6', "-...."},   { '7', "--..."},      {'8', "---.."},
		{'9', "----."},
      } ; // CONST CA VEUT DIRE CONSTANTE / CA NE CHANGE PAS DE VALEUR NUMERIQUE
GPIO_PinState PinState,led;
char morseCode[5]; // Pour enregistrer le code Morse d'une lettre
int morseIndex = 0;
void setup1()
{

	//printf("%c /n/r",lookupInBaseFromCode(".."));
	//printf("%s ",lookupInBaseFromLetter('W'));
    printf("STM32 Morse Decoder Ready\n\r");



}
void loop1()
{
    char d;
    PinState = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13);
    d = waitForInput(decodeappui());

    if (d == ' ')
    {
        morseCode[morseIndex] = '\0'; // Fin du code Morse pour une lettre
        char decodedLetter = lookupInBaseFromCode(morseCode);
        if (decodedLetter)
        {
            printf("Lettre décodée: %c\n\r", decodedLetter); // Afficher la lettre décodée
        }
        morseIndex = 0; // Réinitialiser pour la prochaine lettre
    }
    else
    {
        if (morseIndex < sizeof(morseCode) - 1)
        {
            morseCode[morseIndex++] = d;
            printf("Code Morse en cours: %s\n\r", morseCode); // Afficher le code Morse en cours
        }
    }

    HAL_Delay(100); // Petite pause pour éviter de spammer la détection
}

char lookupInBaseFromCode (char * code)
{
	int i;
	for (i=0;i<ALPHABET_SIZE;i++)
	{
		if (strcmp(code,alphabet[i].code)==0)
			return alphabet[i].letter;
	}
	return 0;
}
char * lookupInBaseFromLetter (char letter)
{
	int i;
	for (i=0;i<ALPHABET_SIZE;i++)
	{
		if (letter==alphabet[i].letter)
			return alphabet[i].code;
	}
	return 0;
}
char waitForInput (char previousInput)
{
    int  d = 0, f = 0, T = 0, T1 = 0, d1 = 0, f1 = 0;
    GPIO_PinState cour;

    cour = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13); // Lire l'état du bouton

    if (cour == GPIO_PIN_RESET) // Si le bouton est appuyé
    {
        d = HAL_GetTick(); // Démarrer le timing
        while (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13) == GPIO_PIN_RESET)
        {
            // Attendre que le bouton soit relâché
        }
        f = HAL_GetTick(); // Temps lorsque le bouton est relâché
        T = f - d; // Calculer la durée de l'appui

        if (T >= 200) // Si l'appui est long
        {
            return '-'; // Retourner un trait
        }
        else if (T > 0 && T < 200) // Si l'appui est court
        {
            return '.'; // Retourner un point
        }
    }
    else // Si le bouton n'est pas appuyé
    {
        f1 = HAL_GetTick();
        T1 = f1 - d1;

        if (T1 >= 1000) // Si l'intervalle dépasse 1 seconde
        {
            return ' '; // Espacement entre les lettres
        }
    }

    return previousInput; // Si rien ne change, retourner l'entrée précédente
}

char decodeappui(void) // SOIT UN - un . OU ESPACE
{
	int  d = 0, f = 0,T=0;
	GPIO_PinState  cour;
	cour = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13);
	if (cour==0)
		{
		    HAL_Delay(50);
			d=HAL_GetTick();
			cour = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13);
			while(cour!=1) // PCK T
			{
				f=HAL_GetTick();
			}
				T=f-d;
			if(T >= 200)
			{

				return '-';
			}
			else
			{
				return '.';
			}
		}
		else
		{
			return ' ';
		}
}


