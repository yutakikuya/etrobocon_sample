/****************************************************
 *  Motor.h                                         
 *  Created on: 2012/05/05 8:58:00                      
 *  Implementation of the Class Motor       
 *  Original author: hiroyuki.watanabe                     
 ****************************************************/

#if !defined(EA_D81C604A_BB8F_4489_A0CE_75BCF7536481__INCLUDED_)
#define EA_D81C604A_BB8F_4489_A0CE_75BCF7536481__INCLUDED_


#include "ecrobot_interface.h"
#include "kernel.h"


// ëÆê´Çï€éùÇ∑ÇÈÇΩÇﬂÇÃç\ë¢ëÃÇÃíËã`
typedef struct Motor
{
	MOTOR_PORT_T outputPort;
} Motor;

// åˆäJëÄçÏ
void Motor_init(Motor* this, MOTOR_PORT_T outputPort);
void Motor_resetAngle(Motor* this);
long Motor_getAngle(Motor* this);
void Motor_rotate(Motor* this, int pwm);

#endif /*!defined(EA_D81C604A_BB8F_4489_A0CE_75BCF7536481__INCLUDED_)*/

