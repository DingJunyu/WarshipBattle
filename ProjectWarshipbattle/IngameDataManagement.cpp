#include "IngameDataManagement.h"

IngameDataManagement::IngameDataManagement()
{
}


IngameDataManagement::~IngameDataManagement()
{
}


void IngameDataManagement::DrawAll() {
	SetDrawScreen(DX_SCREEN_BACK);
	ClearDrawScreen();

	DrawShips();
	DrawPlanes();
	DrawAmmo();
	DrawBomb();
	DrawTorpedo();

	ScreenFlip();
}