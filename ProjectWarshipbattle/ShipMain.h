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
	void SetWeaponTest(PictureLoader *PL);
	void SetWeapon();

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
	int ReferWeaponCount(bool Main) { 
		if (Main)
			return MainWeaponCount;
		else
			return SubWeaponCount;
	}
	double ReferShipCrashR() { return shipCrashR; }
	int ReferSerialNumber() { return serialNumber; }
	double ReferMainWeaponRadianOnZ() {
		return MainWeapon[0].ReferRadianOnZ();
	}
	double ReferMainWeaponCD() { return
		GetTickCount() - MainWeapon[0].ReferLastShootedTime(); }
	double ReferMainWeaponCoolDownTime() {
		return MainWeapon[0].ReferReloadTime();
	}

	//�G�t�F�N�g����
	Effect NewBubble(int num);
	Effect NewSmoke(int num);

	void CheckAndPlaySound();

	/*�ˌ�*/
	int HowManyWeaponYouHave() { return MainWeaponCount; }
	bool IsThisOneUsable(int Num, bool Main);
	Ammo Shoot(int Num, bool Main);



private:
	ShipCrashParts * MainParts;
	ShipCrashParts * SubParts;
	double shipCrashR;
	/*�����̒e�������ɓ�����Ȃ��悤�Ɏg�p����ԍ��ł�*/
	int serialNumber;

	Weapon * MainWeapon;
	int MainWeaponCount;
	Weapon * SubWeapon;
	int SubWeaponCount;

	EffectPoint * bubbleStartPoint;
	int bubblePointCount;

	EffectPoint * smokeStartPoint;
	int smokePointCount;

	void MemorySecure();

	/*�C�̃X�e�[�^�X�ύX*/
	bool TurnMainWeapon(bool right);
	bool PullMainWeapon(bool up);

	double draft;//�i��:�������g�����Ɏg���f�[�^�ł��B
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