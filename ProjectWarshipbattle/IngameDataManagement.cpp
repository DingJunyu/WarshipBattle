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
	int MX = PL.ReferMapX();
	int MZ = PL.ReferMapZ();
	//‚Å‚«‚é‚¾‚¯‘½‚ß‚É‚µ‚Ü‚µ‚½
	int numOnX = Screen::SCREEN_X / MX + 3;
	int numOnZ = Screen::SCREEN_Z / MZ + 3;
	int startX = -(Screen::SCREEN_X % MX) + 
		(int)(MainCamera.ReferCameraX())%MX;
	int startZ = -(Screen::SCREEN_Z % MZ) +
		(int)(MainCamera.ReferCameraZ())%MZ;

	for (int i = 0; i < numOnX; i++) {
		for (int j = 0; j < numOnZ; j++) {
			DrawGraph(startX + MX * i, startZ + MZ * j,
				*PL.ReferMapHandle(), FALSE);
		}
	}
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