#include "Weapon.h"

Weapon::Weapon()
{
}

Weapon::~Weapon()
{
}

Ammo Weapon::Shoot(double x, double z) {
	lastShootedTime = GetTickCount();

	double realX = cos(radianOnZ) * relativeCoordX -
		sin(radianOnZ) * relativeCoordZ + x;
	double realZ = cos(radianOnZ) * relativeCoordZ +
		sin(radianOnZ) * relativeCoordX + z;

	return Ammo(initialSpeed,radianOnZ,realX,realZ,radianOnY,
		ammoHandle);
}

bool Weapon::ReferShootable() {
	if (lastShootedTime + reloadTime < GetTickCount()) {
		return true;
	}
	return false;
}