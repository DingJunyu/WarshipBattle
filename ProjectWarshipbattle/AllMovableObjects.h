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
	}
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

	//描画関数
	void SetPictureHandle(int *p) { pictureHandle = p; }
	void Draw(Camera CM);

	//状態設置関数
	void NewCoordX(double X) { coordX = X; }
	void NewCoordZ(double Z) { coordZ = Z; }
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
	double coordX;
	double coordY;
	double coordZ;
	/*スピードは水平と垂直に分ける*/
	double speedOnZ;
	double speedOnY;
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

