#include "Effect.h"

Effect::~Effect()
{
}

void Effect::Draw() {
	DrawRotaGraph3(coordX, coordZ, graphX / 2, graphZ / 2,
		0.01, 0.01, radian,
		*graphicHandle, TRUE, FALSE);
	if (radian != targetRadian && abs(radian - targetRadian) > 
		radianChangePerFrame) {
		if (radian < 0)
			radian += radianChangePerFrame;
		if (radian > 0)
			radian -= radianChangePerFrame;
	}
	Check();
}

void Effect::Check() {
	if (GetNowCount() > endTime)
		timeUp = true;
}

void Effect::Move() {
	coordX += cos(radian)*speed;
	coordZ += sin(radian)*speed;
}