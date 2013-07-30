/****************************************************
 *  Scenario.h                                         
 *  Created on: 2012/05/05 8:45:31                      
 *  Implementation of the Class Scenario       
 *  Original author: hiroyuki.watanabe                     
 ****************************************************/

#if !defined(EA_338B6E18_0009_4d28_A537_3043831C23C6__INCLUDED_)
#define EA_338B6E18_0009_4d28_A537_3043831C23C6__INCLUDED_


#include "Direction.h"


// 属性を保持するための構造体の定義
typedef struct Scenario
{
	DIRECTION direction;
	short time;
} Scenario;



#endif /*!defined(EA_338B6E18_0009_4d28_A537_3043831C23C6__INCLUDED_)*/

