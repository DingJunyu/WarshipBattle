#include "AllMovableObjects.h"

AllMovableObjects::~AllMovableObjects()
{
}

void AllMovableObjects::Move() {
	if (airResistanceActive)
		speedOnZ *= airResistance;

	//2D�Q�[���ł����AY���̈ړ����l����
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
	//�����ʂł͐��������̃X�s�[�h���v��Ȃ�
	if (!flyable) {
		speedOnY = 0;
		speedOnZ = Spe;
	}
	else {
		speedOnY = sin(radianOnY)*Spe;
		speedOnZ = cos(radianOnY)*Spe;
	}
	speedOnZLargerThan0 = speedOnZ > 0 ? true : false;
}

void AllMovableObjects::SpeedDownbyAirResistance() {
	if (airResistance > MathAndPhysics::MIN_AIR_RESISTANCE)
		airResistance *= 0.99;
	else
		airResistance = MathAndPhysics::MIN_AIR_RESISTANCE;

	if (speedOnZLargerThan0 && speedOnZ > 0) {
		speedOnZ -= airResistance;
		if (speedOnZ < 0)
			speedOnZ = 0;
	}
	if (!speedOnZLargerThan0 && speedOnZ < 0) {
		speedOnZ += airResistance;
		if (speedOnZ > 0)
			speedOnZ = 0;
	}
}
//���@�`�����͂��̊֐����g��
void AllMovableObjects::Draw(Camera CM) {
	double xOnScreen;
	double zOnScreen;
	int shadowDistanceOnX = 2;
	int shadowDistanceOnZ = 2;
	xOnScreen = Screen::SCREEN_X / 2;
	zOnScreen = Screen::SCREEN_Z / 2;

	DrawRotaGraph3((int)xOnScreen + shadowDistanceOnX, 
		(int)zOnScreen + shadowDistanceOnZ, (int)(length / 2), 
		(int)(width) / 2, 0.125, 0.125,
		radianOnZ, *shadowHandle, TRUE, FALSE);

	DrawRotaGraph3((int)xOnScreen, (int)zOnScreen, (int)(length / 2), 
		(int)(width) / 2, 0.125, 0.125,
		radianOnZ, *pictureHandle, TRUE, FALSE);
}

//���@�ȊO�̂͂��̊֐����g��
void AllMovableObjects::DrawSub(Camera CM) {
	/*�V���h�[�̋����v�Z�͂܂�*/
	int shadowDistanceOnX = 2;
	int shadowDistanceOnZ = 2;

	DrawRotaGraph3((int)(coordX - CM.ReferRealCameraX() + shadowDistanceOnX),
		(int)(coordZ - CM.ReferRealCameraZ() + shadowDistanceOnZ),
		(int)(length / 2), (int)(width / 2),
		0.125, 0.125, radianOnZ,
		*shadowHandle, TRUE, FALSE);

	DrawRotaGraph3((int)(coordX - CM.ReferRealCameraX()),
		(int)(coordZ - CM.ReferRealCameraZ()),
		(int)(length / 2), (int)(width / 2),
		0.125, 0.125, radianOnZ,
		*pictureHandle, TRUE, FALSE);
}