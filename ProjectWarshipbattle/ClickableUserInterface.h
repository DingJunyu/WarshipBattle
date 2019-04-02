#pragma once
#include"DefinedData.h"
#include"ButtonCollection.h"
#include"PictureLoader.h"
#include"DxLib.h"
#include"SoundLoader.h"
#include<cmath>
/*����̃Q�[���ł́A���ׂĂ̑�����}�E�X�łł���悤�ɂ������ł��B
���C�����j���[�ɂ��A�Q�[����ʂɂ��g����N���X�ł��B
�ڕW�Ƃ��Ă͓����\���𗘗p���āA
�C���^�[�t�F�[�X��ύX����ΈႤ���g�𗘗p�ł���悤�ɂ������ł�*/
/*�������[�_�[�A�摜���[�_�[�͂��ׂĊO��������܂��̂ŁA�Đ錾���邱�Ƃ��T���܂�*/
/*�߂�l�Ȃǂ͂��ׂ�DefinedData.h�ɒ�`���܂��B*/
/*�Ȃ��A���ڐG��Ȃ�������UserInterface�N���X�Ɏ������܂��B
���̃N���X�ł́A�N���b�N�ł���p�[�c�̕`��Ɩ��߂�Ԃ��̓�̋@�\���������܂��B*/

class ClickableUserInterface
{
public:
	ClickableUserInterface() {
		menuOpened = false;
		lastClickTime = GetTickCount();
	}
	~ClickableUserInterface();

	void IngameInif(PictureLoader *PL, SoundLoader *SL);
	
	int CheckChoice();
	void Draw();
	void SetNormalStatus();
	void LetMeSeeMenu();
	void CloseMenu();
	bool CheckMenuOpened() { return menuOpened; }

	void SetClickTime() { lastClickTime = GetTickCount(); }

	bool ReferClickable() {
		if (lastClickTime + inputDelay <= GetTickCount())
			return true;
		return false;
	}


	void Free();

private:
	/*���̕ύX���ł���悤�ɂ��܂���*/
	void MemorySecure(int);
	void MemoryFree(int);
	void SetThisOne(int num, double x, double z, double mt);

	/*�񎦂̓_�ŗp�J�E���g*/
	int countForTitle;

	bool menuOpened;
	unsigned int lastClickTime;
	const int inputDelay = 50;

	ButtonCollection BC;

	/*0:�����W
	  1:�����W
	  2:���T�C�Y
	  3:���T�C�Y
	  4:�g�嗦
	  5:�\������:0,�\�����Ȃ�:1*/
	double **buttonPosition;
};