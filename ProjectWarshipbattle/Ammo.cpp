#include "Ammo.h"

Ammo::~Ammo()
{
}

void Ammo::CheckAlive() {
	if (ReferCoordY() <= 0) {
		isUsable = false;
	}
}

void Ammo::SetData() {
	GetGraphSize(*ammoHandle, &graphX, &graphZ);
}

void Ammo::Draw(int x,int z){
	DrawRotaGraph3((int)ReferCoordX() - x,
		(int)ReferCoordZ() - z,
		graphX / 2, graphZ / 2,
		0.15, 0.15, ReferRadianOnZ() - MathAndPhysics::PI / 4,
		*ammoHandle, TRUE, FALSE);
}

void Ammo::DrawDelete(int x, int z) {

}