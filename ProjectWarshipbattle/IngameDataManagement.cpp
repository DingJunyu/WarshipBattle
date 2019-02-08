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
	DeleteUseless();
	DrawAll();
	FC.Wait();
}

void IngameDataManagement::DrawAll() {
	SetDrawScreen(DX_SCREEN_BACK);
	ClearDrawScreen();

	DrawSea();

	DrawEffectUnderShips();
	DrawShips();
	DrawEffectBeyondShips();
	UI.DrawUI();
	DrawShipsOnMiniMap();
//	DrawPlanes();
//	DrawAmmo();
//	DrawBomb();
//	DrawTorpedo();
	
	if (TEST_SHOW_ON)
		TEST_DRAW();
	
	ScreenFlip();
}

void IngameDataManagement::DrawShips() {
	//友軍を描画する 
	for (auto mark = alliesFleet.begin();
		mark != alliesFleet.end(); mark++) {
		if (mark->ReferAlive()) {
			mark->Draw(MainCamera);
		}
	}
}

void IngameDataManagement::DrawShipsOnMiniMap() {
	//友軍艦隊
	for (auto mark = alliesFleet.begin();
		mark != alliesFleet.end(); mark++) {
		if (mark->ReferAlive()) {
			UI.DrawShipOnTheMap(mark->ReferCoordX(),
				mark->ReferCoordZ(), false);
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

	//一枚の画像を使って連続描く
	{
		DrawRectGraph(//左上
			(int)(-MCPOX - mapX),
			(int)(-MCPOZ - mapZ),
			(int)0,
			(int)0,
			(int)mapX, (int)mapZ,
			*PL.ReferMapHandle(), FALSE, FALSE);

		DrawRectGraph(//上
			(int)(-MCPOX),
			(int)(-MCPOZ - mapZ),
			(int)0,
			(int)0,
			(int)mapX, (int)mapZ,
			*PL.ReferMapHandle(), FALSE, FALSE);

		DrawRectGraph(//右上
			(int)(-MCPOX + mapX),
			(int)(-MCPOZ - mapZ),
			(int)0,
			(int)0,
			(int)mapX, (int)mapZ,
			*PL.ReferMapHandle(), FALSE, FALSE);

		DrawRectGraph(//左
			(int)(-MCPOX - mapX),
			(int)(-MCPOZ),
			(int)0,
			(int)0,
			(int)mapX, (int)mapZ,
			*PL.ReferMapHandle(), FALSE, FALSE);

		DrawRectGraph(//中
			(int)(-MCPOX),
			(int)(-MCPOZ),
			(int)0,
			(int)0,
			(int)mapX, (int)mapZ,
			*PL.ReferMapHandle(), FALSE, FALSE);

		DrawRectGraph(//右
			(int)(-MCPOX + mapX),
			(int)(-MCPOZ),
			(int)0,
			(int)0,
			(int)mapX, (int)mapZ,
			*PL.ReferMapHandle(), FALSE, FALSE);

		DrawRectGraph(//左下
			(int)(-MCPOX - mapX),
			(int)(-MCPOZ + mapZ),
			(int)0,
			(int)0,
			(int)mapX, (int)mapZ,
			*PL.ReferMapHandle(), FALSE, FALSE);

		DrawRectGraph(//下
			(int)(-MCPOX),
			(int)(-MCPOZ + mapZ),
			(int)0,
			(int)0,
			(int)mapX, (int)mapZ,
			*PL.ReferMapHandle(), FALSE, FALSE);

		DrawRectGraph(//右下
			(int)(-MCPOX + mapX),
			(int)(-MCPOZ + mapZ),
			(int)0,
			(int)0,
			(int)mapX, (int)mapZ,
			*PL.ReferMapHandle(), FALSE, FALSE); 
	}
}

void IngameDataManagement::DrawEffectUnderShips() {
	/*水泡演出*/
	for (auto bubble = bubbleList.begin();
		bubble != bubbleList.end();
		bubble++) {
		bubble->Draw(MainCamera.ReferRealCameraX(),
			MainCamera.ReferRealCameraZ());
	}
}

void IngameDataManagement::DrawEffectBeyondShips() {
	for (auto smoke = smokeList.begin();
		smoke != smokeList.end();
		smoke++) {
		smoke->Draw(MainCamera.ReferRealCameraX(),
			MainCamera.ReferRealCameraZ());
	}
}

void IngameDataManagement::TEST() {
	alliesFleet.push_back(ShipMain());
	auto ship = alliesFleet.begin();
	ship->InifThisShip(PL.ReferBattleCrusierHandle(4000), 
		PL.ReferBattleCrusierShadowHandle(4000), 4000, ET);
	ship->NewCoordX(2200);
	ship->NewCoordZ(1500);
	ship->SetLength(PL.ReferShipSizeX());
	ship->SetWidth(PL.ReferShipSizeZ());
	ship->TEST();
}

/*コマンドを受け取って、新たなものを生成する*/
void IngameDataManagement::Control() {
	int answer = CT.GetCommand();
	auto ship = alliesFleet.begin();

	/*船を操作*/
	ship->ControlThisShip(answer);

	/*テストビュー*/
	if (answer == CommandSerial::TEST_VIEW_ON)
		TEST_SHOW_ON = !TEST_SHOW_ON;

	GetNewEffect();
}

void IngameDataManagement::MoveAll() {
	MoveShips();
	MoveEffects();
}

void IngameDataManagement::MoveShips() {
	for (auto ship = alliesFleet.begin();
		ship != alliesFleet.end();
		ship++) {
		ship->Move();
	}
}

void IngameDataManagement::MoveEffects() {
	for (auto bubble = bubbleList.begin();
		bubble != bubbleList.end();
		bubble++) {
		bubble->Move();
	}
	for (auto smoke = smokeList.begin();
		smoke != smokeList.end();
		smoke++) {
		smoke->Move();
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
	DrawString(10, 170, "OutPutRate", Cr);
	DrawString(110, 170, CharNum, Cr);
}	

void IngameDataManagement::Inif() {
	PL.AllInif();
	UI.InifUI(&PL);
	ET.InifEffectTemplate(&PL);
}

void IngameDataManagement::Free() {
	PL.FREE_ALL();
}

void IngameDataManagement::GetNewEffect() {
	/*進行中の水泡生成*/
	for (auto ship = alliesFleet.begin();
		ship != alliesFleet.end();
		ship++) {
		if (ship->ReferSpeedOnZ() > 0.02 && rand()%3==0 ) {
			bubbleList.push_back(ship->NewBubble(0));
			bubbleList.push_back(ship->NewBubble(1));
			bubbleList.push_back(ship->NewBubble(2));
			bubbleList.push_back(ship->NewBubble(3));
			bubbleList.push_back(ship->NewBubble(4));
		}
	}
	for (auto ship = alliesFleet.begin();
		ship != alliesFleet.end();
		ship++) {
		if (ship->ReferCoordZ() != 0) {
			if ((rand() % 8 < ship->ReferSpeedOnZ() * 10)
				&& rand() % 4 == 0) {
				smokeList.push_back(ship->NewSmoke(0));
				smokeList.push_back(ship->NewSmoke(1));
			}
		}
	}
}

void IngameDataManagement::DeleteUseless() {
	/*バブル*/
	for (auto bubble = bubbleList.begin();
		bubble != bubbleList.end();
		bubble++) {
		if (bubble->ReferTimeUp()) {
			bubble = bubbleList.erase(bubble);
		}
		if (bubbleList.empty())
			break;
	}
	for (auto smoke = smokeList.begin();
		smoke != smokeList.end();
		smoke++) {
		if (smoke->ReferTimeUp()) {
			smoke = smokeList.erase(smoke);
		}
		if (smokeList.empty())
			break;
	}
}