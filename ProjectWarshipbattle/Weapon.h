#pragma once
#include"Ammo.h"
#include"Torpedo.h"
class Weapon
{
public:
	Weapon();
	Weapon(double RCX, double RCZ, double L, double W,
		double ROZ, double ROY,int MHP,double AOS,double AOT,
		int *aH,int iS) :
		relativeCoordX(RCX),relativeCoordZ(RCZ),length(L),
		width(W),radianOnZ(ROZ),radianOnY(ROY),heartPoint(MHP),
		maxHeartPoint(MHP),armorOntheSide(AOS),armorOntheTop(AOT),
		ammoHandle(aH), initialSpeed(iS) {}
	~Weapon();

	//データ問い合わせ関数
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

	//状態問い合わせ関数
	bool ReferShootable();//射撃できればtrueを戻す
	
	Ammo Shoot(double x, double y);


private:
	int numberofGuns;//砲塔の連装数
	unsigned int reloadTime;//再装填の時間
	unsigned int lastShootedTime;//前回射撃した時間
	double calibre;

	int *turrentHandle;//画像データ保存用
	int *ammoHandle;

	double initialSpeed;//初速度
	
	double relativeCoordX;
	double relativeCoordZ;
	double length;
	double width;
	double radianOnZ;//水平面の角度
	double radianOnY;//砲身の角度-->これで砲弾落下位置を推定する

	int heartPoint;
	int maxHeartPoint;
	double armorOntheSide;
	double armorOntheTop;
};