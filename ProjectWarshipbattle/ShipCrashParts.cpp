#include "ShipCrashParts.h"



ShipCrashParts::ShipCrashParts()
{
	damaged = false;
	isMainPart = false;
}


ShipCrashParts::~ShipCrashParts()
{
}

void ShipCrashParts::MinusHP(double damage) {
	heartPoint -= damage;
	if (heartPoint <= 0)
		damaged = true;
}