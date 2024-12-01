/*
 * morse.h
 *
 *  Created on: Oct 7, 2024
 *      Author: karim
 */

#ifndef INC_MORSE_H_
#define INC_MORSE_H_
#include <stdio.h>
#include <string.h>
typedef struct morse_lettre{char letter;char * code;}MORSE_LETTRE;
#define ALPHABET_SIZE 37
char lookupInBaseFromCode (char * code);
char * lookupInBaseFromLetter (char letter);
char waitForInput (char previousInput);
char decodeappui(void);
void setup1(void);
void loop1(void);

#endif /* INC_MORSE_H_ */
