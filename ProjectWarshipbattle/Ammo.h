#pragma once
#include "AllMovableObjects.h"
class Ammo :
	public AllMovableObjects
{
public:
	Ammo() : AllMovableObjects(true, false, true, true) {}
	~Ammo();

	double ReferDamage() { return damage; }
	void SetData();
	
private:
	double penetrateDepth;
	double damage;

	int *effectHandle;
};

