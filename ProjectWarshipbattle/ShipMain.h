#pragma once
#include"AllMovableObjects.h"
#include"ShipCrashParts.h"
#include"DefinedData.h"
#include"IncludeForAll.h"
#include"Weapon.h"
#include"Camera.h"
#include"EffectPoint.h"
#include"ShipData.h"
#include"EffectTemplate.h"
#include"SoundLoader.h"
class ShipMain :
	public AllMovableObjects
{
public:
	ShipMain() : AllMovableObjects(false, false, false, true) {
		currentAccPercentage = 0;
		returnToCenter = false;
	}
	~ShipMain();



	//������
	void RegistrateShipCrashParts();
	void InifThisShip(int *ShipHandle,int *SShadowH,int ShipNum, 
		EffectTemplate ET,SoundLoader *SL);
	void SetEffectPoint(ShipData SD);
	void DestroyMemory();

	void DrawShip(Camera CM);

	//�R���g���[��
	void ControlThisShip(int Command);

	//�ړ��֘A
	void ChangeAccPercentage(bool up);
	void CalSpeed();
	void ChangeDirect(bool right);
	void ReturnDirectChange() { returnToCenter = ! returnToCenter; }
	void Alignment();

	void TEST();
	void TestDraw(double x,double z);

	//�₢���킹
	bool ReferReturnOn() { return returnToCenter; }
	double ReferChangingRadian() { return currentRadian; }
	double ReferOutPutRate() { return currentAccPercentage; }

	//�G�t�F�N�g����
	Effect NewBubble(int num);
	Effect NewSmoke(int num);

	void CheckAndPlaySound();

private:
	ShipCrashParts * MainParts;
	ShipCrashParts * SubParts;

	Weapon * MainWeapon;
	Weapon * SubWeapon;

	EffectPoint * bubbleStartPoint;
	int bubblePointCount;

	EffectPoint * smokeStartPoint;
	int smokePointCount;

	void MemorySecure();

	double draft;//�i��
	int shipType;

	int *shipHandle[SerialNumberOfShipHandle::ARRAY_SIZE];

	/*�G���W���V�X�e������������O�Ɉړ��̕����͈ȉ��̃f�[�^����������*/
	double maxSpeed;
	double maxAcc;
	double currentAccPercentage;
	double minAccPercentageeLostToSpeedPercentage;
	double accPercentageLostToSpeedPercentage;
	double minAccNeedatMaxSpeed;

	//������
	double maxRadian;
	double currentRadian;
	double radianChangePerFrame;
	bool returnToCenter;
	
	std::string name;

	/*�����֘A*/
	/*�z�[�h�̎�ނ͂܂����܂��ĂȂ��̂ō��͎g���Ă��Ȃ�*/
	void LoadSound(SoundLoader *SL);
	int *soundEngine;
	int *soundMoving;
	int *soundSlow;
	int *soundTurning;
	int HordType;
	int *soundHordHigh;
	int *soundHordLow;
};