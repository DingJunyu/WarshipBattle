#include "ShipMain.h"

ShipMain::~ShipMain()
{
}

void ShipMain::InifThisShip(int *ShipHandle,int ShipNum) {
	SetPictureHandle(ShipHandle);
}

void ShipMain::ChangeAccPercentage(bool up) {
	if (up&&currentAccPercentage < 1.0f)
		currentAccPercentage += 0.25f;
	if (!up&&currentAccPercentage > 0)
		currentAccPercentage -= 0.25f;
}

void ShipMain::CalSpeed() {
	
	double currentSpeed;
	double newSpeed;
	double realAccPercentage;
	double realAcc;
	currentSpeed = ReferSpeedOnZ();

	//前進の場合
	if (currentAccPercentage > 0) {
		//加速度の計算
		realAccPercentage = accPercentageLostToSpeedPercentage
			* (1 - currentSpeed / maxSpeed);
		if (realAccPercentage < minAccPercentageeLostToSpeedPercentage)
			realAccPercentage = minAccPercentageeLostToSpeedPercentage;
		//新たな速度の計算
		realAcc = currentAccPercentage * maxAcc *
			realAccPercentage;

		newSpeed = realAcc + currentSpeed;
		if (newSpeed > maxSpeed*currentAccPercentage) {
			newSpeed -= 0.01;
		}
		if (currentAccPercentage == 0 && abs(newSpeed) < 0.05)
			newSpeed = 0;
		SetSpeed(newSpeed);
	}
}

void ShipMain::ChangeDirect(bool right) {
	if (right) {
		currentRadian += radianChangePerFrame;
	}
	else {
		currentRadian -= radianChangePerFrame;
	}
	if (currentRadian > maxRadian)
		currentRadian = maxRadian;
	if (currentRadian < -maxRadian)
		currentRadian = -maxRadian;

//	currentRadian *= (ReferSpeedOnZ() / maxSpeed);

	SetRadianChangePerFrame(currentRadian);
}


void ShipMain::ControlThisShip(int Command) {;
	switch (Command) {
	case CommandSerial::INCREASE_OUTPUT:ChangeAccPercentage(true); break;
	case CommandSerial::DECREASE_OUTPUT:ChangeAccPercentage(false); break;
	case CommandSerial::TURN_RIGHT:ChangeDirect(true); break;
	case CommandSerial::TURN_LEFT:ChangeDirect(false); break;
	}
	CalSpeed();
}

void ShipMain::TEST() {
	maxSpeed = 2;
	maxAcc = 0.05;
	minAccPercentageeLostToSpeedPercentage = 0.2;
	accPercentageLostToSpeedPercentage = 0.1;
	SetSpeed(0);
	SetRadianOnZ(0);
	maxRadian = MathAndPhysics::PI / 60;
	radianChangePerFrame = MathAndPhysics::PI / 1800;
	currentRadian = 0;
	minAccNeedatMaxSpeed = 0.0000001;
}