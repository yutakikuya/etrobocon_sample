/****************************************************
 *  BalanceRunner.h                                         
 *  Created on: 2012/05/05 9:05:13                      
 *  Implementation of the Class BalanceRunner       
 *  Original author: hiroyuki.watanabe                     
 ****************************************************/

#if !defined(EA_5A92E2DE_79E3_420a_9B72_20692872466F__INCLUDED_)
#define EA_5A92E2DE_79E3_420a_9B72_20692872466F__INCLUDED_


#include "ecrobot_interface.h"
#include "kernel.h"

#include "Direction.h"

#include "GyroSensor.h"
#include "Motor.h"


// ëÆê´Çï€éùÇ∑ÇÈÇΩÇﬂÇÃç\ë¢ëÃÇÃíËã`
typedef struct BalanceRunner
{
	int forward;
	int turn;
	BOOL isInitialized;
	GyroSensor *gyroSensor;
	Motor *leftMotor;
	Motor *rightMotor;
} BalanceRunner;

// åˆäJëÄçÏ
void BalanceRunner_init(BalanceRunner* this);
void BalanceRunner_run(BalanceRunner* this, DIRECTION direction);

#endif /*!defined(EA_5A92E2DE_79E3_420a_9B72_20692872466F__INCLUDED_)*/

