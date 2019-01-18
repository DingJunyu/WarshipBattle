#pragma once
#include "AllMovableObjects.h"
class Bomb :
	public AllMovableObjects
{
public:
	Bomb() : AllMovableObjects(true,false){}
	~Bomb();

private:
	double damageRange;
	double damage;
};

