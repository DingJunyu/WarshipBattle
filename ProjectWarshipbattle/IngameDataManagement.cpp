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
	UI.DrawUI();
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
	double mapX = PL.ReferMapX();
	double mapZ = PL.ReferMapZ();

	double MCPOX = MainCamera.ReferPrintOutX(mapX);
	double MCPOZ = MainCamera.ReferPrintOutZ(mapZ);

	int graphNumOnX = 2;
	int graphNumOnZ = 2;

	graphNumOnX = (int)(MainCamera.ReferCameraX() / mapX);
	graphNumOnZ = (int)(MainCamera.ReferCameraZ() / mapZ);

	//ˆê–‡‚Ì‰æ‘œ‚ðŽg‚Á‚Ä˜A‘±•`‚­
	{
		DrawRectGraph(//¶ã
			(int)(-MCPOX - mapX),
			(int)(-MCPOZ - mapZ),
			(int)0,
			(int)0,
			(int)mapX, (int)mapZ,
			*PL.ReferMapHandle(), FALSE, FALSE);

		DrawRectGraph(//ã
			(int)(-MCPOX),
			(int)(-MCPOZ - mapZ),
			(int)0,
			(int)0,
			(int)mapX, (int)mapZ,
			*PL.ReferMapHandle(), FALSE, FALSE);

		DrawRectGraph(//‰Eã
			(int)(-MCPOX + mapX),
			(int)(-MCPOZ - mapZ),
			(int)0,
			(int)0,
			(int)mapX, (int)mapZ,
			*PL.ReferMapHandle(), FALSE, FALSE);

		DrawRectGraph(//¶
			(int)(-MCPOX - mapX),
			(int)(-MCPOZ),
			(int)0,
			(int)0,
			(int)mapX, (int)mapZ,
			*PL.ReferMapHandle(), FALSE, FALSE);

		DrawRectGraph(//’†
			(int)(-MCPOX),
			(int)(-MCPOZ),
			(int)0,
			(int)0,
			(int)mapX, (int)mapZ,
			*PL.ReferMapHandle(), FALSE, FALSE);

		DrawRectGraph(//‰E
			(int)(-MCPOX + mapX),
			(int)(-MCPOZ),
			(int)0,
			(int)0,
			(int)mapX, (int)mapZ,
			*PL.ReferMapHandle(), FALSE, FALSE);

		DrawRectGraph(//¶‰º
			(int)(-MCPOX - mapX),
			(int)(-MCPOZ + mapZ),
			(int)0,
			(int)0,
			(int)mapX, (int)mapZ,
			*PL.ReferMapHandle(), FALSE, FALSE);

		DrawRectGraph(//‰º
			(int)(-MCPOX),
			(int)(-MCPOZ + mapZ),
			(int)0,
			(int)0,
			(int)mapX, (int)mapZ,
			*PL.ReferMapHandle(), FALSE, FALSE);

		DrawRectGraph(//‰E‰º
			(int)(-MCPOX + mapX),
			(int)(-MCPOZ + mapZ),
			(int)0,
			(int)0,
			(int)mapX, (int)mapZ,
			*PL.ReferMapHandle(), FALSE, FALSE); 
	}
}

void IngameDataManagement::TEST() {
	alliesFleet.push_back(ShipMain());
	auto ship = alliesFleet.begin();
	ship->InifThisShip(PL.ReferBattleCrusierHandle(4000), 
		PL.ReferBattleCrusierShadowHandle(4000), 4000);
	ship->NewCoordX(2200);
	ship->NewCoordZ(1500);
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
	_gcvt_s(CharNum, ship->ReferSpeedOnZ()*100, 10);
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
	DrawString(50, 130, CharNum, Cr);
	_gcvt_s(CharNum, sin(ship->ReferRadianOnZ()), 10);
	DrawString(10, 150, "Sin", Cr);
	DrawString(50, 150, CharNum, Cr);
	_gcvt_s(CharNum, ship->ReferOutPutRate(), 10);
	DrawString(10, 170, "OutPut", Cr);
	DrawString(70, 170, CharNum, Cr);
}	

void IngameDataManagement::Inif() {
	PL.AllInif();
	UI.InifUI(&PL);
}

void IngameDataManagement::Free() {
	PL.FREE_ALL();
}