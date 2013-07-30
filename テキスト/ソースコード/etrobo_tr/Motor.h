/****************************************************
 *  Motor.h                                         
 *  Created on: 2012/05/05 7:35:26                      
 *  Implementation of the Class Motor       
 *  Original author: hiroyuki.watanabe                     
 ****************************************************/

#if !defined(EA_57AC6181_F8E0_460f_9F59_90029C62B716__INCLUDED_)
#define EA_57AC6181_F8E0_460f_9F59_90029C62B716__INCLUDED_


#include "ecrobot_interface.h"
#include "kernel.h"


// ������ێ����邽�߂̍\���̂̒�`
typedef struct Motor
{
	MOTOR_PORT_T outputPort;
} Motor;

// ���J����
void Motor_init(Motor* this, MOTOR_PORT_T outputPort);
void Motor_resetAngle(Motor* this);
long Motor_getAngle(Motor* this);
void Motor_rotate(Motor* this, int pwm);

#endif /*!defined(EA_57AC6181_F8E0_460f_9F59_90029C62B716__INCLUDED_)*/

