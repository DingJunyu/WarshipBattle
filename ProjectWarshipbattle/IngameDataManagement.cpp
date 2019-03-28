#include "IngameDataManagement.h"

IngameDataManagement::~IngameDataManagement()
{
}

/*���C�����[�g*/
void IngameDataManagement::Update() {
	CUI.SetNormalStatus();/*�����̓e�X�g�o�[�W����*/

	MainCamera.GetXZ(ReferPlayerX(), ReferPlayerZ());
	Control();//�R�}���h���󂯎���āA�D�̏�Ԃ�ύX����
	GetNewEffect();
	MoveAll();//�D�̏�Ԃɂ����W��ύX����
//	CrashDecision();//�D�̊Ԃ̂����蔻��
//	HitDecision();//�C�e�ƑD�̊Ԃ̂����蔻��
	DeleteUseless();//����Ȃ����̂�����
	CheckAndPlaySound();
	DrawAll();//�S���X�V�������ʂ�`��
	FC.Wait();//60�t���[���ɍ��킹��悤�ɑ҂�
}

/****************************************************/
/*                     �`��֘A                     */
/****************************************************/
void IngameDataManagement::DrawAll() {
	SetDrawScreen(DX_SCREEN_BACK);//����ʂɕ`�悷��
	ClearDrawScreen();

	DrawSea();

	DrawEffectUnderShips();
//	DrawTorpedo();
	DrawShips();
	DrawEffectBeyondShips();

//	DrawPlanes();
	DrawAmmo();
//	DrawBomb();


	UI.DrawUI();
	DrawShipsOnMiniMap();

	SIMPLE_USER_INTERFACE();

	CUI.Draw();

	
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

void IngameDataManagement::DrawShipsOnMiniMap() {
	//�F�R�͑�
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

	//�ꖇ�̉摜���g���ĘA���`��
	{
		DrawRectGraph(//����
			(int)(-MCPOX - mapX),
			(int)(-MCPOZ - mapZ),
			(int)0,
			(int)0,
			(int)mapX, (int)mapZ,
			*PL.ReferMapHandle(), FALSE, FALSE);

		DrawRectGraph(//��
			(int)(-MCPOX),
			(int)(-MCPOZ - mapZ),
			(int)0,
			(int)0,
			(int)mapX, (int)mapZ,
			*PL.ReferMapHandle(), FALSE, FALSE);

		DrawRectGraph(//�E��
			(int)(-MCPOX + mapX),
			(int)(-MCPOZ - mapZ),
			(int)0,
			(int)0,
			(int)mapX, (int)mapZ,
			*PL.ReferMapHandle(), FALSE, FALSE);

		DrawRectGraph(//��
			(int)(-MCPOX - mapX),
			(int)(-MCPOZ),
			(int)0,
			(int)0,
			(int)mapX, (int)mapZ,
			*PL.ReferMapHandle(), FALSE, FALSE);

		DrawRectGraph(//��
			(int)(-MCPOX),
			(int)(-MCPOZ),
			(int)0,
			(int)0,
			(int)mapX, (int)mapZ,
			*PL.ReferMapHandle(), FALSE, FALSE);

		DrawRectGraph(//�E
			(int)(-MCPOX + mapX),
			(int)(-MCPOZ),
			(int)0,
			(int)0,
			(int)mapX, (int)mapZ,
			*PL.ReferMapHandle(), FALSE, FALSE);

		DrawRectGraph(//����
			(int)(-MCPOX - mapX),
			(int)(-MCPOZ + mapZ),
			(int)0,
			(int)0,
			(int)mapX, (int)mapZ,
			*PL.ReferMapHandle(), FALSE, FALSE);

		DrawRectGraph(//��
			(int)(-MCPOX),
			(int)(-MCPOZ + mapZ),
			(int)0,
			(int)0,
			(int)mapX, (int)mapZ,
			*PL.ReferMapHandle(), FALSE, FALSE);

		DrawRectGraph(//�E��
			(int)(-MCPOX + mapX),
			(int)(-MCPOZ + mapZ),
			(int)0,
			(int)0,
			(int)mapX, (int)mapZ,
			*PL.ReferMapHandle(), FALSE, FALSE); 
	}
}

/*�D�̉��ɂ���G�t�F�N�g��`��*/
void IngameDataManagement::DrawEffectUnderShips() {
	/*���A���o*/
	if (!bubbleList.empty())
	for (auto bubble = bubbleList.begin();
		bubble != bubbleList.end();
		bubble++) {
		bubble->Draw((int)MainCamera.ReferRealCameraX(),
			(int)MainCamera.ReferRealCameraZ());
	}
}

/*�D�̏�ɂ���G�t�F�N�g��`��*/
void IngameDataManagement::DrawEffectBeyondShips() {
	if (!smokeList.empty())
	for (auto smoke = smokeList.begin();
		smoke != smokeList.end();
		smoke++) {
		smoke->Draw((int)MainCamera.ReferRealCameraX(),
			(int)MainCamera.ReferRealCameraZ());
	}
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
	//�e�X�g�E�W���pUI
	unsigned int Cr;
	Cr = GetColor(255, 255, 255);
	auto ship = alliesFleet.begin();
	char CharNum[255];

	SetFontSize(20);
	ChangeFont("HG�s����");

	DrawString(100, 600, "���x:", Cr);
	if (ship->ReferSpeedOnZ()*28.0f > 0.5f)
		_gcvt_s(CharNum, ship->ReferSpeedOnZ()*28.0f, 2);
	else if (ship->ReferSpeedOnZ()*28.0f > 10.0f)
		_gcvt_s(CharNum, ship->ReferSpeedOnZ()*28.0f, 3);
	else
		_gcvt_s(CharNum, 0.0f, 2);
	DrawString(180, 600, CharNum, Cr);
	DrawString(220, 600, "Kt", Cr);

	DrawString(100, 620, "�o��", Cr);
	_gcvt_s(CharNum, ship->ReferOutPutRate() * 100, 3);
	DrawString(180, 620, CharNum, Cr);
	DrawString(220, 620, "%", Cr);

	DrawString(100, 660, "�q�s����", Cr);
	if (ship->ReferChangingRadian() > 0)
		DrawString(200, 660, "�E��", Cr);
	else if (ship->ReferChangingRadian() < 0)
		DrawString(200, 660, "����", Cr);
	else
		DrawString(200, 660, "�O��", Cr);
}

/****************************************************/
/*                     �e�X�g�@                     */
/****************************************************/
void IngameDataManagement::TEST() {
	alliesFleet.push_back(ShipMain());
	auto ship = alliesFleet.begin();
	//�����̕����͏������֐��ƃt�@�C���ǂݍ��݂͂܂��o���Ă��Ȃ�
	//�������֐��͉��̂悤�ɂ�����
	ship->InifThisShip(PL.ReferBattleCrusierHandle(4000), 
		PL.ReferBattleCrusierShadowHandle(4000), 4000, ET, &SL);
	ship->NewCoordX(2200);
	ship->NewCoordZ(1500);
	ship->SetLength(PL.ReferShipSizeX());
	ship->SetWidth(PL.ReferShipSizeZ());
	ship->TEST();
	ship->SetWeaponTest(&PL);
}

void IngameDataManagement::TEST_DRAW() {
	unsigned int Cr;
	Cr = GetColor(255, 255, 255);
	auto ship = alliesFleet.begin();
	ship->TestDraw(MainCamera.ReferRealCameraX(),
		MainCamera.ReferRealCameraZ());
	char CharNum[255];

	SetFontSize(15);
	ChangeFont("HG��Я�M");

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
/*                   �R���g���[��                   */
/****************************************************/
/*�R�}���h���󂯎���āA�V���Ȃ��̂𐶐�����*/
void IngameDataManagement::Control() {
	int answer = CT.GetCommand();


	/*�D�𑀍�*/
	auto ship = alliesFleet.begin();
	ship->ControlThisShip(answer);


	if (answer == CommandSerial::SHOOT) {
		TestShoot();
	}

	/*�e�X�g�r���[*/
	if (answer == CommandSerial::TEST_VIEW_ON)
		TEST_SHOW_ON = !TEST_SHOW_ON;
}

/****************************************************/
/*                     �ړ��֘A                     */
/****************************************************/
void IngameDataManagement::MoveAll() {
	MoveShips();
	MoveEffects();
	MoveAmmo();
}

void IngameDataManagement::MoveShips() {
	for (auto ship = alliesFleet.begin();
		ship != alliesFleet.end();
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
/*                    �f�[�^�֘A                    */
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
/*                  �G�t�F�N�g�֘A                  */
/****************************************************/
void IngameDataManagement::GetNewEffect() {
	/*�i�s���̐��A����*/
	for (auto ship = alliesFleet.begin();
		ship != alliesFleet.end();
		ship++) {
		if (ship->ReferSpeedOnZ() > 0.1 && rand() % 3==0 
			&& rand()%100>ship->ReferSpeedOnZ()*10) {
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
		if (ship->ReferOutPutRate() != 0) {
			if ((rand() % 8 < ship->ReferSpeedOnZ() * 10)
				&& rand() % 4 == 0) {
				smokeList.push_back(ship->NewSmoke(0));
				smokeList.push_back(ship->NewSmoke(1));
			}
		}
	}
}

void IngameDataManagement::DeleteUselessEffect() {
	/*�o�u��*/
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
/*                     �ˌ��֘A                     */
/****************************************************/

void IngameDataManagement::TestShoot() {
	FiringData FD;
	//�Q�[�����ł́A�G���ˌ����鎞�ɑS��true�ɂ���
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
/*                     �����蔻��                   */
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