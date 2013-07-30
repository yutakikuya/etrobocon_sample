/****************************************************
 *  UI.h                                         
 *  Created on: 2012/05/05 8:28:46                      
 *  Implementation of the Class UI       
 *  Original author: hiroyuki.watanabe                     
 ****************************************************/

#if !defined(EA_FB3DF40C_CBF0_454a_9BA8_39674A045269__INCLUDED_)
#define EA_FB3DF40C_CBF0_454a_9BA8_39674A045269__INCLUDED_

#include "TouchSensor.h"


// 属性を保持するための構造体の定義
typedef struct UI
{
	TouchSensor *touchSensor;
} UI;

// 公開操作
void UI_init(UI* this);
void UI_waitStart(UI* this);

#endif /*!defined(EA_FB3DF40C_CBF0_454a_9BA8_39674A045269__INCLUDED_)*/

