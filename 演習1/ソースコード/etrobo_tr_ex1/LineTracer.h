/****************************************************
 *  LineTracer.h                                         
 *  Created on: 2012/05/05 8:31:07                      
 *  Implementation of the Class LineTracer       
 *  Original author: hiroyuki.watanabe                     
 ****************************************************/

#if !defined(EA_6FB55B53_C0F0_4250_B6B0_BC28A0A336D7__INCLUDED_)
#define EA_6FB55B53_C0F0_4250_B6B0_BC28A0A336D7__INCLUDED_

#include "ColorJudgement.h"
#include "BalanceRunner.h"


// 属性を保持するための構造体の定義
typedef struct LineTracer
{
	ColorJudgement *colorJudgement;
	BalanceRunner *balanceRunner;
} LineTracer;

// 公開操作
void LineTracer_init(LineTracer* this);
void LineTracer_trace(LineTracer* this);

#endif /*!defined(EA_6FB55B53_C0F0_4250_B6B0_BC28A0A336D7__INCLUDED_)*/

