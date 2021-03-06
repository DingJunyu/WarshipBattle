#pragma once
#include"DxLib.h"
#include"DefinedData.h"
#include<time.h>
#include<cmath>
class Effect
{
public:
	Effect(bool Movable, int continueTime, double R,
		double TRadian, double RCPF, double Speed, double CX,
		double CZ, int *GH, bool Spread, double ZM, double ZR) :
		movable(Movable),
		timeUp(false), endTime(GetNowCount() + continueTime),
		radian(R), targetRadian(TRadian), radianChangePerFrame(RCPF),
		speed(Speed), coordX(CX), coordZ(CZ), graphicHandle(GH),
		spread(Spread), zoomMutliple(ZM), zoomRate(ZR)
	{
		right = rand() % 2;
	}
	~Effect();

	void Draw(int x, int z);
	void Move();

	//時間に過ぎたら消す
	bool ReferTimeUp() { return timeUp; }

	void SetGraphHandle(int *GH) { graphicHandle = GH; }

private:
	void Check();
	//エフェクトのタイプと移動できるか
	bool movable;
	int type;
	//座標など
	double radian;
	double targetRadian;
	double radianChangePerFrame;
	double coordX;
	double coordZ;
	double speed;
	bool right;
	//画像データ
	int *graphicHandle;
	int graphX;
	int graphZ;
	int *animationHandle;
	//消失時間
	int endTime;
	bool timeUp;

	bool spread;
	double zoomMutliple;
	double zoomRate;
};