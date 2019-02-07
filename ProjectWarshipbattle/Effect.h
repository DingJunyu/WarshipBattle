#pragma once
#include"DxLib.h"
#include"DefinedData.h"
#include<time.h>
#include<cmath>
class Effect
{
public:
	Effect(bool Movable,  int continueTime, double R,
		double TRadian, double RCPF,double Speed, double CX,
		double CZ,int *GH) :
		movable(Movable),
		timeUp(false), endTime(GetNowCount() + continueTime),
		radian(R),targetRadian(TRadian),radianChangePerFrame(RCPF),
		speed(Speed),coordX(CX),coordZ(CZ){}
	~Effect();

	void Draw();
	void Move();

	//���Ԃɉ߂��������
	bool ReferTimeUp() { return timeUp; }

	void SetGraphHandle(int *GH) { graphicHandle = GH; }

private:
	void Check();
	//�G�t�F�N�g�̃^�C�v�ƈړ��ł��邩
	bool movable;
	int type;
	//���W�Ȃ�
	double radian;
	double targetRadian;
	double radianChangePerFrame;
	double coordX;
	double coordZ;
	double speed;
	//�摜�f�[�^
	int *graphicHandle;
	int graphX;
	int graphZ;
	int *animationHandle;
	//��������
	int endTime;
	bool timeUp;
};

