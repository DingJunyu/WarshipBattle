#include "IngameDataManagement.h"

IngameDataManagement::IngameDataManagement()
{
}


IngameDataManagement::~IngameDataManagement()
{
}

void IngameDataManagement::Update(Camera CM) {
	CrashDecision();
	HitDecision();
	DeleteUseless();
	DrawAll(CM.ReferCameraX(),CM.ReferCameraZ);
}

void IngameDataManagement::DrawAll(int CX,int CZ) {
	SetDrawScreen(DX_SCREEN_BACK);
	ClearDrawScreen();

	DrawSea();
	DrawShips(CX,CZ);
	DrawPlanes(CX, CZ);
	DrawAmmo(CX, CZ);
	DrawBomb(CX, CZ);
	DrawTorpedo(CX, CZ);

	ScreenFlip();
}

void IngameDataManagement::DrawShips(int CX, int CZ) {
	//—FŒR‚ð•`‰æ‚·‚é
	for (auto mark = alliesFleet.begin();
		mark != alliesFleet.end(); mark++) {
		if (mark->ReferAlive()) {
			mark->Draw(CX,CZ);
		}
	}
}

