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

}

void Ammo::Draw(int x,int z){

}

void Ammo::DrawDelete(int x, int z) {

}