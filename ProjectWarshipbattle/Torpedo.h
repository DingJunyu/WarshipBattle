#pragma once
#include "AllMovableObjects.h"
class Torpedo :
	public AllMovableObjects
{
public:
	Torpedo() : AllMovableObjects(true, false, true) {}
	~Torpedo();

private:
	double depth;
};

