/****************************************************
 *  BalanceRunner.c                                         
 *  Created on: 2012/05/05 9:05:13                      
 *  Implementation of the Class BalanceRunner       
 *  Original author: hiroyuki.watanabe                     
 ****************************************************/

#include "BalanceRunner.h"
#include "balancer.h" // �|���U�q����p�w�b�_�t�@�C��

#define LOW     30 // �ᑬ
#define NORMAL  50 // �ʏ�
#define HIGH    70 // ����
#define BATT  8000 // �o�b�e���[�d��



// ����������
void BalanceRunner_init(BalanceRunner* this)
{
	this->forward 	    = LOW;
	this->turn          = LOW;
	this->isInitialized = FALSE;
}

// �|�����s���s��
void BalanceRunner_run(BalanceRunner* this, DIRECTION direction)
{
	int turn;			// �����𔽉f�������񑬓x
	unsigned int gyro;		// �W���C���Z���T�l
	unsigned int gyro_offset;	// �W���C���Z���T�I�t�Z�b�g�l
	long motor_ang_l;		// �����[�^��]�p�x
	long motor_ang_r;		// �E���[�^��]�p�x
	signed char pwm_l;		// �����[�^PWM�o�͒l
	signed char pwm_r;		// �E���[�^PWM�o�͒l
	
	// �ŏ������A�|���U�q������������ƃ��[�^�G���R�[�_�̃��Z�b�g���s��
	if(! this->isInitialized)
	{
		balance_init();		// �|���U�q���䏉����
	
		// ���[�^�̉�]�p�x�����Z�b�g����
		Motor_resetAngle(this->leftMotor);
		Motor_resetAngle(this->rightMotor);
	
		// �������ςɂ���
		this->isInitialized = TRUE;
	}
	
	// �w�肳�ꂽ�����ɍ��킹�����񑬓x��ݒ肷��
	if(direction == LEFT)
	{
		turn = this->turn * (-1);
	}
	else if(direction == RIGHT)
	{
		turn = this->turn;
	}
	else
	{
		turn = 0;
	}
	
	// �|���U�q����API �ɓn���p�����[�^���擾����
	gyro_offset = GyroSensor_getOffset(this->gyroSensor);
	gyro = GyroSensor_getAngularVelocity(this->gyroSensor);
	motor_ang_l = Motor_getAngle(this->leftMotor);
	motor_ang_r = Motor_getAngle(this->rightMotor);
	
	// �|���U�q����API���Ăяo���A�|�����s���邽�߂�
	// ���E���[�^�o�͒l�𓾂�
	balance_control(
		(float)this->forward,
		(float)turn,
		(float)gyro, (float)gyro_offset,
		(float)motor_ang_l, (float)motor_ang_r,
		BATT,
		(signed char*)&pwm_l, (signed char*)&pwm_r
	);
	
	// ���E���[�^�ɉ�]���w������
	Motor_rotate(this->leftMotor,pwm_l);
	Motor_rotate(this->rightMotor,pwm_r);
} 




