#pragma once
#include "AllMovableObjects.h"
class Ammo :
	public AllMovableObjects
{
public:
	Ammo() : AllMovableObjects(true, false, true, true) {
		isUsable = true;
		canBeDelete = false;
	}
	Ammo(double spe, double rad, double x, double z, double y,
		double radY, int *aH) : 
		AllMovableObjects(true, false, true, true){
		SetRadianOnZ(rad);
		NewCoordX(x);
		NewCoordZ(z);
		NewCoordY(y);
		SetRadianOnY(radY);
		SetSpeed(spe);
		ammoHandle = aH;
		SetData();
	}
	~Ammo();

	double ReferDamage() { return damage; }
	void CheckAlive();
	void SetData();
	
	//�ʏ�`��
	void Draw(int x,int z);
	//�����O�̓��扉�o
	void DrawDelete(int x, int z);
	bool FallIntoWater() { 
		if (ReferCoordY() <= 0)return true; 
		else return false;
	}
	
private:
	double penetrateDepth;
	double damage;

	//deletetime�͌Œ肳�ꂽ���ARecord���g���Ď����𔻒f���܂�
	unsigned int timeCounterForDelete;
	unsigned int timeRecordForDelete;
	unsigned int DeleteTime;

	bool isUsable;
	bool canBeDelete;

	int graphX;
	int graphZ;

	int *ammoHandle;
};

