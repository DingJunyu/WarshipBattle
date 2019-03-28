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
	//Žg‚¤‚â‚Â‚ÌƒTƒCƒY‚ðŽæ‚é
	GetGraphSize(*title, &titleSizeX, &titleSizeZ);
	GetGraphSize(*pressedToStart, &PTSSizeX, &PTSSizeZ);

	SetButtonPosition();
}

void MainMenuController::DrawTitle() {
	SetDrawScreen(DX_SCREEN_BACK);//— ‰æ–Ê‚É•`‰æ‚·‚é
	
	while (1) {
		ClearDrawScreen();

		DrawExtendGraph(0, 0, Screen::SCREEN_X, Screen::SCREEN_Z,
			*backGroundHandle, FALSE);
		DrawExtendGraph(
			Screen::SCREEN_X / 2 - titleSizeX / 4,
			(int)(0.1*Screen::SCREEN_Z),
			Screen::SCREEN_X / 2 + titleSizeX / 4,
			0.1*Screen::SCREEN_Z + titleSizeZ / 2,
			*title,
			TRUE
		);

		//‚R‚OƒtƒŒ[ƒ€‚²‚Æ‚É“_–Å‚·‚é
		int *useThisPressedToStart =
			(countForTitle % 60 > 30 ? pressedToStart : pressedToStartDown);

		DrawExtendGraph(
			Screen::SCREEN_X / 2 - PTSSizeX / 4,
			(int)(0.6*Screen::SCREEN_Z),
			Screen::SCREEN_X / 2 + PTSSizeX / 4,
			(int)(0.6*Screen::SCREEN_Z) + PTSSizeZ / 2,
			*useThisPressedToStart,
			TRUE
		);
		ScreenFlip();

		countForTitle++;
		countForTitle %= 60;

		if ((CheckHitKeyAll() != 0 && GetInputChar(TRUE))
			|| GetMouseInput() == MOUSE_INPUT_LEFT)
			break;

		if (ProcessMessage() == -1)
			break;
	}
}

void MainMenuController::DrawMainMenu() {
	if (firstTimeGetIntoMainMenu) {
		FC.Reset();
		firstTimeGetIntoMainMenu = false;
	}

	SetDrawScreen(DX_SCREEN_BACK);//— ‰æ–Ê‚É•`‰æ‚·‚é
	ClearDrawScreen();

	DrawExtendGraph(0, 0, Screen::SCREEN_X, Screen::SCREEN_Z,
		*backGroundHandle, FALSE);

	for (int i = ButtonEvent::NEW_GAME; i <= ButtonEvent::GAME_OVER; i++) {
		BC.buttonContainer[i].DrawThisButton();
	}

	DrawExtendGraph(.67*Screen::SCREEN_X, .1*Screen::SCREEN_Z, 
		.67*Screen::SCREEN_X + titleSizeX / 4, .1*Screen::SCREEN_Z + titleSizeZ / 4,
		*title, TRUE);

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

	DrawString(0.85*Screen::SCREEN_X, 0.85*Screen::SCREEN_Z, "LOADING...", Cr);

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