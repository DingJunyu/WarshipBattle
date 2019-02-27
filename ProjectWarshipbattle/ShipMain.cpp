#include "ShipMain.h"

ShipMain::~ShipMain()
{
}

void ShipMain::InifThisShip(int *ShipHandle, int *SShadowH ,int ShipNum,
	EffectTemplate ET, SoundLoader *SL) {
	SetPictureHandle(ShipHandle);
	SetShadowHandle(SShadowH);
	//GetDataFromShipdata(ShipNum);
	MemorySecure();
	LoadSound(SL);

	/*テスト部分も含む*/
	for (int i = 0; i < 5; i++) {
		bubbleStartPoint[i] = ET.CopyFromCreateBubble();
		bubbleStartPoint[i].InifCoordinate(100, 0, true, 3000, 20, true,
			0.15, 1.001);
	}
	bubbleStartPoint[1].InifCoordinate(-14, -13, true, 1500, 20, true,
		0.15, 1.001);
	bubbleStartPoint[2].InifCoordinate(-14, 13, true, 1500, 20, true,
		0.15, 1.001);

	bubbleStartPoint[3].InifCoordinate(-78, -6, true, 1500, 20, true,
		0.15, 1.001);
	bubbleStartPoint[4].InifCoordinate(-78, 6, true, 1500, 20, true,
		0.15, 1.001);

	for (int i = 0; i < 2; i++) {
		smokeStartPoint[i] = ET.CopyFromCreateSmoke();
		smokeStartPoint[i].InifCoordinate(4, 0, true, 2000, 20, true,
			0.06, 1.005);
	}
	smokeStartPoint[0].InifCoordinate(14, 0, true, 2000, 20, true,
		0.06, 1.005);
	smokeStartPoint[1].InifCoordinate(-12, 0, true, 2000, 20, true,
		0.06, 1.005);
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
				newSpeed -= 0.0001 / currentAccPercentage*
				(newSpeed / maxSpeed * (1 - currentAccPercentage));
			else
				newSpeed -= 0.00015;
		}

		if (currentRadian != 0) {
			if (newSpeed > maxSpeed*currentAccPercentage * 0.95)
				newSpeed -= 0.0001;
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
	/*ここに入れたものは最後全部shipdataに統合する*/
	/*移動関連*/
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

	/*エフェクト関連*/
	bubblePointCount = 5;
	smokePointCount = 2;

	/*音声関連*/
}

void ShipMain::TestDraw(double x, double z) {
	for (int i = 0; i < 5; i++) {
		bubbleStartPoint[i].TestDraw(ReferRadianOnZ(),ReferCoordX(),
			ReferCoordZ(),x,z);
	}
	for (int i = 0; i < 2; i++) {
		smokeStartPoint[i].TestDraw(ReferRadianOnZ(), ReferCoordX(),
			ReferCoordZ(),x,z);
	}
}

void ShipMain::MemorySecure() {
	MainParts = new ShipCrashParts [10];
	SubParts = new ShipCrashParts[10];

	MainWeapon = new Weapon[10];
	SubWeapon = new Weapon[10];

	bubbleStartPoint = new EffectPoint[5];
	smokeStartPoint = new EffectPoint[2];
}

/*削除前に必ずこの関数を呼び出して！*/
void ShipMain::DestroyMemory() {
	delete[] MainParts;
	delete[] SubParts;
	delete[] MainWeapon;
	delete[] SubWeapon;
	delete[] bubbleStartPoint;
	delete[] smokeStartPoint;
}

//エフェクト生成
Effect ShipMain::NewBubble(int num) {
	double newRadian = ReferRadianOnZ() - MathAndPhysics::PI;

	return bubbleStartPoint[num].NewEffect(newRadian,
		ReferSpeedOnZ(),
		ReferCoordX(), ReferCoordZ());
}

Effect ShipMain::NewSmoke(int num) {
	double newRadian = ReferRadianOnZ() - MathAndPhysics::PI;

	newRadian += (double)((1 - rand() % 3) / 180.0f) * MathAndPhysics::PI;

	return smokeStartPoint[num].NewEffect(newRadian, ReferSpeedOnZ(),
		ReferCoordX(), ReferCoordZ());
}

/*音声関連*/
void ShipMain::LoadSound(SoundLoader *SL) {
	soundEngine = SL->referShipSoundEngine();
	soundMoving = SL->referShipSoundMoving();
	soundSlow = SL->referShipSoundSlow();
	soundTurning = SL->referShipSoundTuring();

	soundHordHigh = SL->referShipHordLargeHigh();
	soundHordLow = SL->referShipHordLargeLow();
}

void ShipMain::CheckAndPlaySound() {
	/*エンジン音*/
	if (currentAccPercentage != 0 && CheckSoundMem(*soundEngine) == 0) {
		PlaySoundMem(*soundEngine, DX_PLAYTYPE_LOOP, TRUE);
	}
	if (currentAccPercentage == 0 && CheckSoundMem(*soundEngine) != 0) {
		StopSoundMem(*soundEngine);
	}
	/*水音*/
	if (ReferSpeedOnZ() > 0 && ReferSpeedOnZ() < 0.2&&
		CheckSoundMem(*soundSlow) == 0) {
		PlaySoundMem(*soundSlow,DX_PLAYTYPE_LOOP,TRUE);
	}
	if ((ReferSpeedOnZ() < 0 || ReferSpeedOnZ() >= 0.2)&&
		CheckSoundMem(*soundSlow) != 0) {
		StopSoundMem(*soundSlow);
	}

	if (ReferSpeedOnZ() >= 0.2 && CheckSoundMem(*soundMoving) == 0) {
		PlaySoundMem(*soundMoving, DX_PLAYTYPE_LOOP, TRUE);
	}
	if (ReferSpeedOnZ() < 0.2 && CheckSoundMem(*soundMoving) != 0) {
		StopSoundMem(*soundMoving);
	}

	/*転向音*/
	if (abs(currentRadian) > MathAndPhysics::PI / 30 &&
		CheckSoundMem(*soundTurning) == 0) {
		PlaySoundMem(*soundTurning, DX_PLAYTYPE_LOOP, TRUE);
	}
	if (abs(currentRadian) < MathAndPhysics::PI / 30 &&
		CheckSoundMem(*soundTurning) != 0) {
		StopSoundMem(*soundTurning);
	}
}

bool ShipMain::IsThisOneUsable(int Num, bool Main) {

}