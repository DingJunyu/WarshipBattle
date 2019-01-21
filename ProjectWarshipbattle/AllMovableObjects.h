#pragma once
#include<cmath>
const double GRAVITATIONAL_ACCELERATION = 9.80665;
const int GRAVITATIONAL_ACCELERATION_INT = 10;
const double MIN_AIR_RESISTANCE = 0.5;

class AllMovableObjects
{
public:
	AllMovableObjects(bool fly, bool pla, bool poi) : flyable(fly),
		plane(pla), alive(true), point(poi) {}
	~AllMovableObjects();

	//�f�[�^�₢���킹�֐�
	double ReferCoordX() { return coordX; }
	double ReferCoordY() { return coordY; }
	double ReferCoordZ() { return coordZ; }
	double ReferSpeedOnZ() { return speedOnZ; }
	double ReferSpeedOnY() { return speedOnY; }
	double ReferAirResistance() { return airResistance; }
	double ReferRadianOnZ() { return radianOnZ; }
	double ReferRadianOnY() { return radianOnY; }

	//�����蔻��p�₢���킹
	double ReferLeft() { return coordX - width; }
	double ReferRight() { return coordX; }
	double ReferUpper() { return coordZ - length; }
	double ReferLower() { return coordZ; }

	//��Ԗ₢���킹�֐�
	bool ReferAlive() { return alive; }

	//�ړ��֐�
	void Move();
	void FallingDown();
	void SpeedDownbyAirResistance();

	//��Ԑݒu�֐�
	void NewCoordX(double X) { coordX = X; }
	void NewCoordY(double Y) { coordY = Y; }
	void SetRadianOnZ(double ROZ) { radianOnZ = ROZ; }
	void SetRadianOnY(double ROY) { radianOnY = ROY; }
	void Killed() { alive = false; }
	void SetSpeed(double Spe);
	void SetAirResistance(double AR) { airResistance = AR; }
	

private:
	/*XZ�͐������W�AY�͍���*/
	double coordX;
	double coordY;
	double coordZ;
	/*�X�s�[�h�͐����Ɛ����ɕ�����*/
	double speedOnZ;
	double speedOnY;
	double airResistance;//��C��R
	double radianOnZ;//�s������(����)
	double radianOnY;//�s������(����)
	bool alive;//��������

	bool flyable;//����͔�ׂ���̂��i�d�͉e���̗L���j
	bool plane;//����͔�ׂ���̂����A�d�͂��������Ĕ�Ԃ��Ƃ��ł���

	/*�����`�𗘗p���ĊȒP�ȓ����蔻����s��*/
	bool point;
	double length;
	double width;
};

