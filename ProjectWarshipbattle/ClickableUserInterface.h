#pragma once
#include"DefinedData.h"
#include"ButtonCollection.h"
#include"PictureLoader.h"
#include"DxLib.h"
#include"SoundLoader.h"
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
	ClickableUserInterface();
	~ClickableUserInterface();

	void IngameInif(PictureLoader *PL, SoundLoader *SL);
	
	int CheckChoice();
	void Draw();
	void SetNormalStatus();

	void Free();

private:
	/*���̕ύX���ł���悤�ɂ��܂���*/
	void MemorySecure(int);
	void MemoryFree(int);
	void SetThisOne(int num, double x, double z, double mt);

	/*�񎦂̓_�ŗp�J�E���g*/
	int countForTitle;

	ButtonCollection BC;

	/*0:�����W
	  1:�����W
	  2:���T�C�Y
	  3:���T�C�Y
	  4:�g�嗦
	  5:�\������:0,�\�����Ȃ�:1*/
	double **buttonPosition;
};