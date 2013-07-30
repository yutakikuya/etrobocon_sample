/****************************************************
 *  BalanceRunner.h                                         
 *  Created on: 2012/05/05 7:35:18                      
 *  Implementation of the Class BalanceRunner       
 *  Original author: hiroyuki.watanabe                     
 ****************************************************/

#if !defined(EA_C605D693_C4E5_4bae_AA91_AF78605F3679__INCLUDED_)
#define EA_C605D693_C4E5_4bae_AA91_AF78605F3679__INCLUDED_


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

#endif /*!defined(EA_C605D693_C4E5_4bae_AA91_AF78605F3679__INCLUDED_)*/

