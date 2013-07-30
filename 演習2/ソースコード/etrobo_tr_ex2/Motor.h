/****************************************************
 *  Motor.h                                         
 *  Created on: 2012/05/05 8:42:48                      
 *  Implementation of the Class Motor       
 *  Original author: hiroyuki.watanabe                     
 ****************************************************/

#if !defined(EA_57656B0C_86F0_4b40_8B71_CCEFEB7B1FEE__INCLUDED_)
#define EA_57656B0C_86F0_4b40_8B71_CCEFEB7B1FEE__INCLUDED_


#include "ecrobot_interface.h"
#include "kernel.h"


// 属性を保持するための構造体の定義
typedef struct Motor
{
	MOTOR_PORT_T outputPort;
} Motor;

// 公開操作
void Motor_init(Motor* this, MOTOR_PORT_T outputPort);
void Motor_resetAngle(Motor* this);
long Motor_getAngle(Motor* this);
void Motor_rotate(Motor* this, int pwm);

#endif /*!defined(EA_57656B0C_86F0_4b40_8B71_CCEFEB7B1FEE__INCLUDED_)*/

