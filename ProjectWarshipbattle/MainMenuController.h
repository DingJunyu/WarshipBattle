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
	}
	~MainMenuController();

	void Inif();
	void DrawTitle();
	void DrawMainMenu();
	int CheckChoice();
	void FREE();

private:
	PictureLoader PL;
	SoundLoader SL;
	ButtonCollection BC;
	FrameControl FC;

	int countForTitle;

	int *backGroundHandle;
	int *title;
	int titleSizeX;
	int titleSizeZ;
	int *pressedToStart;
	int PTSSizeX;
	int PTSSizeZ;
	int *pressedToStartDown;

	int titleMultiple;
};

