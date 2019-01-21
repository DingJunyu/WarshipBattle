#pragma once
#include"AllMovableObjects.h"
#include"AirWeapon.h"
class Plane :
	public AllMovableObjects
{
public:
	Plane() : AllMovableObjects(true, true, false) {}
	~Plane();
private:
	int maxFuel;
	int fuelRemained;
	
};

