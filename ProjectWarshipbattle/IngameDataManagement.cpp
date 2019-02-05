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
	//�F�R��`�悷�� 
	for (auto mark = alliesFleet.begin();
		mark != alliesFleet.end(); mark++) {
		if (mark->ReferAlive()) {
			mark->Draw(MainCamera);
		}
	}
}

void IngameDataManagement::DrawSea() {
	double halfMapX = PL.ReferMapX() / 2;
	double halfMapZ = PL.ReferMapZ() / 2;

	double centerGraphStartX;
	double centerGraphStartZ;
	double graphTopX;
	double graphTopZ;

	if (MainCamera.ReferPrintOutZ(PL.ReferMapZ()) < halfMapZ) {
		centerGraphStartZ =  -
			MainCamera.ReferPrintOutZ(halfMapZ);
		graphTopZ = 0;
	}
	else {
		centerGraphStartZ =  -
			MainCamera.ReferPrintOutZ(halfMapZ);
		graphTopZ = MainCamera.ReferPrintOutZ(PL.ReferMapZ());
	}

	if (MainCamera.ReferPrintOutX(PL.ReferMapX()) < halfMapX) {
		centerGraphStartX = -
			MainCamera.ReferPrintOutX(halfMapX);
		graphTopX = 0;
	}
	else{
		centerGraphStartX = PL.ReferMapX() -
			MainCamera.ReferPrintOutX(halfMapX);
		graphTopX = MainCamera.ReferPrintOutX(PL.ReferMapX());
	}

	DrawRectGraph(
		(int)centerGraphStartX,
		(int)centerGraphStartZ,
		(int)graphTopX,
		(int)graphTopZ, 
		PL.ReferMapX(), PL.ReferMapZ(),
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
	_gcvt_s(CharNum, ship->ReferChangingRadian(), 10);
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
	_gcvt_s(CharNum, ship->ReferOutPutRate(), 10);
	DrawString(10, 170, "OutPut", Cr);
	DrawString(70, 170, CharNum, Cr);
}	