#pragma once
#include"DxLib.h"
#include"PictureLoader.h"
#include"DefinedData.h"
#include<cmath>
class UserInterface
{
public:
	UserInterface() :
		matStartX(0), matStartZ(Screen::SCREEN_Z / 4.5),
		leftSCMStartX(0), leftSCMStartZ(0),
		rightSCMStartX(0), rightSCMStartZ(0), mapMatSize(Screen::SCREEN_X / 8),
		mapPaperSize(mapMatSize - 10) {}
	~UserInterface();

	void InifUI(PictureLoader *PL);

	void DrawUI();

	void DrawShipOnTheMap(double X, double Z, bool enemy);

	void SetMat(int *M) { mat = M; }
	

private:
	int *mat;
	int *shipCardMat;

	int *miniMapMat;
	int *miniMapPaper;

	double matStartX;
	double matStartZ;

	double leftSCMStartX;
	double leftSCMStartZ;
	double rightSCMStartX;
	double rightSCMStartZ;

	double mapMatSize;
	double mapPaperSize;
	
};

