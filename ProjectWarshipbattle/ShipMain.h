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

	//初期化
	void RegistrateShipCrashParts();
	void InifThisShip(int *ShipHandle,int *SShadowH,int ShipNum, 
		EffectTemplate ET,SoundLoader *SL);
	void SetEffectPoint(ShipData SD);
	void DestroyMemory();
	void SetWeaponTest(PictureLoader *PL);
	void SetWeapon();

	void DrawShip(Camera CM);

	//コントロール
	void ControlThisShip(int Command);

	//移動関連
	void ChangeAccPercentage(bool up);
	void CalSpeed();
	void ChangeDirect(bool right);
	void ReturnDirectChange() { returnToCenter = ! returnToCenter; }
	void Alignment();

	void TEST();
	void TestDraw(double x,double z);

	//問い合わせ
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

	//エフェクト生成
	Effect NewBubble(int num);
	Effect NewSmoke(int num);

	void CheckAndPlaySound();

	/*射撃*/
	int HowManyWeaponYouHave() { return MainWeaponCount; }
	bool IsThisOneUsable(int Num, bool Main);
	Ammo Shoot(int Num, bool Main);



private:
	ShipCrashParts * MainParts;
	ShipCrashParts * SubParts;
	double shipCrashR;
	/*自分の弾が自分に当たらないように使用する番号です*/
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

	/*砲のステータス変更*/
	bool TurnMainWeapon(bool right);
	bool PullMainWeapon(bool up);

	double draft;//喫水:魚雷を使う時に使うデータです。
	int shipType;

	int *shipHandle[SerialNumberOfShipHandle::ARRAY_SIZE];

	/*エンジンシステムを実装する前に移動の部分は以下のデータを実現する*/
	double maxSpeed;
	double maxAcc;
	double currentAccPercentage;
	double minAccPercentageeLostToSpeedPercentage;
	double accPercentageLostToSpeedPercentage;
	double minAccNeedatMaxSpeed;

	//方向舵
	double maxRadian;
	double currentRadian;
	double radianChangePerFrame;
	bool returnToCenter;
	
	std::string name;

	/*音声関連*/
	/*ホードの種類はまだ決まってないので今は使っていない*/
	void LoadSound(SoundLoader *SL);
	int *soundEngine;
	int *soundMoving;
	int *soundSlow;
	int *soundTurning;
	int HordType;
	int *soundHordHigh;
	int *soundHordLow;
};