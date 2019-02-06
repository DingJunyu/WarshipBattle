#include "Effect.h"

Effect::~Effect()
{
}

void Effect::Draw() {
	DrawRotaGraph3(coordX, coordZ, graphX / 2, graphZ / 2,
		0.25, 0.25, radian,
		*graphicHandle, TRUE, FALSE);
}