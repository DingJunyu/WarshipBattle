#include "ShipMain.h"

ShipMain::~ShipMain()
{
}

void ShipMain::InifThisShip(int *ShipHandle, int *SShadowH ,int ShipNum) {
	SetPictureHandle(ShipHandle);
	SetShadowHandle(SShadowH);
}

void ShipMain::ChangeAccPercentage(bool up) {
	if (up&&currentAccPercentage < 1.0f)
		currentAccPercentage += 0.25f;
	if (!up&&currentAccPercentage > 0)
		currentAccPercentage -= 0.25f;
}

void ShipMain::CalSpeed() {
	
	double currentSpeed;
	double newSpeed = 0;
	double realAccPercentage;
	double realAcc;
	currentSpeed = ReferSpeedOnZ();

	//前進の場合
	if (currentAccPercentage >= 0) {
		//加速度の計算
		realAccPercentage = accPercentageLostToSpeedPercentage
			* (1 - (currentSpeed / maxSpeed));
		if (realAccPercentage < minAccPercentageeLostToSpeedPercentage)
			realAccPercentage = minAccPercentageeLostToSpeedPercentage;
		//新たな速度の計算
		realAcc = currentAccPercentage * maxAcc *
			realAccPercentage;

		newSpeed = realAcc/100 + currentSpeed;
		if (newSpeed > maxSpeed*currentAccPercentage) {
			if (currentAccPercentage != 0.0f)
				newSpeed -= 0.001 / currentAccPercentage*
				(newSpeed / maxSpeed * (1 - currentAccPercentage));
			else
				newSpeed -= 0.0015;
		}

		if (currentRadian != 0) {
			if (newSpeed > maxSpeed*currentAccPercentage*0.95)
				newSpeed -= 0.001;
		}

		if (currentAccPercentage == 0 && abs(newSpeed) < 0.0005)
			newSpeed = 0;
		if (newSpeed > maxSpeed)
			newSpeed = maxSpeed;
		if (newSpeed < 0)
			newSpeed = 0;
	}
	SetSpeed(newSpeed);
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
}

void ShipMain::Alignment() {

	if (returnToCenter == true) {
		if (currentRadian > MathAndPhysics::PI / 10000)
			currentRadian -= MathAndPhysics::PI / 10000;
		if (currentRadian < -MathAndPhysics::PI / 10000)
			currentRadian += MathAndPhysics::PI / 10000;
		if ((currentRadian < MathAndPhysics::PI / 10000 
			&& currentRadian>0) ||
			(currentRadian > -MathAndPhysics::PI / 10000 
				&& currentRadian < 0)) {
			currentRadian = 0;
		}
	}
	SetRadianChangePerFrame(currentRadian);
}


void ShipMain::ControlThisShip(int Command) {;
	switch (Command) {
	case CommandSerial::INCREASE_OUTPUT:ChangeAccPercentage(true); break;
	case CommandSerial::DECREASE_OUTPUT:ChangeAccPercentage(false); break;
	case CommandSerial::TURN_RIGHT:ChangeDirect(true); break;
	case CommandSerial::TURN_LEFT:ChangeDirect(false); break;
	case CommandSerial::TURN_RETURN:ReturnDirectChange(); break;
	}
	CalSpeed();
	Alignment();
}

void ShipMain::TEST() {
	maxSpeed = 0.8;
	maxAcc = 0.1;
	minAccPercentageeLostToSpeedPercentage = 0.2;
	accPercentageLostToSpeedPercentage = 0.1;
	SetSpeed(0);
	SetRadianOnZ(0);
	maxRadian = MathAndPhysics::PI / 15;
	radianChangePerFrame = MathAndPhysics::PI / 1800;
	currentRadian = 0;
	minAccNeedatMaxSpeed = 0.0000001;
}