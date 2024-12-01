/*
 * utils.c
 *
 *  Created on: Oct 15, 2024
 *      Author: karim
 */
#include <stm32l4xx_hal.h>
#include "utils.h"
//i l’horloge du r´ecepteur est d´ecal´ee de x % par rapport ` a celle de l’´emetteur,
 //quelle doit ˆetre la valeur de x pour ˆ etre certain d’´echantillonner correctement
// tous les bits d’un octet, sachant que pour ´emettre un octet il faut ´emettre dix
 //bits (start et stop inclus).
// DECLAGE CUMIULE NE OIT PAS DEPASSER LA MOITIE D4UN BIT D4OU %x *10 =1/2
// d'ou x=0,05
void setup(void)
{

}
void loop(void)
{

}
