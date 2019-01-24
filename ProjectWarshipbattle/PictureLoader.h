#pragma once
#include"DxLib.h"

class PictureLoader
{
public:
	PictureLoader();
	~PictureLoader();

	/*�������֐�*/
	void AllInif();

	/*���������*/
	void FreeMemory();
	void FreePicture();
	void FREE_ALL() { FreeMemory(); FreePicture(); }

private:
	/*�D�摜�f�[�^*/
	/*a[x][0]�͑D�̉摜�f�[�^�A[1][2]�̓T�C�Y�A[4]�͑��ʐ}�A
	[5]�͉e�A[6]����͒��ޓ���*/
	int **destroyerHandle;
	int **lightCruiserHandle;
	int **heaveyCruiserHandle;
	int **battleCruiserHandle;
	int **battleShipHandle;
	int **aircraftCarrierHandle;
	int **lightAircraftCarrierHandle;
	int **CVEHandle;

	/*�}�b�v�I�u�W�F�N�g�f�[�^*/
	int *mapObjectHandle;
	int *mapObjectOnMiniMapHandle;
	int *mapObjectShadowHandle;
	int *MOX;
	int *MOY;

	/*�}�b�v�f�[�^*/
	/*�n���h��*/
	int *mapHandle;
	/*�T�C�Y*/
	int *mapX;
	int *mapY;

	/*�e�f�[�^*/
	/*�n���h��*/
	int **ammoHandle;
	/*�T�C�Y*/
	int *ammoX;
	int *ammoY;

	/*UI�f�[�^*/
	/*UI�x�[�X*/
	int lowerBoardHandle;
	int leftBoardHandle;
	int rightBoardHandle;
	int miniMapBoardHandle;

	/*�̓}�[�N*/
	int **markForAllies;
	int **markForEnemies;
};

