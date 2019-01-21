#include "AllMovableObjects.h"

AllMovableObjects::~AllMovableObjects()
{
}

void AllMovableObjects::Move() {
	//2Dゲームですか、Y軸の移動も考える
	if (flyable) {
		if (!plane) {
			FallingDown();
			SpeedDownbyAirResistance();
		}
		coordY += speedOnY;
	}
	coordX += speedOnZ * cos(radianOnZ);
	coordZ += speedOnZ * sin(radianOnZ);
}

void AllMovableObjects::FallingDown() {
	if (coordZ > 0 && flyable && !plane) {
		speedOnY -= GRAVITATIONAL_ACCELERATION;
	}
}

void AllMovableObjects::SetSpeed(double Spe) {
	//水平面では垂直方向のスピードが要らない
	if (!flyable) {
		speedOnY = 0;
		speedOnZ = Spe;
	}
	else {
		speedOnY = sin(radianOnY)*Spe;
		speedOnZ = cos(radianOnY)*Spe;
	}
}

void AllMovableObjects::SpeedDownbyAirResistance() {
	if (airResistance > MIN_AIR_RESISTANCE)
		airResistance *= 0.99;
	else
		airResistance = MIN_AIR_RESISTANCE;

	if (speedOnZ >= 0) {
		speedOnZ -= airResistance;
	}
}