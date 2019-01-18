#pragma once
#include"AllMovableObjects.h"
#include"ShipCrashParts.h"
class ShipMain :
	public AllMovableObjects
{
public:
	ShipMain() : AllMovableObjects(true, false) {}
	~ShipMain();

private:
	ShipCrashParts * MainParts;
};