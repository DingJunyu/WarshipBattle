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
	ShipMain() : AllMovableObjects(false, false, false, true) {}
	~ShipMain();

	void RegistrateShipCrashParts();
	void InifThisShip(int *ShipHandle,int ShipNum);


private:
	ShipCrashParts * MainParts;
	ShipCrashParts * SubParts;

	Weapon * MainWeapon;
	Weapon * SubWeapon;

	double draft;//ãiêÖ
	int ShipType;

	int shipHandle[SerialNumberOfShipHandle::ARRAY_SIZE];
	
	std::string name;
};