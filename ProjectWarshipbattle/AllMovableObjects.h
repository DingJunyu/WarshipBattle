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

	//データ問い合わせ関数
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

	//当たり判定用問い合わせ
	double ReferLeft() { return coord.x - width; }
	double ReferRight() { return coord.x; }
	double ReferUpper() { return coord.z - length; }
	double ReferLower() { return coord.z; }

	//状態問い合わせ関数
	bool ReferAlive() { return alive; }

	//移動関数
	void Move();
	void FallingDown();
	void SpeedDownbyAirResistance();

	//描画関数
	void SetPictureHandle(int *p) { pictureHandle = p; }
	void SetShadowHandle(int *p) { shadowHandle = p; }
	void Draw(Camera CM);
	void DrawSub(Camera CM);

	//状態設置関数
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
	/*XZは水平座標、Yは高さ*/
	Coordinate<double> coord;
	/*スピードは水平と垂直に分ける*/
	double speedOnZ;
	double speedOnY;
	bool speedOnZLargerThan0;
	bool airResistanceActive;
	double airResistance;//空気抵抗
	double radianOnZ;//行く方向(水平)
	double radianChangePerFrame;
	double radianOnY;//行く方向(垂直)
	bool alive;//生きる状態

	/*継承先で値を与える*/
	bool flyable;//これは飛べるものか（重力影響の有無）
	bool plane;//これは飛べるものだが、重力を克服して飛ぶことができる

	/*長方形を利用して簡単な当たり判定を行う*/
	/*継承先で値を与える*/
	bool point;//点と判断する時は長さなどを使わない
	double length;
	double width;

	//当たり判定が必要かどうか
	bool crashable;
	
	//画像のハンドル
	int *pictureHandle;
	int *shadowHandle;
};

