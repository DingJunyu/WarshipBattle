#include "IngameDataManagement.h"

IngameDataManagement::IngameDataManagement()
{
}


IngameDataManagement::~IngameDataManagement()
{
}

void IngameDataManagement::Update(Camera CM, PictureLoader PL) {
//	CrashDecision();
//	HitDecision();
//	DeleteUseless();
	DrawAll(CM.ReferCameraX(), CM.ReferCameraZ(), PL);
}

void IngameDataManagement::DrawAll(double CX,double CZ, PictureLoader PL) {
	SetDrawScreen(DX_SCREEN_BACK);
	ClearDrawScreen();

	DrawSea(CX, CZ, PL);
//	DrawShips(CX, CZ, PL);
//	DrawPlanes(CX, CZ, PL);
//	DrawAmmo(CX, CZ, PL);
//	DrawBomb(CX, CZ, PL);
//	DrawTorpedo(CX, CZ, PL);

	ScreenFlip();
}

void IngameDataManagement::DrawShips(double CX, double CZ, PictureLoader PL) {
	//—FŒR‚ð•`‰æ‚·‚é 
	/*
	for (auto mark = alliesFleet.begin();
		mark != alliesFleet.end(); mark++) {
		if (mark->ReferAlive()) {
			mark->Draw(CX,CZ);
		}
	}*/
}

void IngameDataManagement::DrawSea(double CX, double CZ, PictureLoader PL) {
	int MX = PL.ReferMapX();
	int MZ = PL.ReferMapZ();
	int numOnX = Screen::SCREEN_X / MX + 2;
	int numOnZ = Screen::SCREEN_Z / MZ + 2;
	int startX = -(Screen::SCREEN_X % MX);
	int startZ = -(Screen::SCREEN_Z % MZ);

	for (int i = 0; i < numOnX; i++) {
		for (int j = 0; j < numOnZ; j++) {
			DrawGraph(startX + MX * i, startZ + MZ * j,
				PL.ReferMapHandle(), FALSE);
		}
	}
}