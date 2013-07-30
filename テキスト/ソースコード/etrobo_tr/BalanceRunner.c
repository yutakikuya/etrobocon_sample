/****************************************************
 *  BalanceRunner.c                                         
 *  Created on: 2012/05/05 7:35:18                      
 *  Implementation of the Class BalanceRunner       
 *  Original author: hiroyuki.watanabe                     
 ****************************************************/

#include "BalanceRunner.h"
#include "balancer.h" // 倒立振子制御用ヘッダファイル

#define LOW     30 // 低速
#define NORMAL  50 // 通常
#define HIGH    70 // 高速
#define BATT  8000 // バッテリー電圧



// 初期化する
void BalanceRunner_init(BalanceRunner* this)
{
	this->forward 	    = LOW;
	this->turn          = LOW;
	this->isInitialized = FALSE;
}

// 倒立走行を行う
void BalanceRunner_run(BalanceRunner* this, DIRECTION direction)
{
	int turn;			// 方向を反映した旋回速度
	unsigned int gyro;		// ジャイロセンサ値
	unsigned int gyro_offset;	// ジャイロセンサオフセット値
	long motor_ang_l;		// 左モータ回転角度
	long motor_ang_r;		// 右モータ回転角度
	signed char pwm_l;		// 左モータPWM出力値
	signed char pwm_r;		// 右モータPWM出力値
	
	// 最初だけ、倒立振子制御を初期化とモータエンコーダのリセットを行う
	if(! this->isInitialized)
	{
		balance_init();		// 倒立振子制御初期化
	
		// モータエンコーダをリセットする
		nxt_motor_set_count(NXT_PORT_C, 0);
		nxt_motor_set_count(NXT_PORT_B, 0);
	
		// 初期化済にする
		this->isInitialized = TRUE;
	}
	
	// 指定された方向に合わせた旋回速度を設定する
	if(direction == LEFT)
	{
		turn = this->turn * (-1);
	}
	else
	{
		turn = this->turn;
	}
	
	// 倒立振子制御API に渡すパラメータを取得する
	gyro_offset = GyroSensor_getOffset(this->gyroSensor);
	gyro = GyroSensor_getAngularVelocity(this->gyroSensor);
	motor_ang_l = Motor_getAngle(this->leftMotor);
	motor_ang_r = Motor_getAngle(this->rightMotor);
	
	// 倒立振子制御APIを呼び出し、倒立走行するための
	// 左右モータ出力値を得る
	balance_control(
		(float)this->forward,
		(float)turn,
		(float)gyro, (float)gyro_offset,
		(float)motor_ang_l, (float)motor_ang_r,
		BATT,
		(signed char*)&pwm_l, (signed char*)&pwm_r
	);
	
	// 左右モータに回転を指示する
	Motor_rotate(this->leftMotor,pwm_l);
	Motor_rotate(this->rightMotor,pwm_r);
} 




