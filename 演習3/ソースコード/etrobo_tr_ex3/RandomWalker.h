/****************************************************
 *  RandomWalker.h                                         
 *  Created on: 2012/05/05 22:20:47                      
 *  Implementation of the Class RandomWalker       
 *  Original author: hiroyuki.watanabe                     
 ****************************************************/

#if !defined(EA_C9F8BA56_B8EA_4eb2_87DF_95C16E8EFFFA__INCLUDED_)
#define EA_C9F8BA56_B8EA_4eb2_87DF_95C16E8EFFFA__INCLUDED_

#include "LineTracer.h"
#include "ScenarioTracer.h"

/*状態の定義列挙値*/
typedef enum RW_State
{
	LINE_TRACE,
	STOP,
	SCENARIO_TRACE,
} RW_STATE;

// 属性を保持するための構造体の定義
typedef struct RandomWalker
{
	RW_STATE state;
	int time;
	int runtime;
	LineTracer *lineTracer;
	ScenarioTracer *scenarioTracer;
} RandomWalker;

// 公開操作
void RandomWalker_init(RandomWalker* this);
void RandomWalker_run(RandomWalker* this);

#endif /*!defined(EA_C9F8BA56_B8EA_4eb2_87DF_95C16E8EFFFA__INCLUDED_)*/

