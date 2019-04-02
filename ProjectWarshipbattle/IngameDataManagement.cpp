#include "IngameDataManagement.h"

IngameDataManagement::~IngameDataManagement()
{
}

/*メインルート*/
void IngameDataManagement::Update() {
	CUI.SetNormalStatus();/*ここはテストバージョン*/

	MainCamera.GetXZ(ReferPlayerX(), ReferPlayerZ());
	Control();//コマンドを受け取って、船の状態を変更する
	GetNewEffect();
	MoveAll();//船の状態による座標を変更する
//	CrashDecision();//船の間のあたり判定
//	HitDecision();//砲弾と船の間のあたり判定
	DeleteUseless();//入らないものを消す
	CheckAndPlaySound();
	DrawAll();//全部更新した後画面を描く
	FC.Wait();//60フレームに合わせるように待つ
}

/****************************************************/
/*                     描画関連                     */
/****************************************************/
void IngameDataManagement::DrawAll() {
	SetDrawScreen(DX_SCREEN_BACK);//裏画面に描画する
	ClearDrawScreen();

	DrawSea();

	DrawEffectUnderShips();
//	DrawTorpedo();
	DrawShips();
	DrawEffectBeyondShips();

//	DrawPlanes();
	DrawAmmo();
//	DrawBomb();

	/*UI関連*/
	auto ship = alliesFleet.begin();
	UI.DrawUI();
	UI.DrawUINeedInput(&*ship);
	DrawShipsOnMiniMap();

	SIMPLE_USER_INTERFACE();

	CUI.Draw();

	
	if (TEST_SHOW_ON)
		TEST_DRAW();
	
	ScreenFlip();
}

void IngameDataManagement::DrawShips() {
	//友軍を描画する 
	if (!alliesFleet.empty())
		for (auto mark = alliesFleet.begin();
			mark != alliesFleet.end(); mark++) {
		if (mark->ReferAlive()) {
			if (mark == alliesFleet.begin())
				mark->Draw(MainCamera);
			else
				mark->DrawSub(MainCamera);
		}
	}
	if(!enemyFleet.empty())
		for (auto ship = enemyFleet.begin();
			ship != enemyFleet.end(); ship++) {
		if (ship->ReferAlive()) {
			ship->DrawSub(MainCamera);
		}
	}
}

void IngameDataManagement::DrawShipsOnMiniMap() {
	//友軍艦隊
	if(!alliesFleet.empty())
	for (auto ship = alliesFleet.begin();
		ship != alliesFleet.end(); ship++) {
		if (ship->ReferAlive()) {
			UI.DrawShipOnTheMap(ship->ReferCoordX(),
				ship->ReferCoordZ(), false);
		}
	}
	if (!enemyFleet.empty())
		for (auto ship = enemyFleet.begin();
			ship != enemyFleet.end(); ship++) {
		if (ship->ReferAlive()) {
			UI.DrawShipOnTheMap(ship->ReferCoordX(),
				ship->ReferCoordZ(), true);
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

/*船の下にあるエフェクトを描く*/
void IngameDataManagement::DrawEffectUnderShips() {
	/*水泡演出*/
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 90);
	if (!bubbleList.empty())
	for (auto bubble = bubbleList.begin();
		bubble != bubbleList.end();
		bubble++) {
		bubble->Draw((int)MainCamera.ReferRealCameraX(),
			(int)MainCamera.ReferRealCameraZ());
	}
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}

/*船の上にあるエフェクトを描く*/
void IngameDataManagement::DrawEffectBeyondShips() {
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 240);
	if (!smokeList.empty())
	for (auto smoke = smokeList.begin();
		smoke != smokeList.end();
		smoke++) {
		smoke->Draw((int)MainCamera.ReferRealCameraX(),
			(int)MainCamera.ReferRealCameraZ());
	}
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}

void IngameDataManagement::DrawAmmo() {
	if (!shellList.empty())
	for (auto shell = shellList.begin();
		shell != shellList.end();
		shell++) {
		shell->Draw((int)MainCamera.ReferRealCameraX(),
			(int)MainCamera.ReferRealCameraZ());
	}
}

void IngameDataManagement::SIMPLE_USER_INTERFACE() {
	//テスト・展示用UI
	unsigned int Cr;
	Cr = GetColor(255, 255, 255);
	auto ship = alliesFleet.begin();
	char CharNum[255];

	SetFontSize(20);
	ChangeFont("HG行書体");

	DrawString(100, 650, "速度:", Cr);
	if (ship->ReferSpeedOnZ()*28.0f > 0.5f)
		_gcvt_s(CharNum, ship->ReferSpeedOnZ()*28.0f, 2);
	else if (ship->ReferSpeedOnZ()*28.0f > 10.0f)
		_gcvt_s(CharNum, ship->ReferSpeedOnZ()*28.0f, 3);
	else
		_gcvt_s(CharNum, 0.0f, 2);
	DrawString(180, 650, CharNum, Cr);
	DrawString(220, 650, "Kt", Cr);

	DrawString(100, 670, "出力", Cr);
	_gcvt_s(CharNum, ship->ReferOutPutRate() * 100, 3);
	DrawString(180, 670, CharNum, Cr);
	DrawString(220, 670, "%", Cr);

	DrawString(100, 710, "航行方向", Cr);
	if (ship->ReferChangingRadian() > 0)
		DrawString(200, 710, "右へ", Cr);
	else if (ship->ReferChangingRadian() < 0)
		DrawString(200, 710, "左へ", Cr);
	else
		DrawString(200, 710, "前方", Cr);
}

/****************************************************/
/*                     テスト　                     */
/****************************************************/
void IngameDataManagement::TEST() {
	alliesFleet.push_back(ShipMain());
	auto ship = alliesFleet.begin();
	//ここの部分は初期化関数とファイル読み込みはまだ出来ていない
	//初期化関数は下のようにしたい
	ship->InifThisShip(PL.ReferBattleCrusierHandle(4000), 
		PL.ReferBattleCrusierShadowHandle(4000), 4000, ET, &SL);
	ship->NewCoordX(2200);
	ship->NewCoordZ(1500);
	ship->SetLength(PL.ReferShipSizeX());
	ship->SetWidth(PL.ReferShipSizeZ());
	ship->TEST();
	ship->SetWeaponTest(&PL);

	enemyFleet.push_back(ShipMain());
	auto enemyShip = enemyFleet.begin();

	enemyShip->InifThisShip(PL.ReferBattleCrusierHandle(4000),
		PL.ReferBattleCrusierShadowHandle(4000), 4000, ET, &SL);
	enemyShip->NewCoordX(3000);
	enemyShip->NewCoordZ(1800);
	enemyShip->SetLength(PL.ReferShipSizeX());
	enemyShip->SetWidth(PL.ReferShipSizeZ());
	enemyShip->TEST();
	enemyShip->SetWeaponTest(&PL);
}

void IngameDataManagement::TEST_DRAW() {
	unsigned int Cr;
	Cr = GetColor(255, 255, 255);
	auto ship = alliesFleet.begin();
	ship->TestDraw(MainCamera.ReferRealCameraX(),
		MainCamera.ReferRealCameraZ());
	char CharNum[255];

	SetFontSize(15);
	ChangeFont("HGｺﾞﾐｯｸM");

	_gcvt_s(CharNum, ship->ReferSpeedOnZ() * 100, 10);
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

/****************************************************/
/*                   コントロール                   */
/****************************************************/
/*コマンドを受け取って、新たなものを生成する*/
void IngameDataManagement::Control() {
	int answer;

	answer = CUI.CheckChoice();


	if (answer == CommandSerial::INCREASE_OUTPUT ||
		answer == CommandSerial::DECREASE_OUTPUT ||
		answer == CommandSerial::MENU ||
		answer == CommandSerial::TURN_RETURN)
		if (!CUI.ReferClickable())
			return;

	if (answer == -1)
		answer = CT.GetCommand();


	/*船を操作*/
	auto ship = alliesFleet.begin();
	ship->ControlThisShip(answer);


	if (answer == CommandSerial::SHOOT) {
		TestShoot();
	}

	/*UI関連*/
	if (answer == CommandSerial::MENU) {
		if (!CUI.CheckMenuOpened()) {
			CUI.LetMeSeeMenu();
		}
		else {
			CUI.CloseMenu();
		}
	}

	/*テストビュー*/
	if (answer == CommandSerial::TEST_VIEW_ON)
		TEST_SHOW_ON = !TEST_SHOW_ON;

	/*ゲーム終了*/
	if (answer == CommandSerial::EXIT) {
		GameOver = true;
	}

	CUI.SetClickTime();
}

/****************************************************/
/*                     移動関連                     */
/****************************************************/
void IngameDataManagement::MoveAll() {
	MoveShips();
	MoveEffects();
	MoveAmmo();
}

void IngameDataManagement::MoveShips() {
	if(!alliesFleet.empty())
	for (auto ship = alliesFleet.begin();
		ship != alliesFleet.end();
		ship++) {
		ship->Move();
	}
	if(!enemyFleet.empty())
	for (auto ship = enemyFleet.begin();
		ship != enemyFleet.end();
		ship++) {
		ship->Move();
	}
}

void IngameDataManagement::MoveEffects() {
	if(!bubbleList.empty())
	for (auto bubble = bubbleList.begin();
		bubble != bubbleList.end();
		bubble++) {
		bubble->Move();
	}
	if(!smokeList.empty())
	for (auto smoke = smokeList.begin();
		smoke != smokeList.end();
		smoke++) {
		smoke->Move();
	}
}

void IngameDataManagement::MoveAmmo() {
	if (!shellList.empty())
		for (auto shell = shellList.begin();
			shell != shellList.end();
			shell++) {
		shell->Move();
	}
}

/****************************************************/
/*                    データ関連                    */
/****************************************************/
void IngameDataManagement::Inif() {
	PL.AllInif();
	UI.InifUI(&PL);
	ET.InifEffectTemplate(&PL);
	SL.Inif();
	CT.Inif(&SL);
	CUI.IngameInif(&PL,&SL);
}

void IngameDataManagement::Free() {
	PL.FREE_ALL();
	SL.FreeAll();
	CUI.Free();
}

void IngameDataManagement::DeleteUseless() {
	DeleteUselessEffect();
	DeleteUselessAmmo();
}

void IngameDataManagement::CheckAndPlaySound() {
	auto ship = alliesFleet.begin();
	ship->CheckAndPlaySound();
}

/****************************************************/
/*                  エフェクト関連                  */
/****************************************************/
void IngameDataManagement::GetNewEffect() {
	/*進行中の水泡生成*/
	if (!alliesFleet.empty()) {
		for (auto ship = alliesFleet.begin();
			ship != alliesFleet.end();
			ship++) {
			if (ship->ReferSpeedOnZ() > 0.1 && rand() % 3 == 0
				&& rand() % 100 > ship->ReferSpeedOnZ() * 10) {
				//for(int i = 0; i < ship->ReferBubbleCount(); i++)
				for (int i = 0; i < 4; i++)
					bubbleList.push_back(ship->NewBubble(i));
			}
		}
		for (auto ship = alliesFleet.begin();
			ship != alliesFleet.end();
			ship++) {
			if (ship->ReferOutPutRate() != 0) {
				if ((rand() % 8 < ship->ReferSpeedOnZ() * 10)
					&& rand() % 4 == 0) {
					//for(int i = 0; i < ship->ReferSmokeCount(); i++)
					for (int i = 0; i < 2; i++)
						smokeList.push_back(ship->NewSmoke(i));
				}
			}
		}
	}

	if (!enemyFleet.empty()) {
		for (auto ship = enemyFleet.begin();
			ship != enemyFleet.end();
			ship++) {
			if (ship->ReferSpeedOnZ() > 0.1 && rand() % 3 == 0
				&& rand() % 100 > ship->ReferSpeedOnZ() * 10) {
				//for(int i = 0; i < ship->ReferBubbleCount(); i++)
				for (int i = 0; i < 4; i++)
					bubbleList.push_back(ship->NewBubble(i));
			}
		}
		for (auto ship = enemyFleet.begin();
			ship != enemyFleet.end();
			ship++) {
			if (ship->ReferOutPutRate() != 0) {
				if ((rand() % 8 < ship->ReferSpeedOnZ() * 10)
					&& rand() % 4 == 0) {
					//for(int i = 0; i < ship->ReferSmokeCount(); i++)
					for (int i = 0; i < 2; i++)
						smokeList.push_back(ship->NewSmoke(i));
				}
			}
		}
	}
}

void IngameDataManagement::DeleteUselessEffect() {
	/*バブル*/
	if (!bubbleList.empty())
		for (auto bubble = bubbleList.begin();
			bubble != bubbleList.end();
			bubble++) {
		if (bubble->ReferTimeUp()) {
			bubble = bubbleList.erase(bubble);
		}
		if (bubbleList.empty() || bubble == bubbleList.end())
			break;
	}
	if (!smokeList.empty())
		for (auto smoke = smokeList.begin();
			smoke != smokeList.end();
			smoke++) {
		if (smoke->ReferTimeUp()) {
			smoke = smokeList.erase(smoke);
		}
		if (smokeList.empty() || smoke == smokeList.end())
			break;
	}
}

/****************************************************/
/*                     射撃関連                     */
/****************************************************/

void IngameDataManagement::TestShoot() {
	FiringData FD;
	//ゲーム中では、敵が射撃する時に全部trueにする
	FD.isThisMainWeapon = true;
	for (int i = 0; i < 8; i++) {
		FD.selected[i] = true;
	}
	
	auto ship = alliesFleet.begin();
	InputNewAmmo(&*ship, FD);
}

void IngameDataManagement::InputNewAmmo(ShipMain *SM, FiringData FD) {
	int weaponAmount = SM->ReferWeaponCount(FD.isThisMainWeapon);
	for (int i = 0; i < weaponAmount; i++) {
		if (FD.selected[i]) {
			if (SM->IsThisOneUsable(i, FD.isThisMainWeapon)) {
				shellList.push_back(SM->Shoot(i,FD.isThisMainWeapon));
			}
		}
	}
}

void IngameDataManagement::DeleteUselessAmmo() {
	if (!shellList.empty())
		for (auto shell = shellList.begin();
			shell != shellList.end();
			shell++) {
		if (shell->FallIntoWater()) {
			shell = shellList.erase(shell);
		}
		if (shellList.empty() || shell == shellList.end())
			break;
	}
}

/****************************************************/
/*                     あたり判定                   */
/****************************************************/
void IngameDataManagement::SimpleHitDecision() {
	if (!shellList.empty())
		for (auto shell = shellList.begin();
			shell != shellList.end();
			shell++) {
		if (!alliesFleet.empty())
			for (auto ship = alliesFleet.begin();
				ship != alliesFleet.end();
				ship++) {
			if (shell->ReferSerialNumber() != ship->ReferSerialNumber()) {
				double distance;
				distance = Distance3D(shell->ReferCoord(), ship->ReferCoord());
				if (distance <= ship->ReferShipCrashR()) {
			
				}
			}
		}
		if (!enemyFleet.empty())
			for (auto ship = enemyFleet.begin();
				ship != enemyFleet.end();
				ship++) {
			if (shell->ReferSerialNumber() != ship->ReferSerialNumber()) {
				double distance;
				distance = Distance3D(shell->ReferCoord(), ship->ReferCoord());
				if (distance <= ship->ReferShipCrashR()) {

				}
			}
		}
	}
}