#pragma once
#include"PictureLoader.h"
#include"DxLib.h"
#include"SoundLoader.h"
#include"DefinedData.h"
#include"ButtonCollection.h"
#include"FrameControl.h"
class MainMenuController
{
public:
	MainMenuController() {
		countForTitle = 0;
		firstTimeGetIntoMainMenu = true;
		titleMultipleRateInTitle = 2;
		titleMultipleRateInMainMenu = 4;
	}
	~MainMenuController();

	void Inif();

	void DrawTitle();
	void DrawMainMenu();
	void DrawLoading();
	void SetButtonPosition();

	int CheckChoice();
	void FREE();

private:
	PictureLoader PL;
	SoundLoader SL;
	ButtonCollection BC;
	FrameControl FC;

	/*提示の点滅用カウント*/
	int countForTitle;

	/*0->x,1->z*/
	double buttonPosition[ButtonEvent::BUTTON_AMOUNT][2];
	int buttonSizeX;
	int buttonSizeZ;

	int *backGroundHandle;
	int *title;
	int titleSizeX;
	int titleSizeZ;

	int titleMultipleRateInTitle;
	int titleMultipleRateInMainMenu;

	int *pressedToStart;
	int PTSSizeX;
	int PTSSizeZ;
	int *pressedToStartDown;

	int titleMultiple;

	bool firstTimeGetIntoMainMenu;
};

