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

	if (speedOnZ != 0 && radianChangePerFrame != 0) {
		radianOnZ += (radianChangePerFrame/100) * speedOnZ;
	}
	if (radianOnZ > (MathAndPhysics::PI * 2)) {
		radianOnZ -= (MathAndPhysics::PI * 2);
	}
	if (radianOnZ < - (MathAndPhysics::PI * 2)) {
		radianOnZ += (MathAndPhysics::PI * 2);
	}

	coordX += speedOnZ * cos(radianOnZ);
	coordZ += speedOnZ * sin(radianOnZ);
}

void AllMovableObjects::FallingDown() {
	if (coordZ > 0 && flyable && !plane) {
		speedOnY -= MathAndPhysics::GRAVITATIONAL_ACCELERATION;
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
	if (airResistance > MathAndPhysics::MIN_AIR_RESISTANCE)
		airResistance *= 0.99;
	else
		airResistance = MathAndPhysics::MIN_AIR_RESISTANCE;

	if (speedOnZ >= 0) {
		speedOnZ -= airResistance;
	}
}

void AllMovableObjects::Draw(Camera CM) {
	double xOnScreen;
	double zOnScreen;
	int shadowDistanceOnX = 2;
	int shadowDistanceOnZ = 2;
	xOnScreen = CM.ReferRealCameraX();
	zOnScreen = CM.ReferRealCameraZ();

	DrawRotaGraph3((int)xOnScreen + shadowDistanceOnX, 
		(int)zOnScreen + shadowDistanceOnZ, (int)(length / 2), 
		(int)(width) / 2, 0.125, 0.125,
		radianOnZ, *shadowHandle, TRUE, FALSE);

	DrawRotaGraph3((int)xOnScreen, (int)zOnScreen, (int)(length / 2), 
		(int)(width) / 2, 0.125, 0.125,
		radianOnZ, *pictureHandle, TRUE, FALSE);
}