///////////////////////////////////////////////////////////
//  model_impl.c
///////////////////////////////////////////////////////////

#include "ScenarioTracer.h"
#include "Scenario.h"
#include "UI.h"
#include "BalanceRunner.h"
#include "TouchSensor.h"
#include "GyroSensor.h"
#include "Motor.h"

#include "kernel.h"
#include "kernel_id.h"
#include "ecrobot_interface.h"

#define	COUNT_SCENARIO	4			// シナリオの数
						// ※MAX_SCENARIOを超えないこと

// オブジェクトを静的に確保する
ScenarioTracer 	scenarioTracer;
Scenario	scenarios[] = {
		{LEFT, 1250},			// 左旋回1.25秒
		{STRAIGHT, 5000},		// 直進5秒
		{LEFT, 1250},			// 左旋回1.25秒
		{STRAIGHT, 2500},};		// 直進2.5秒
UI 		ui;
BalanceRunner 	balanceRunner;
TouchSensor 	touchSensor;
GyroSensor 	gyroSensor;
Motor 		leftMotor, rightMotor;

// デバイス初期化用フック関数
// この関数はnxtOSEK起動時に実行されます。
void ecrobot_device_initialize()
{
	// センサ、モータなどの各デバイスの初期化関数を
	// ここで実装することができます
	// ⇒　光センサ赤色LEDをONにする
	ecrobot_set_light_sensor_active(NXT_PORT_S3);
}

// デバイス終了用フック関数
// この関数はSTOPまたはEXITボタンが押された時に実行されます。
void ecrobot_device_terminate()
{
	// センサ、モータなどの各デバイスの終了関数を
	// ここで実装することができます。
	// ⇒　光センサ赤色LEDをOFFにする
	ecrobot_set_light_sensor_inactive(NXT_PORT_S3);
}

// 1msec周期割り込み(ISRカテゴリ2)から起動されるユーザー用フック関数
void user_1ms_isr_type2(void)
{
	// 今回は何も行わない
}

TASK(TaskMain)
{
	int i;

	// オブジェクト間のリンクを構築する
	for(i = 0; i < COUNT_SCENARIO; i++)
	{
		scenarioTracer.scenarios[i]  = &scenarios[i];
	}
	scenarioTracer.balanceRunner = &balanceRunner;
	ui.touchSensor		     = &touchSensor;
	balanceRunner.gyroSensor     = &gyroSensor;
	balanceRunner.leftMotor      = &leftMotor;
	balanceRunner.rightMotor     = &rightMotor;

	// 各オブジェクトを初期化する
	ScenarioTracer_init(&scenarioTracer, COUNT_SCENARIO);
	UI_init(&ui);
	BalanceRunner_init(&balanceRunner);
	TouchSensor_init(&touchSensor, NXT_PORT_S4);
	GyroSensor_init(&gyroSensor, NXT_PORT_S1);
	Motor_init(&leftMotor, NXT_PORT_C);
	Motor_init(&rightMotor, NXT_PORT_B);

	// UIに開始待ちを依頼する
	UI_waitStart(&ui);

	// 4ms周期で、シナリオレーサにトレース走行を依頼する
	while(1)
	{
		ScenarioTracer_trace(&scenarioTracer);
		systick_wait_ms(4);
	}
}

