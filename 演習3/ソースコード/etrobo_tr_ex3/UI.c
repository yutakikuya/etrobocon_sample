/****************************************************
 *  UI.c                                         
 *  Created on: 2012/05/05 8:58:45                      
 *  Implementation of the Class UI       
 *  Original author: hiroyuki.watanabe                     
 ****************************************************/

#include "UI.h"


void UI_init(UI* this)
{
	// 何もしない
}

void UI_waitStart(UI* this)
{
	// タッチセンサが押されるまで、待ち続ける
	while(1)
	{
		if(TouchSensor_isPressed(this->touchSensor))
		{
			break;		// タッチセンサが押された
		}
	}
} 




