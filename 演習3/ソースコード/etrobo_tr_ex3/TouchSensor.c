/****************************************************
 *  TouchSensor.c                                         
 *  Created on: 2012/05/05 8:53:40                      
 *  Implementation of the Class TouchSensor       
 *  Original author: hiroyuki.watanabe                     
 ****************************************************/

#include "TouchSensor.h"


// ����������
void TouchSensor_init(TouchSensor* this, SENSOR_PORT_T inputPort)
{
	this->inputPort = inputPort;
}

// ������Ԃ𓾂�
BOOL TouchSensor_isPressed(TouchSensor* this)
{
	return ecrobot_get_touch_sensor(this->inputPort);
} 




