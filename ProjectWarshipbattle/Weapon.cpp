#include "Weapon.h"

Weapon::Weapon()
{
}

Weapon::~Weapon()
{
}

Ammo Weapon::Shoot(double x, double z,double r) {
	lastShootedTime = GetTickCount();

	//â‘ÎÀ•W‚ðŒvŽZ‚·‚é
	double realX = cos(radianOnZ + r) * relativeCoordX -
		sin(radianOnZ + r) * relativeCoordZ + x;
	double realZ = cos(radianOnZ + r) * relativeCoordZ +
		sin(radianOnZ + r) * relativeCoordX + z;

	//Å‰‚ÌŠp“x‚ªƒ‰ƒ“ƒ_ƒ€‚É•ÏX‚µ‚ÄÅŒã‚Ì—Ž‰º“_‚É‰e‹¿‚ðã‚°‚é‚æ‚¤‚É‚·‚é
	double realRadianOnZ = radianOnZ + r;
	double targetRandom = rand() % 20;
	if (targetRandom >= 10) {
		realRadianOnZ += RandomDataWhenShoot::radianOnZ * (targetRandom - 9) / 10;
	}
	else {
		realRadianOnZ -= RandomDataWhenShoot::radianOnZ * targetRandom / 10;
	}

	return Ammo(initialSpeed, realRadianOnZ, realX, realZ, high, radianOnY,
		ammoHandle, serialNumber);
}

bool Weapon::ReferShootable() {
	if (lastShootedTime + reloadTime < GetTickCount()) {
		return true;
	}
	return false;
}