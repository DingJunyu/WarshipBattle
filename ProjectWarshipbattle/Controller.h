#pragma once
#include"DefinedData.h"
#include"SoundLoader.h"
#include"DxLib.h"
/*�����̃R���g���[���[�ł́A�L�[�{�[�h�̓��͂��󂯎���ĐM���ɕύX���܂��B
�}�E�X����Ȃǂ�ClickableUserInterface�Ɏ������܂�*/
class Controller
{
public:
	Controller();
	~Controller();

	void Inif(SoundLoader *SL);

	int GetCommand();

private:
	int Action;
	char KeyBuf[256];

	int shipHordType;
	int *shipHordHigh;
	int *shipHordLow;
};

