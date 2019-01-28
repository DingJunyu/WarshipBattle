#pragma once
#include"DxLib.h"
#include"DefinedData.h"

class PictureLoader
{
public:
	PictureLoader();
	~PictureLoader();

	/*�������֐�*/
	void AllInif() { MemorySecure(); LoadPicture(); }

	/*���������*/
	/*�K���Ō�Ɏg���I�I�I*/
	void FREE_ALL() { FreePicture(); FreeMemory(); }

private:
	/*�������֐�*/
	void MemorySecure();
	void LoadPicture();

	/*���������*/
	void FreeMemory();
	void FreePicture();

	/*�D�摜�f�[�^*/
	/*�Q�l�FDefinedData.h-SerialNumberOfShipHandle*/
	int **destroyerHandle;
	int **lightCruiserHandle;
	int **heaveyCruiserHandle;
	int **battleCruiserHandle;
	int **battleShipHandle;
	int **aircraftCarrierHandle;
	int **lightAircraftCarrierHandle;
	int **CVEHandle;
	int ShipSizeX;
	int ShipSizeZ;

	/*�}�b�v�I�u�W�F�N�g�f�[�^*/
	int **mapObjectHandle;

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

