///////////////////////////////////////////////////////////
//  model_impl.c
///////////////////////////////////////////////////////////

#include "LineTracer.h"
#include "ColorJudgement.h"
#include "BalanceRunner.h"
#include "LightSensor.h"
#include "GyroSensor.h"
#include "Motor.h"

#include "kernel.h"
#include "kernel_id.h"
#include "ecrobot_interface.h"

// �I�u�W�F�N�g��ÓI�Ɋm�ۂ���
LineTracer 	lineTracer;
ColorJudgement 	colorJudgement;
BalanceRunner 	balanceRunner;
LightSensor 	lightSensor;
GyroSensor 	gyroSensor;
Motor 		leftMotor, rightMotor;

// �f�o�C�X�������p�t�b�N�֐�
// ���̊֐���nxtOSEK�N�����Ɏ��s����܂��B
void ecrobot_device_initialize()
{
	// �Z���T�A���[�^�Ȃǂ̊e�f�o�C�X�̏������֐���
	// �����Ŏ������邱�Ƃ��ł��܂�
	// �ˁ@���Z���T�ԐFLED��ON�ɂ���
	ecrobot_set_light_sensor_active(NXT_PORT_S3);
}

// �f�o�C�X�I���p�t�b�N�֐�
// ���̊֐���STOP�܂���EXIT�{�^���������ꂽ���Ɏ��s����܂��B
void ecrobot_device_terminate()
{
	// �Z���T�A���[�^�Ȃǂ̊e�f�o�C�X�̏I���֐���
	// �����Ŏ������邱�Ƃ��ł��܂��B
	// �ˁ@���Z���T�ԐFLED��OFF�ɂ���
	ecrobot_set_light_sensor_inactive(NXT_PORT_S3);
}

// 1msec�������荞��(ISR�J�e�S��2)����N������郆�[�U�[�p�t�b�N�֐�
void user_1ms_isr_type2(void)
{
	// ����͉����s��Ȃ�
}

TASK(TaskMain)
{
	// �I�u�W�F�N�g�Ԃ̃����N���\�z����
	lineTracer.colorJudgement  = &colorJudgement;
	lineTracer.balanceRunner   = &balanceRunner;
	colorJudgement.lightSensor = &lightSensor;
	balanceRunner.gyroSensor   = &gyroSensor;
	balanceRunner.leftMotor    = &leftMotor;
	balanceRunner.rightMotor   = &rightMotor;

	// �e�I�u�W�F�N�g������������
	LineTracer_init(&lineTracer);
	ColorJudgement_init(&colorJudgement);
	BalanceRunner_init(&balanceRunner);
	LightSensor_init(&lightSensor, NXT_PORT_S3);
	GyroSensor_init(&gyroSensor, NXT_PORT_S1);
	Motor_init(&leftMotor, NXT_PORT_C);
	Motor_init(&rightMotor, NXT_PORT_B);

	// 4ms�����ŁA���C���g���[�T�Ƀg���[�X���s���˗�����
	while(1)
	{
		LineTracer_trace(&lineTracer);
		systick_wait_ms(4);
	}
}

