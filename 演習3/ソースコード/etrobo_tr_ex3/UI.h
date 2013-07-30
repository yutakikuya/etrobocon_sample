/****************************************************
 *  UI.h                                         
 *  Created on: 2012/05/05 8:58:45                      
 *  Implementation of the Class UI       
 *  Original author: hiroyuki.watanabe                     
 ****************************************************/

#if !defined(EA_FC87B806_F8A2_4205_8009_1F1040CED965__INCLUDED_)
#define EA_FC87B806_F8A2_4205_8009_1F1040CED965__INCLUDED_


#include "TouchSensor.h"


// 属性を保持するための構造体の定義
typedef struct UI
{
	TouchSensor *touchSensor;
} UI;

// 公開操作
void UI_init(UI* this);
void UI_waitStart(UI* this);

#endif /*!defined(EA_FC87B806_F8A2_4205_8009_1F1040CED965__INCLUDED_)*/

