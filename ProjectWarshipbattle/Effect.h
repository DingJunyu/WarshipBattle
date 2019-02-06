#pragma once
#include"DxLib.h"
#include"DefinedData.h"
#include<time.h>
class Effect
{
public:
	Effect(bool Movable):
		movable(Movable),radian(rand() % 60 * MathAndPhysics::PI){}
	~Effect();

	void Draw();

private:
	bool movable;
	int type;
	double radian;
	double coordX;
	double coordZ;
	int *graphicHandle;
	int graphX;
	int graphZ;
	int *animationHandle;
};

