/****************************************************
 *  LightSensor.h                                         
 *  Created on: 2012/05/05 8:57:50                      
 *  Implementation of the Class LightSensor       
 *  Original author: hiroyuki.watanabe                     
 ****************************************************/

#if !defined(EA_4F1484FA_9502_4846_9B62_B4651FDF20C2__INCLUDED_)
#define EA_4F1484FA_9502_4846_9B62_B4651FDF20C2__INCLUDED_


#include "ecrobot_interface.h"
#include "kernel.h"


// 属性を保持するための構造体の定義
typedef struct LightSensor
{
	SENSOR_PORT_T inputPort;
} LightSensor;

// 公開操作
void LightSensor_init(LightSensor* this, SENSOR_PORT_T inputPort);
unsigned int LightSensor_getBrightness(LightSensor* this);

#endif /*!defined(EA_4F1484FA_9502_4846_9B62_B4651FDF20C2__INCLUDED_)*/

