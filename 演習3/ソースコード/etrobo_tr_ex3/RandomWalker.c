/****************************************************
 *  RandomWalker.c                                         
 *  Created on: 2012/05/05 22:20:50                      
 *  Implementation of the Class RandomWalker       
 *  Original author: hiroyuki.watanabe                     
 ****************************************************/

#include "RandomWalker.h"
#include <stdlib.h>

#define	TASK_CYCLE	4	// �^�X�N�̎����imsec�j
#define MIN		5000	// �؂�ւ����Ԃ̍ŏ��l�i5�b�j
#define MAX		15000	// �؂�ւ����Ԃ̍ő�l�i15�b�j


// ����J����
static int RandomWalker_getRandom(RandomWalker* this, int min, int max);
static void RandomWalker_reset(RandomWalker* this);
static void RandomWalker_run_LINE_TRACE(RandomWalker* this);
static void RandomWalker_run_STOP(RandomWalker* this);
static void RandomWalker_run_SCENARIO_TRACE(RandomWalker* this);

// ����������
void RandomWalker_init(RandomWalker* this)
{
	this->state   = STOP;			// ��Ԃ��~���ɂ���
	this->time    = 0;			// �؂�ւ����Ԃ����Z�b�g����
	this->runtime = 0;			// ���s���Ԃ����Z�b�g����
	srand((unsigned)systick_get_ms());	// ���������Z�b�g����
}

// �������擾����
static int RandomWalker_getRandom(RandomWalker* this, int min, int max)
{
	return min + (int)((double)rand()*(max-min+1.0)/(1.0+RAND_MAX));
}

// �؂�ւ����Ԃ����Z�b�g����
static void RandomWalker_reset(RandomWalker* this)
{
	ecrobot_sound_tone(1000, 100, 50);	// �؂�ւ��̍��}
	this->runtime = 0;
	this->time = RandomWalker_getRandom(this, MIN, MAX);
} 

// ���s����
void RandomWalker_run(RandomWalker* this)
{
	switch(this->state)
	{
		case LINE_TRACE:
			RandomWalker_run_LINE_TRACE(this);
			break;

		case STOP:
			RandomWalker_run_STOP(this);
			break;

		case SCENARIO_TRACE:
			RandomWalker_run_SCENARIO_TRACE(this);
			break;

		default:
			break;
	}
}

// ���C���g���[�X���̎��s����
static void RandomWalker_run_LINE_TRACE(RandomWalker* this)
{
	// ���Z�������s���Ԃ��؂�ւ����Ԃ𒴂�����A�V���Ȑ؂�ւ����Ԃ�
	// ���Z�b�g���ăV�i���I�g���[�X���ɑJ�ڂ���
	this->runtime += TASK_CYCLE;
	if(this->runtime >= this->time)
	{
		// �؂�ւ����Ԃ����Z�b�g����
		RandomWalker_reset(this);

		// �V�i���I�g���[�X���s���ientry�A�N�V�����j
		this->state = SCENARIO_TRACE;
		ScenarioTracer_trace(this->scenarioTracer);
	}
	else
	{
		// ���C���g���[�X���s���ientry�A�N�V�����j
		this->state = LINE_TRACE;
		LineTracer_trace(this->lineTracer);
	}
}

// ��~���̎��s����
static void RandomWalker_run_STOP(RandomWalker* this)
{
	// �؂�ւ����Ԃ����Z�b�g����
	RandomWalker_reset(this);

	// ���C���g���[�X���s���ientry�A�N�V�����j
	this->state = LINE_TRACE;
	LineTracer_trace(this->lineTracer);
}

// �V�i���I�g���[�X���̎��s����
static void RandomWalker_run_SCENARIO_TRACE(RandomWalker* this)
{
	// ���Z�������s���Ԃ��؂�ւ����Ԃ𒴂�����A�V���Ȑ؂�ւ����Ԃ�
	// ���Z�b�g���ă��C���g���[�X���ɑJ�ڂ���
	this->runtime += TASK_CYCLE;
	if(this->runtime >= this->time)
	{
		// �؂�ւ����Ԃ����Z�b�g����
		RandomWalker_reset(this);

		// ���C���g���[�X���s���ientry�A�N�V�����j
		this->state = LINE_TRACE;
		LineTracer_trace(this->lineTracer);
	}
	else
	{
		// �V�i���I�g���[�X���s���ientry�A�N�V�����j
		this->state = SCENARIO_TRACE;
		ScenarioTracer_trace(this->scenarioTracer);
	}
}



