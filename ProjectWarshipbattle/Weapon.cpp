#include "Weapon.h"

Weapon::Weapon()
{
}

Weapon::~Weapon()
{
}

Ammo Weapon::Shoot(int x, int z) {
	lastShootedTime = GetTickCount();

	double realX = cos(radianOnZ) * relativeCoordX -
		sin(radianOnZ) * relativeCoordZ + x;
	double realZ = cos(radianOnZ) * relativeCoordZ +
		sin(radianOnZ) * relativeCoordX + z;

	return Ammo(initialSpeed,radianOnZ,realX,realZ,radianOnY);
}

bool Weapon::ReferShootable() {
	if (lastShootedTime + reloadTime < GetTickCount()) {
		return true;
	}
	return false;
}