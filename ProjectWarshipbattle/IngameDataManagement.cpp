#include "IngameDataManagement.h"

IngameDataManagement::~IngameDataManagement()
{
}

void IngameDataManagement::Update() {
	MainCamera.GetXZ(ReferPlayerX(), ReferPlayerZ());
	Control();
	MoveAll();
//	CrashDecision();
//	HitDecision();
//	DeleteUseless();
	DrawAll();
	FC.Wait();
}

void IngameDataManagement::DrawAll() {
	SetDrawScreen(DX_SCREEN_BACK);
	ClearDrawScreen();

	DrawSea();
	DrawShips();
//	DrawPlanes();
//	DrawAmmo();
//	DrawBomb();
//	DrawTorpedo();
	if (TEST_SHOW_ON)
		TEST_DRAW();

	ScreenFlip();
}

void IngameDataManagement::DrawShips() {
	//—FŒR‚ð•`‰æ‚·‚é 
	for (auto mark = alliesFleet.begin();
		mark != alliesFleet.end(); mark++) {
		if (mark->ReferAlive()) {
			mark->Draw(MainCamera);
		}
	}
}

void IngameDataManagement::DrawSea() {
	/*int MX = PL.ReferMapX();
	int MZ = PL.ReferMapZ();
	//‚Å‚«‚é‚¾‚¯‘½‚ß‚É‚µ‚Ü‚µ‚½
	int numOnX = Screen::SCREEN_X / MX + 2;
	int numOnZ = Screen::SCREEN_Z / MZ + 2;
	int startX = -(Screen::SCREEN_X % MX) + 
		(int)(MainCamera.ReferCameraX()) % MX;
	int startZ = -(Screen::SCREEN_Z % MZ) +
		(int)(MainCamera.ReferCameraZ()) % MZ;
	if (startX > 0) {
		startX = 0 - startX;
	}
	if (startZ > 0) {
		startZ = 0 - startZ;
	}

	for (int i = 0; i < numOnX; i++) {
		for (int j = 0; j < numOnZ; j++) {
			DrawGraph(startX + MX * i, startZ + MZ * j,
				*PL.ReferMapHandle(), FALSE);
		}
	}*/
	DrawRectGraph(0, 0, (int)(MainCamera.ReferPrintOutX()),
		(int)(MainCamera.ReferPrintOutZ())
		, Screen::SCREEN_X, Screen::SCREEN_Z, 
		*PL.ReferMapHandle(), FALSE, FALSE);
}

void IngameDataManagement::TEST() {
	alliesFleet.push_back(ShipMain());
	auto ship = alliesFleet.begin();
	ship->InifThisShip(PL.ReferBattleCrusierHandle(4000), 4000);
	ship->NewCoordX(400);
	ship->NewCoordZ(200);
	ship->SetLength(PL.ReferShipSizeX());
	ship->SetWidth(PL.ReferShipSizeZ());
	ship->TEST();
}

void IngameDataManagement::Control() {
	auto ship = alliesFleet.begin();
	ship->ControlThisShip(CT.GetCommand());
}

void IngameDataManagement::MoveAll() {
	MoveShips();
}

void IngameDataManagement::MoveShips() {
	for (auto ship = alliesFleet.begin();
		ship != alliesFleet.end();
		ship++) {
		ship->Move();
	}
}

void IngameDataManagement::TEST_DRAW() {
	unsigned int Cr;
	Cr = GetColor(255, 255, 255);
	auto ship = alliesFleet.begin();
	char CharNum[255];
	_itoa_s((int)(ship->ReferSpeedOnZ() * 1000), CharNum, 10);
	DrawString(10, 10, "Speed", Cr);
	DrawString(60, 10, CharNum, Cr);
	if (ship->ReferReturnOn()) {
		DrawString(10, 30, "Alignment On", Cr);
	}
	else {
		DrawString(10, 30, "Alignment Off", Cr);
	}
	_itoa_s((int)(ship->ReferChangingRadian() * 1000), CharNum, 10);
	DrawString(10, 50, "Radian(C)", Cr);
	DrawString(100, 50, CharNum, Cr);
	_gcvt_s(CharNum, ship->ReferCoordX(), 10);
	DrawString(10, 70, "X", Cr);
	DrawString(30, 70, CharNum, Cr);
	_gcvt_s(CharNum, ship->ReferCoordZ(), 10);
	DrawString(10, 90, "Z", Cr);
	DrawString(30, 90, CharNum, Cr);
	_gcvt_s(CharNum, ship->ReferRadianOnZ(), 10);
	DrawString(10, 110, "Radian(R)", Cr);
	DrawString(100, 110, CharNum, Cr);
	_gcvt_s(CharNum, cos(ship->ReferRadianOnZ()), 10);
	DrawString(10, 130, "Cos", Cr);
	DrawString(100, 130, CharNum, Cr);
	_gcvt_s(CharNum, sin(ship->ReferRadianOnZ()), 10);
	DrawString(10, 150, "Sin", Cr);
	DrawString(100, 150, CharNum, Cr);

}	