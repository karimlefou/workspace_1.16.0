/*
 * button.c
 *
 *  Created on: Jun 14, 2024
 *      Author: nicohaas57
 */

#include "button.h"

static BUTTON joystick[5] = {{0,0,BTN_CENTER_GPIO_Port,BTN_CENTER_Pin}, {0,0,BTN_BOTTOM_GPIO_Port,BTN_BOTTOM_Pin},
							 {0,0,BTN_RIGHT_GPIO_Port,BTN_RIGHT_Pin}, {0,0,BTN_TOP_GPIO_Port,BTN_TOP_Pin},
							 {0,0,BTN_LEFT_GPIO_Port,BTN_LEFT_Pin}
};

int BUTTON_Get_Value(DIRECTION direction) {
	return joystick[direction].isOn;
}

int BUTTON_Get_Pressed(DIRECTION direction) {
	return joystick[direction].hasBeenPressed;
}

void BUTTON_Update()
{
    for (int i = 0; i < 5; i++)
    {

        int isPressed = (HAL_GPIO_ReadPin(joystick[i].port, joystick[i].pinNumber) == GPIO_PIN_SET);

        if (!joystick[i].isOn && isPressed) {
            joystick[i].hasBeenPressed = 1;
            printf("Bouton %d appuyé\n", i);
        } else {
            joystick[i].hasBeenPressed = 0;
        }


        joystick[i].isOn = isPressed;

        HAL_GPIO_WritePin(joystick[i].port, joystick[i].pinNumber, joystick[i].isOn);
    }
}


