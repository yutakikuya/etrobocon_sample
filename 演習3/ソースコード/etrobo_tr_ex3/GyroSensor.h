/****************************************************
 *  GyroSensor.h                                         
 *  Created on: 2012/05/05 8:57:56                      
 *  Implementation of the Class GyroSensor       
 *  Original author: hiroyuki.watanabe                     
 ****************************************************/

#if !defined(EA_14C2A771_5413_40b2_9A50_D64689AA5533__INCLUDED_)
#define EA_14C2A771_5413_40b2_9A50_D64689AA5533__INCLUDED_


#include "ecrobot_interface.h"
#include "kernel.h"


// ������ێ����邽�߂̍\���̂̒�`
typedef struct GyroSensor
{
	unsigned int offset;
	SENSOR_PORT_T inputPort;
} GyroSensor;

// ���J����
void GyroSensor_init(GyroSensor* this, SENSOR_PORT_T inputPort);
unsigned int GyroSensor_getAngularVelocity(GyroSensor* this);
unsigned int GyroSensor_getOffset(GyroSensor* this);

#endif /*!defined(EA_14C2A771_5413_40b2_9A50_D64689AA5533__INCLUDED_)*/

