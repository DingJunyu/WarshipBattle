#pragma once
class Weapon
{
public:
	Weapon();
	~Weapon();

	//問い合わせ関数
	int ReferNumbefofGuns() { return numberofGuns; }
	int ReferReloadTime() { return reloadTime; }
	int ReferLastShootedTime() { return lastShootedTime; }
	bool ReferShootable();//射撃できればtrueを戻す



private:
	int numberofGuns;//砲塔の連装数
	int reloadTime;//再装填の時間
	int lastShootedTime;//前回射撃した時間
	double calibre;

	int *turrentHandle;//画像データ保存用
	
	double relativeCoordX;
	double relativeCoordY;
	double length;
	double width;
	double radianOnZ;//水平面の角度
	double radianOnY;//砲身の角度-->これで砲弾落下位置を推定する

	int heartPoint;
	int maxHeartPoint;
	double armorOntheSide;
	double armorOntheTop;

};