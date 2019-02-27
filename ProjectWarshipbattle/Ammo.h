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
	Ammo(double spe, double rad, double x, double z,
		double radY) : 
		AllMovableObjects(true, false, true, true){
		SetSpeed(spe);
		SetRadianOnZ(rad);
		NewCoordX(x);
		NewCoordZ(z);
		SetRadianOnY(radY);
	}
	~Ammo();

	double ReferDamage() { return damage; }
	void CheckAlive();
	void SetData();
	
	//�ʏ�`��
	void Draw(int x,int z);
	//�����O�̓��扉�o
	void DrawDelete(int x, int z);
	
private:
	double penetrateDepth;
	double damage;

	//deletetime�͌Œ肳�ꂽ���ARecord���g���Ď����𔻒f���܂�
	unsigned int timeCounterForDelete;
	unsigned int timeRecordForDelete;
	unsigned int DeleteTime;

	bool isUsable;
	bool canBeDelete;

	int *effectHandle;
};

