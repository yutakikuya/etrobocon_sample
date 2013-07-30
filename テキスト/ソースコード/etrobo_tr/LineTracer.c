/****************************************************
 *  LineTracer.c                                         
 *  Created on: 2012/05/05 7:35:10                      
 *  Implementation of the Class LineTracer       
 *  Original author: hiroyuki.watanabe                     
 ****************************************************/

#include "LineTracer.h"
#include "Direction.h"
#include "Color.h"



// 非公開操作
static DIRECTION LineTracer_calcDirection(LineTracer* this, COLOR color);


// 初期化する
void LineTracer_init(LineTracer* this)
{
	// 何も行わない
}

// ライントレースを行う
void LineTracer_trace(LineTracer* this)
{
	COLOR color;			// 路面の色
	DIRECTION direction;		// 走行体の向き
	
	// 路面の色を判定する
	color = ColorJudgement_judgeColor(this->colorJudgement);
	
	// 走行体の向きを計算する
	direction = LineTracer_calcDirection(this, color);
	
	// 倒立走行を行う
	BalanceRunner_run(this->balanceRunner, direction);
}

static DIRECTION LineTracer_calcDirection(LineTracer* this, COLOR color)
{
	// ラインの左エッジ走行を前提として、
	if(color == BLACK)
	{
		// 路面の色が黒ならばライン上と判断して左へ旋回
		return LEFT;
	}
	else
	{
		// 路面の色が黒以外ならばライン外と判断して右へ旋回
		return RIGHT;
	}
} 




