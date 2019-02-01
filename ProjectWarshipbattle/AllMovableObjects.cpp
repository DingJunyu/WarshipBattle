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
	coordX -= speedOnZ * cos(radianOnZ);
	coordZ -= speedOnZ * sin(radianOnZ);
	if (speedOnZ != 0) {
		radianOnZ += radianChangePerFrame/10;
	}
	if (radianOnZ > 2*MathAndPhysics::PI)
		radianOnZ -= 2*MathAndPhysics::PI;
	if (radianOnZ < -2*MathAndPhysics::PI)
		radianOnZ += 2*MathAndPhysics::PI;
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
	xOnScreen = CM.ReferRealCameraX();
	zOnScreen = CM.ReferRealCameraZ();
	DrawRotaGraph3(xOnScreen, zOnScreen, length / 2
		, width / 2, 0.125, 0.125,
		radianOnZ, *pictureHandle, TRUE, FALSE);
}