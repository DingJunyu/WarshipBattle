#pragma once
#include"Ammo.h"
#include"Torpedo.h"
class Weapon
{
public:
	Weapon();
	Weapon(double RCX, double RCZ, double L, double W,
		double ROZ, double ROY,int MHP,double AOS,double AOT,
		int *aH,int iS,double H) :
		relativeCoordX(RCX),relativeCoordZ(RCZ),length(L),
		width(W),radianOnZ(ROZ),radianOnY(ROY),heartPoint(MHP),
		maxHeartPoint(MHP),armorOntheSide(AOS),armorOntheTop(AOT),
		ammoHandle(aH), initialSpeed(iS), high(H) {
		lastShootedTime = 0;
	}
	~Weapon();

	//�f�[�^�₢���킹�֐�
	int ReferNumbefofGuns() { return numberofGuns; }
	int ReferReloadTime() { return reloadTime; }
	int ReferLastShootedTime() { return lastShootedTime; }
	double ReferCalibre() { return calibre; }
	double ReferRelativeCoordX() { return relativeCoordX; }
	double ReferRelativeCoordZ() { return relativeCoordZ; }
	double ReferLength() { return length; }
	double ReferWidth() { return width; }
	double ReferRadianOnZ() { return radianOnZ; }
	double ReferRadianOnY() { return radianOnY; }
	double ReferHP() { return heartPoint; }
	double ReferMaxHP() { return maxHeartPoint; }
	double ReferArmorOntheSide() { return armorOntheSide; }
	double ReferArmorOntheTop() { return armorOntheTop; }

	void SetCoolDownTime(int time) { reloadTime = time; }
	void TurnRight() { radianOnZ += MathAndPhysics::PI * (5 / 180); }
	void TurnLeft() { radianOnZ -= MathAndPhysics::PI*(5 / 180); }

	//��Ԗ₢���킹�֐�
	bool ReferShootable();//�ˌ��ł����true��߂�
	
	Ammo Shoot(double x, double y,double r);


private:
	int numberofGuns;//�C���̘A����
	unsigned int reloadTime;//�đ��U�̎���
	unsigned int lastShootedTime;//�O��ˌ���������
	double calibre;

	int *turrentHandle;//�摜�f�[�^�ۑ��p
	int *ammoHandle;

	double initialSpeed;//�����x
	
	double relativeCoordX;
	double relativeCoordZ;
	double length;
	double width;
	double radianOnZ;//�����ʂ̊p�x
	double radianOnY;//�C�g�̊p�x-->����ŖC�e�����ʒu�𐄒肷��

	double high;

	int heartPoint;
	int maxHeartPoint;
	double armorOntheSide;
	double armorOntheTop;
};