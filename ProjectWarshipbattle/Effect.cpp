#include "Effect.h"

Effect::~Effect()
{
}

void Effect::Draw(int x,int z) {
	if (spread) {
		zoomMutliple *= zoomRate;
	}

	double rotateX = 0;
	double rotateZ = 0;

	//rotateX = (double)graphX;
	//rotateZ = (double)graphZ;

	//double realX = cos(radian) * rotateX -
	//	sin(radian) * rotateZ;
	//double realZ = cos(radian) * rotateZ +
	//	sin(radian) * rotateX;

	DrawRotaGraph3((int)coordX - x - (int)(rotateX),
		(int)coordZ - z - (int)(rotateZ),
		graphX / 2, graphZ / 2,
		zoomMutliple, zoomMutliple, radian - MathAndPhysics::PI/4,
		*graphicHandle, TRUE, FALSE);

	/*テスト用*/
	/*unsigned int Cr = GetColor(0, 0, 255);
	DrawPixel(coordX - x, coordZ - z, Cr);*/

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