#include "Weapon.h"

Weapon::Weapon()
{
}

Weapon::~Weapon()
{
}

Ammo Weapon::Shoot(double x, double z,double r) {
	lastShootedTime = GetTickCount();

	//��΍��W���v�Z����
	double realX = cos(radianOnZ + r) * relativeCoordX -
		sin(radianOnZ + r) * relativeCoordZ + x;
	double realZ = cos(radianOnZ + r) * relativeCoordZ +
		sin(radianOnZ + r) * relativeCoordX + z;

	//�ŏ��̊p�x�������_���ɕύX���čŌ�̗����_�ɉe�����グ��悤�ɂ���
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