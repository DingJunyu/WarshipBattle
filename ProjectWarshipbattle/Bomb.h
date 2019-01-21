#pragma once
#include "AllMovableObjects.h"
class Bomb :
	public AllMovableObjects
{
public:
	Bomb() : AllMovableObjects(true, false, true) {}
	~Bomb();

private:
	double damageRange;
	double damage;
};

