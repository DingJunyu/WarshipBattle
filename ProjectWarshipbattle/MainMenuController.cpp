#include "MainMenuController.h"

MainMenuController::~MainMenuController()
{
}

void MainMenuController::Inif() {
	PL.AllInif();
	SL.Inif();
	BC.Inif(&PL);

	backGroundHandle = PL.ReferBackGround();
	title = PL.ReferTitle();
	pressedToStart = PL.ReferPressedToStart();
	pressedToStartDown = PL.ReferPressedToStartDown();
	//使うやつのサイズを取る
	GetGraphSize(*title, &titleSizeX, &titleSizeZ);
	GetGraphSize(*pressedToStart, &PTSSizeX, &PTSSizeZ);
}

void MainMenuController::DrawTitle() {
	SetDrawScreen(DX_SCREEN_BACK);//裏画面に描画する
	
	while (1) {
		ClearDrawScreen();

		DrawExtendGraph(0, 0, Screen::SCREEN_X, Screen::SCREEN_Z,
			*backGroundHandle, FALSE);
		DrawExtendGraph(
			Screen::SCREEN_X / 2 - titleSizeX / 4,
			100,
			Screen::SCREEN_X / 2 + titleSizeX / 4,
			100 + titleSizeZ / 2,
			*title,
			TRUE
		);

		//３０フレームごとに点滅する
		int *useThisPressedToStart =
			(countForTitle % 60 > 30 ? pressedToStart : pressedToStartDown);

		DrawExtendGraph(
			Screen::SCREEN_X / 2 - PTSSizeX / 4,
			500,
			Screen::SCREEN_X / 2 + PTSSizeX / 4,
			500 + PTSSizeZ / 2,
			*useThisPressedToStart,
			TRUE
		);
		ScreenFlip();

		countForTitle++;
		countForTitle %= 60;

		if ((CheckHitKeyAll() != 0 && GetInputChar(TRUE))
			|| GetMouseInput() == MOUSE_INPUT_LEFT)
			break;
	}
}

void MainMenuController::DrawMainMenu() {
	if (firstTimeGetIntoMainMenu) {
		SetButtonPosition();
		FC.Reset();
		firstTimeGetIntoMainMenu = false;
	}

	SetDrawScreen(DX_SCREEN_BACK);//裏画面に描画する
	ClearDrawScreen();

	DrawExtendGraph(0, 0, Screen::SCREEN_X, Screen::SCREEN_Z,
		*backGroundHandle, FALSE);

	for (int i = ButtonEvent::NEW_GAME; i <= ButtonEvent::GAME_OVER; i++) {
		BC.buttonContainer[i].DrawThisButton();
	}

	//ここの位置は適度に決めた
	DrawExtendGraph(850,50,850+titleSizeX/4,50+titleSizeZ/4,
		*title,TRUE);

	ScreenFlip();
}

void MainMenuController::DrawLoading() {
	SetDrawScreen(DX_SCREEN_BACK);
	ClearDrawScreen();

	DrawExtendGraph(0, 0, Screen::SCREEN_X, Screen::SCREEN_Z,
		*backGroundHandle, FALSE);

	unsigned int Cr;
	Cr = GetColor(255, 255, 255);
	SetFontSize(30);

	DrawString(1100, 640, "LOADING...", Cr);

	ScreenFlip();
}

void MainMenuController::SetButtonPosition() {
	buttonSizeX = 
		BC.buttonContainer[ButtonEvent::NEW_GAME].ReferGraphSizeX();
	buttonSizeZ =
		BC.buttonContainer[ButtonEvent::NEW_GAME].ReferGraphSizeZ();

	for (int i = ButtonEvent::NEW_GAME; i <= ButtonEvent::GAME_OVER; i++) {
		buttonPosition[i][0] = BUTTON_POSITION::START_POSITION_ON_X;
	}

	buttonPosition[ButtonEvent::NEW_GAME][1] =
		BUTTON_POSITION::NEW_GAME;
	buttonPosition[ButtonEvent::CONTINUE_GAME][1] =
		BUTTON_POSITION::CONTINUE_GAME;
	buttonPosition[ButtonEvent::LOAD_GAME][1] =
		BUTTON_POSITION::LOAD_GAME;
	buttonPosition[ButtonEvent::OPTION][1] =
		BUTTON_POSITION::OPTION;
	buttonPosition[ButtonEvent::GAME_OVER][1] =
		BUTTON_POSITION::GAME_OVER;

	for (int i = ButtonEvent::NEW_GAME; i <= ButtonEvent::GAME_OVER; i++) {
		BC.buttonContainer[i].SetXZ(buttonPosition[i][0],
			buttonPosition[i][1], buttonMultiple);
	}
}

int MainMenuController::CheckChoice(){
	int choice = -1;
	bool pressed = false;

	int mouseX, mouseZ;

	GetMousePoint(&mouseX, &mouseZ);
	if (GetMouseInput() == MOUSE_INPUT_LEFT) {
		pressed = true;
	}

	for (int i = ButtonEvent::NEW_GAME; i <= ButtonEvent::GAME_OVER; i++) {
		if (mouseX > buttonPosition[i][0] * Screen::SCREEN_X &&
			mouseX < buttonPosition[i][0] *
			Screen::SCREEN_X + buttonSizeX * buttonMultiple &&
			mouseZ > buttonPosition[i][1] * Screen::SCREEN_Z &&
			mouseZ < buttonPosition[i][1] *
			Screen::SCREEN_Z + buttonSizeZ * buttonMultiple) {

			BC.buttonContainer[i].ChangePressed();

			if (pressed)
				choice = i;
		}
	}

	if(choice != -1)
		firstTimeGetIntoMainMenu = true;
	return choice;
}

void MainMenuController::FREE() {
	BC.FREE();
	PL.FREE_ALL();
	SL.FreeAll();
}