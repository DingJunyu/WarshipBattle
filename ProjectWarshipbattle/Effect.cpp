#include "Effect.h"

Effect::~Effect()
{
}

void Effect::Draw(int x,int z) {
	if (spread) {
		zoomMutliple *= zoomRate;
	}


	DrawRotaGraph3((int)coordX - x, (int)coordZ - z, 
		graphX / 2, graphZ / 2,
		zoomMutliple, zoomMutliple, radian,
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
	if (rand()%2==0)
		radian += (double)((rand() % 2) / 180.0f) * MathAndPhysics::PI;
	else
		radian -= (double)((rand() % 2) / 180.0f) * MathAndPhysics::PI;

	coordX += cos(radian)*speed;
	coordZ += sin(radian)*speed;

}