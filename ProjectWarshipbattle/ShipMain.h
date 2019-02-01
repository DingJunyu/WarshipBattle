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
	}
	~ShipMain();

	void RegistrateShipCrashParts();
	void InifThisShip(int *ShipHandle,int ShipNum);
	void ControlThisShip(int Command);

	void ChangeAccPercentage(bool up);
	void CalSpeed();
	void ChangeDirect(bool right);
	void CalDirect();

	void TEST();

private:
	ShipCrashParts * MainParts;
	ShipCrashParts * SubParts;

	Weapon * MainWeapon;
	Weapon * SubWeapon;

	double draft;//�i��
	int shipType;

	int shipHandle[SerialNumberOfShipHandle::ARRAY_SIZE];

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
	
	std::string name;
};