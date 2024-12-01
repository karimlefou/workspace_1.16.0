/*
 * encoder.c
 *
 *  Created on: Nov 8, 2024
 *      Author: karim
 */
#include "encoder.h"
static ENCODER encoder;

void encoder_init(TIM_HandleTypeDef * htim_param, int32_t min, int32_t max)
{
	encoder.htim = htim_param;
	    encoder.min_value = min;
	    encoder.max_value = max;
	    //encoder.htim->Instance->CNT=0;
	    HAL_TIM_Encoder_Start(encoder.htim, TIM_CHANNEL_ALL);


}
int32_t encoder_read()
{
    int32_t value = encoder.htim->Instance->CNT;

    if (value > encoder.max_value) {
        value = encoder.max_value;
        encoder.htim->Instance->CNT = encoder.max_value;
        }

    else if (value < encoder.min_value) {
        value = encoder.min_value;
        encoder.htim->Instance->CNT = encoder.min_value;
    }


    return value;
}



