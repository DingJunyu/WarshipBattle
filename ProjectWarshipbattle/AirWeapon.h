#pragma once
#include"Bomb.h"
#include"Torpedo.h"
class AirWeapon
{
public:
	AirWeapon(int WT) :weaponType(WT) {}
	~AirWeapon();

	int ReferAmmoRemained() { return ammoRemain; }
	int UseAmmo() { ammoRemain--; }

	void SetAmmo(int Amount) { ammoRemain = Amount; }

private:
	int weaponType;
	int ammoRemain;
};

