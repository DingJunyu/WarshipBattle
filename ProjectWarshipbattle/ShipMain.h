#pragma once
#include"AllMovableObjects.h"
#include"ShipCrashParts.h"
#include"DefinedData.h"
#include"IncludeForAll.h"
#include"Weapon.h"
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
	void InifThisShip(int *ShipHandle,int ShipNum);

	//コントロール
	void ControlThisShip(int Command);

	//移動関連
	void ChangeAccPercentage(bool up);
	void CalSpeed();
	void ChangeDirect(bool right);
	void ReturnDirectChange() { returnToCenter = ! returnToCenter; }
	void Alignment();

	void TEST();

	//問い合わせ
	bool ReferReturnOn() { return returnToCenter; }
	double ReferChangingRadian() { return currentRadian; }

private:
	ShipCrashParts * MainParts;
	ShipCrashParts * SubParts;

	Weapon * MainWeapon;
	Weapon * SubWeapon;

	double draft;//喫水
	int shipType;

	int shipHandle[SerialNumberOfShipHandle::ARRAY_SIZE];

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
};