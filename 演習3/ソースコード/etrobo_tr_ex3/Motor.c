/****************************************************
 *  Motor.c                                         
 *  Created on: 2012/05/05 8:58:00                      
 *  Implementation of the Class Motor       
 *  Original author: hiroyuki.watanabe                     
 ****************************************************/

#include "Motor.h"


// ����������
void Motor_init(Motor* this, MOTOR_PORT_T outputPort)
{
	this->outputPort = outputPort;
}

// ��]�p�x�����Z�b�g����
void Motor_resetAngle(Motor* this)
{
	return nxt_motor_set_count(this->outputPort, 0);
}

// ��]�p�x�𓾂�
long Motor_getAngle(Motor* this)
{
	return nxt_motor_get_count(this->outputPort);
}

// ��]������
void Motor_rotate(Motor* this, int pwm)
{
	nxt_motor_set_speed(this->outputPort, pwm, 1);
} 




