#pragma once
#include"PictureLoader.h"
#include"DxLib.h"
#include"SoundLoader.h"
#include"DefinedData.h"
#include"ButtonCollection.h"
#include"FrameControl.h"
/*���Ƃ��Ƃ͂��̃N���X�Ń��C�����j���[�̑�����������邾�����A
���ۂɂق��̉�ʂ̃R���g���[���[�̓��e���d�����܂����A
���ꂩ�烆�[�U�[�̑���͂��ׂĂق��̃N���X�Ɉڍs���܂��B*/
class MainMenuController
{
public:
	MainMenuController() {
		countForTitle = 0;
		firstTimeGetIntoMainMenu = true;
		titleMultipleRateInTitle = 2;
		titleMultipleRateInMainMenu = 4;
		buttonMultiple = 0.5;
	}
	~MainMenuController();

	void Inif();

	void DrawTitle();
	void DrawMainMenu();
	void DrawLoading();

	int CheckChoice();
	void FREE();

private:
	void SetButtonPosition();

	/*���ۂɉ摜�ۑ��N���X�͂����ɐ錾���ׂ��ł͂Ȃ��������A
	�f�U�C���̃~�X�ł����ɐ錾���܂����A���̃N���X�̖������ԈႢ�܂����A
	MainMenuCOntroller�ł͂Ȃ��AClickableUserInterface�ɒ����ׂ���*/
	/*���߂�ClickableUserInterface�̃N���X�����܂��B*/
	PictureLoader PL;
	SoundLoader SL;
	ButtonCollection BC;
	FrameControl FC;

	/*�񎦂̓_�ŗp�J�E���g*/
	int countForTitle;

	/*0->x,1->z*/
	double buttonPosition[ButtonEvent::BUTTON_AMOUNT][2];
	int buttonSizeX;
	int buttonSizeZ;
	double buttonMultiple;

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

