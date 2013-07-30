/****************************************************
 *  ScenarioTracer.c                                         
 *  Created on: 2012/05/05 9:09:03                      
 *  Implementation of the Class ScenarioTracer       
 *  Original author: hiroyuki.watanabe                     
 ****************************************************/

#include "ScenarioTracer.h"
#define	TASK_CYCLE	4	// �^�X�N�̎����imsec�j


// ����J����
static void ScenarioTracer_updateScenario(ScenarioTracer* this);


void ScenarioTracer_init(ScenarioTracer* this, int countScenario)
{
	this->countScenario = countScenario;	// �V�i���I��
	this->currentScenario = 0;		// ���݂̃V�i���I�ʒu���Z�b�g
	this->runtime = 0;			// ���s���Ԃ����Z�b�g
}

void ScenarioTracer_trace(ScenarioTracer* this)
{
	if(this->runtime
	     >= this->scenarios[this->currentScenario]->time)
	{
		// �V�i���I�Ŏw�肳�ꂽ���s���Ԃ��o�߂�����A
		// �V�i���I���X�V���A���s���Ԃ����Z�b�g����
		ScenarioTracer_updateScenario(this);
		this->runtime = 0;
	}
	
	// ���݂̃V�i���I�ɏ�����Ă�������ŁA
	// �|�����s�ɑ��s���˗�����
	BalanceRunner_run(
		this->balanceRunner, 
		this->scenarios[this->currentScenario]->direction);
	
	this->runtime += TASK_CYCLE;	// ���s���Ԃ����Z����
}

static void ScenarioTracer_updateScenario(ScenarioTracer* this)
{
	if(this->currentScenario < this->countScenario)
	{
		// ���̃V�i���I����
		// �ˎ��̃V�i���I�����݂̃V�i���I�ɂ���
		this->currentScenario++;
	}
	else
	{
		// ���̃V�i���I�Ȃ�
		// �ˁ@�擪�̃V�i���I�����݂̃V�i���I�ɂ���
		this->currentScenario = 0;
	}
} 




