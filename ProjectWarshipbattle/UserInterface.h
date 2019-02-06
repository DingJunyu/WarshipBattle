#pragma once
#include"DxLib.h"
#include"PictureLoader.h"
#include"DefinedData.h"
class UserInterface
{
public:
	UserInterface(): 
		matStartX(0),matStartZ(Screen::SCREEN_Z/5),
		leftSCMStartX(0),leftSCMStartZ(0),
		rightSCMStartX(0),rightSCMStartZ(0){}
	~UserInterface();

	void InifUI(PictureLoader *PL);

	void DrawUI();

	void SetMat(int *M) { mat = M; }
	

private:
	int *mat;
	int *shipCardMat;

	double matStartX;
	double matStartZ;

	double leftSCMStartX;
	double leftSCMStartZ;
	double rightSCMStartX;
	double rightSCMStartZ;
};

