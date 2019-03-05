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
	
	//通常描画
	void Draw(int x,int z);
	//消す前の動画演出
	void DrawDelete(int x, int z);
	bool FallIntoWater() { 
		if (ReferCoordY() <= 0)return true; 
		else return false;
	}
	
private:
	double penetrateDepth;
	double damage;

	//deletetimeは固定されたが、Recordを使って時期を判断します
	unsigned int timeCounterForDelete;
	unsigned int timeRecordForDelete;
	unsigned int DeleteTime;

	bool isUsable;
	bool canBeDelete;

	int graphX;
	int graphZ;

	int *ammoHandle;
};

