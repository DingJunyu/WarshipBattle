#include "MainMenuController.h"

MainMenuController::~MainMenuController()
{
}

void MainMenuController::Inif() {
	PL.AllInif();
	SL.Inif();
//	BC.Inif(&PL);

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
	ClearDrawScreen();

	DrawExtendGraph(0, 0, Screen::SCREEN_X, Screen::SCREEN_Z,
		*backGroundHandle, FALSE);
	DrawExtendGraph(
		Screen::SCREEN_X / 2 - titleSizeX / 4,
		100,
		Screen::SCREEN_X / 2 + titleSizeX / 4,
		100 + titleSizeZ/2,
		*title,
		TRUE
	);

	int *useThisPressedToStart = 
		(countForTitle % 120 > 60 ? pressedToStart : pressedToStartDown);

	DrawExtendGraph(
		Screen::SCREEN_X/2 - PTSSizeX/4,
		500,
		Screen::SCREEN_X/2 + PTSSizeX/4,
		500 + PTSSizeZ/2,
		*useThisPressedToStart,
		TRUE
	);
	ScreenFlip();

	countForTitle++;
	countForTitle %= 120;
}

void MainMenuController::DrawMainMenu() {
	
}

int MainMenuController::CheckChoice(){
	return 0;
}

void MainMenuController::FREE() {
	PL.FREE_ALL();
	SL.FreeAll();
//	BC.FREE();
}