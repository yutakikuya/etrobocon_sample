/****************************************************
 *  LineTracer.c                                         
 *  Created on: 2012/05/05 7:35:10                      
 *  Implementation of the Class LineTracer       
 *  Original author: hiroyuki.watanabe                     
 ****************************************************/

#include "LineTracer.h"
#include "Direction.h"
#include "Color.h"



// ����J����
static DIRECTION LineTracer_calcDirection(LineTracer* this, COLOR color);


// ����������
void LineTracer_init(LineTracer* this)
{
	// �����s��Ȃ�
}

// ���C���g���[�X���s��
void LineTracer_trace(LineTracer* this)
{
	COLOR color;			// �H�ʂ̐F
	DIRECTION direction;		// ���s�̂̌���
	
	// �H�ʂ̐F�𔻒肷��
	color = ColorJudgement_judgeColor(this->colorJudgement);
	
	// ���s�̂̌������v�Z����
	direction = LineTracer_calcDirection(this, color);
	
	// �|�����s���s��
	BalanceRunner_run(this->balanceRunner, direction);
}

static DIRECTION LineTracer_calcDirection(LineTracer* this, COLOR color)
{
	// ���C���̍��G�b�W���s��O��Ƃ��āA
	if(color == BLACK)
	{
		// �H�ʂ̐F�����Ȃ�΃��C����Ɣ��f���č��֐���
		return LEFT;
	}
	else
	{
		// �H�ʂ̐F�����ȊO�Ȃ�΃��C���O�Ɣ��f���ĉE�֐���
		return RIGHT;
	}
} 




