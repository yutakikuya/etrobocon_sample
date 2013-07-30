/****************************************************
 *  RandomWalker.c                                         
 *  Created on: 2012/05/05 22:20:50                      
 *  Implementation of the Class RandomWalker       
 *  Original author: hiroyuki.watanabe                     
 ****************************************************/

#include "RandomWalker.h"
#include <stdlib.h>

#define	TASK_CYCLE	4	// タスクの周期（msec）
#define MIN		5000	// 切り替え時間の最小値（5秒）
#define MAX		15000	// 切り替え時間の最大値（15秒）


// 非公開操作
static int RandomWalker_getRandom(RandomWalker* this, int min, int max);
static void RandomWalker_reset(RandomWalker* this);
static void RandomWalker_run_LINE_TRACE(RandomWalker* this);
static void RandomWalker_run_STOP(RandomWalker* this);
static void RandomWalker_run_SCENARIO_TRACE(RandomWalker* this);

// 初期化する
void RandomWalker_init(RandomWalker* this)
{
	this->state   = STOP;			// 状態を停止中にする
	this->time    = 0;			// 切り替え時間をリセットする
	this->runtime = 0;			// 走行時間をリセットする
	srand((unsigned)systick_get_ms());	// 乱数をリセットする
}

// 乱数を取得する
static int RandomWalker_getRandom(RandomWalker* this, int min, int max)
{
	return min + (int)((double)rand()*(max-min+1.0)/(1.0+RAND_MAX));
}

// 切り替え時間をリセットする
static void RandomWalker_reset(RandomWalker* this)
{
	ecrobot_sound_tone(1000, 100, 50);	// 切り替えの合図
	this->runtime = 0;
	this->time = RandomWalker_getRandom(this, MIN, MAX);
} 

// 実行する
void RandomWalker_run(RandomWalker* this)
{
	switch(this->state)
	{
		case LINE_TRACE:
			RandomWalker_run_LINE_TRACE(this);
			break;

		case STOP:
			RandomWalker_run_STOP(this);
			break;

		case SCENARIO_TRACE:
			RandomWalker_run_SCENARIO_TRACE(this);
			break;

		default:
			break;
	}
}

// ライントレース中の実行処理
static void RandomWalker_run_LINE_TRACE(RandomWalker* this)
{
	// 加算した走行時間が切り替え時間を超えたら、新たな切り替え時間に
	// リセットしてシナリオトレース中に遷移する
	this->runtime += TASK_CYCLE;
	if(this->runtime >= this->time)
	{
		// 切り替え時間をリセットする
		RandomWalker_reset(this);

		// シナリオトレースを行う（entryアクション）
		this->state = SCENARIO_TRACE;
		ScenarioTracer_trace(this->scenarioTracer);
	}
	else
	{
		// ライントレースを行う（entryアクション）
		this->state = LINE_TRACE;
		LineTracer_trace(this->lineTracer);
	}
}

// 停止中の実行処理
static void RandomWalker_run_STOP(RandomWalker* this)
{
	// 切り替え時間をリセットする
	RandomWalker_reset(this);

	// ライントレースを行う（entryアクション）
	this->state = LINE_TRACE;
	LineTracer_trace(this->lineTracer);
}

// シナリオトレース中の実行処理
static void RandomWalker_run_SCENARIO_TRACE(RandomWalker* this)
{
	// 加算した走行時間が切り替え時間を超えたら、新たな切り替え時間に
	// リセットしてライントレース中に遷移する
	this->runtime += TASK_CYCLE;
	if(this->runtime >= this->time)
	{
		// 切り替え時間をリセットする
		RandomWalker_reset(this);

		// ライントレースを行う（entryアクション）
		this->state = LINE_TRACE;
		LineTracer_trace(this->lineTracer);
	}
	else
	{
		// シナリオトレースを行う（entryアクション）
		this->state = SCENARIO_TRACE;
		ScenarioTracer_trace(this->scenarioTracer);
	}
}



