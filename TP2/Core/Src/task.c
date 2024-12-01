/*
 * task.c
 *
 *  Created on: Nov 6, 2024
 *      Author: karim
 */

#include "task.h"
static int globalDelayInMs=200;

int upDownMotif[]={0,128,192,224,240,248,252,254,255,254,252,248,240,224,192,128};
int chenillardUpMotif[]={1,2,4,8,16,32,64,128};
int chenillardDownMotif[]={128,64,32,16,8,4,2,1};
const MOTIF_TYPE upDown={16,upDownMotif,"Up Down"};
const MOTIF_TYPE chenillardUp={8,chenillardUpMotif,"K 2000"};
const MOTIF_TYPE chenillardDown={8,chenillardDownMotif,"K -2000"};
const MOTIF_TYPE* tableau_motif[3]={&upDown, &chenillardUp, &chenillardDown};
static int index_tableau_motif=0;

void setup()
{
}
void loop()
{

}
void taskLED()
{

	int numero_motif=(HAL_GetTick()/globalDelayInMs)%(tableau_motif[index_tableau_motif]->size);
	/*LED_Set_Value_With_Int(numero_motif);
	const MOTIF_TYPE* motif = tableau_motif[index_tableau_motif];
	LED_Set_Value_With_Int(motif->motif[numero_motif]);
	LED_Update();
	if (numero_motif == motif->size - 1) {
	        index_tableau_motif = (index_tableau_motif + 1) % 3; } // Passer au motif suivant dans le tableau
*/



}
void taskButton()
{


}
void taskScreen()
{


}
