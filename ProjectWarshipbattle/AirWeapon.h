#pragma once
class AirWeapon
{
public:
	AirWeapon(int WT) :weaponType(WT) {}
	~AirWeapon();

	//�c�e���₢���킹
	int ReferAmmoRemained() { return ammoRemain; }
	bool Usable() { return ammoRemain != 0 ? true : false; }

	//�e�Ȃǂ𔭎˂��Ďc�e������
	int UseAmmo() { ammoRemain--; }

	//�������i�e�̐��j
	void SetAmmo(int Amount) { ammoRemain = Amount; maxAmmo = Amount; }

private:
	int weaponType;//�p����Œ��ڒ�`����

	int ammoRemain;
	int maxAmmo;
};
