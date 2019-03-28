#pragma once
#include<cmath>
#include"DefinedData.h"
#include"Camera.h"
#include"DxLib.h"

class AllMovableObjects
{
public:
	AllMovableObjects(bool fly, bool pla, bool poi,bool Cb) : flyable(fly),
		plane(pla), alive(true), point(poi), crashable(Cb) {
		radianChangePerFrame = 0;
		airResistanceActive = false;
		airResistance = 0.001;
	}
	virtual ~AllMovableObjects();

	//�f�[�^�₢���킹�֐�
	double ReferCoordX() { return coord.x; }
	double ReferCoordY() { return coord.y; }
	double ReferCoordZ() { return coord.z; }
	Coordinate<double> ReferCoord() { return coord; }
	double ReferSpeedOnZ() { return speedOnZ; }
	double ReferSpeedOnY() { return speedOnY; }
	double ReferAirResistance() { return airResistance; }
	double ReferRadianOnZ() { return radianOnZ; }
	double ReferRadianOnY() { return radianOnY; }
	double ReferLength() { return length; }
	double ReferWidth() { return width; }

	//�����蔻��p�₢���킹
	double ReferLeft() { return coord.x - width; }
	double ReferRight() { return coord.x; }
	double ReferUpper() { return coord.z - length; }
	double ReferLower() { return coord.z; }

	//��Ԗ₢���킹�֐�
	bool ReferAlive() { return alive; }

	//�ړ��֐�
	void Move();
	void FallingDown();
	void SpeedDownbyAirResistance();

	//�`��֐�
	void SetPictureHandle(int *p) { pictureHandle = p; }
	void SetShadowHandle(int *p) { shadowHandle = p; }
	void Draw(Camera CM);
	void DrawSub(Camera CM);

	//��Ԑݒu�֐�
	void NewCoordX(double X) { coord.x = X; }
	void NewCoordZ(double Z) { coord.z = Z; }
	void NewCoordY(double Y) { coord.y = Y; }
	void SetCoord(Coordinate<double> NC) { coord = NC; }
	void SetRadianOnZ(double ROZ) { radianOnZ = ROZ; }
	void SetRadianChangePerFrame(double RCPF) { radianChangePerFrame = RCPF; }
	void SetRadianOnY(double ROY) { radianOnY = ROY; }
	void SetLength(double L) { length = L; }
	void SetWidth(double W) { width = W; }
	void Killed() { alive = false; }
	void SetSpeed(double Spe);
	void SetAirResistance(double AR) { airResistance = AR; }
	void UnsetPlane() { plane = false; }
	

private:
	/*XZ�͐������W�AY�͍���*/
	Coordinate<double> coord;
	/*�X�s�[�h�͐����Ɛ����ɕ�����*/
	double speedOnZ;
	double speedOnY;
	bool speedOnZLargerThan0;
	bool airResistanceActive;
	double airResistance;//��C��R
	double radianOnZ;//�s������(����)
	double radianChangePerFrame;
	double radianOnY;//�s������(����)
	bool alive;//��������

	/*�p����Œl��^����*/
	bool flyable;//����͔�ׂ���̂��i�d�͉e���̗L���j
	bool plane;//����͔�ׂ���̂����A�d�͂��������Ĕ�Ԃ��Ƃ��ł���

	/*�����`�𗘗p���ĊȒP�ȓ����蔻����s��*/
	/*�p����Œl��^����*/
	bool point;//�_�Ɣ��f���鎞�͒����Ȃǂ��g��Ȃ�
	double length;
	double width;

	//�����蔻�肪�K�v���ǂ���
	bool crashable;
	
	//�摜�̃n���h��
	int *pictureHandle;
	int *shadowHandle;
};

