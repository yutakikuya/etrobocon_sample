/****************************************************
 *  BalanceRunner.h                                         
 *  Created on: 2012/05/05 8:44:23                      
 *  Implementation of the Class BalanceRunner       
 *  Original author: hiroyuki.watanabe                     
 ****************************************************/

#if !defined(EA_D4C8BBB9_0AED_4f6f_B4B8_A6C29FF08A8B__INCLUDED_)
#define EA_D4C8BBB9_0AED_4f6f_B4B8_A6C29FF08A8B__INCLUDED_


#include "ecrobot_interface.h"
#include "kernel.h"

#include "Direction.h"

#include "GyroSensor.h"
#include "Motor.h"


// 属性を保持するための構造体の定義
typedef struct BalanceRunner
{
	int forward;
	int turn;
	BOOL isInitialized;
	GyroSensor *gyroSensor;
	Motor *leftMotor;
	Motor *rightMotor;
} BalanceRunner;

// 公開操作
void BalanceRunner_init(BalanceRunner* this);
void BalanceRunner_run(BalanceRunner* this, DIRECTION direction);

#endif /*!defined(EA_D4C8BBB9_0AED_4f6f_B4B8_A6C29FF08A8B__INCLUDED_)*/

