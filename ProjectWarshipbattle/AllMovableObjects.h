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

	//データ問い合わせ関数
	double ReferCoordX() { return coordX; }
	double ReferCoordY() { return coordY; }
	double ReferCoordZ() { return coordZ; }
	double ReferSpeedOnZ() { return speedOnZ; }
	double ReferSpeedOnY() { return speedOnY; }
	double ReferAirResistance() { return airResistance; }
	double ReferRadianOnZ() { return radianOnZ; }
	double ReferRadianOnY() { return radianOnY; }

	//当たり判定用問い合わせ
	double ReferLeft() { return coordX - width; }
	double ReferRight() { return coordX; }
	double ReferUpper() { return coordZ - length; }
	double ReferLower() { return coordZ; }

	//状態問い合わせ関数
	bool ReferAlive() { return alive; }

	//移動関数
	void Move();
	void FallingDown();
	void SpeedDownbyAirResistance();

	//状態設置関数
	void NewCoordX(double X) { coordX = X; }
	void NewCoordY(double Y) { coordY = Y; }
	void SetRadianOnZ(double ROZ) { radianOnZ = ROZ; }
	void SetRadianOnY(double ROY) { radianOnY = ROY; }
	void Killed() { alive = false; }
	void SetSpeed(double Spe);
	void SetAirResistance(double AR) { airResistance = AR; }
	

private:
	/*XZは水平座標、Yは高さ*/
	double coordX;
	double coordY;
	double coordZ;
	/*スピードは水平と垂直に分ける*/
	double speedOnZ;
	double speedOnY;
	double airResistance;//空気抵抗
	double radianOnZ;//行く方向(水平)
	double radianOnY;//行く方向(垂直)
	bool alive;//生きる状態

	bool flyable;//これは飛べるものか（重力影響の有無）
	bool plane;//これは飛べるものだが、重力を克服して飛ぶことができる

	/*長方形を利用して簡単な当たり判定を行う*/
	bool point;
	double length;
	double width;
};

