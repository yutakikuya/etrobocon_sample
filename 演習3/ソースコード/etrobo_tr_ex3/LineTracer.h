/****************************************************
 *  LineTracer.h                                         
 *  Created on: 2012/05/05 11:16:11                      
 *  Implementation of the Class LineTracer       
 *  Original author: hiroyuki.watanabe                     
 ****************************************************/

#if !defined(EA_EAE750CB_6FDB_4099_9556_295270797231__INCLUDED_)
#define EA_EAE750CB_6FDB_4099_9556_295270797231__INCLUDED_


#include "ColorJudgement.h"
#include "BalanceRunner.h"


// ‘®«‚ğ•Û‚·‚é‚½‚ß‚Ì\‘¢‘Ì‚Ì’è‹`
typedef struct LineTracer
{
	ColorJudgement *colorJudgement;
	BalanceRunner *balanceRunner;
} LineTracer;

// ŒöŠJ‘€ì
void LineTracer_init(LineTracer* this);
void LineTracer_trace(LineTracer* this);

#endif /*!defined(EA_EAE750CB_6FDB_4099_9556_295270797231__INCLUDED_)*/

