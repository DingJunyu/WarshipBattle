#pragma once
#include "AirWeapon.h"
#include"DefinedData.h"
#include"Bomb.h"
class BombLoader :
	public AirWeapon
{
public:
	BombLoader() :AirWeapon(BOMB_PW){}
	~BombLoader();

	bool Usable() { return (ReferAmmoRemained() != 0) ?  true : false; }
	Bomb DropTheBomb();

private:
	Bomb Booooom;
};

