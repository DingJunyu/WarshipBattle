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
	
	//�₢���킹�֐�
	//�D
	int ReferShipSizeX() { return shipSizeX; }
	int ReferShipSizeZ() { return shipSizeZ; }

	int *ReferBattleCrusierHandle(int x) {
		return &battleCruiserHandle
		[x-ShipType::BATTLE_CRUISER*RESERVED_NUMBER_FOR_SHIPS]
		[SerialNumberOfShipHandle::SHIP_HANDLE];
	}

	//�}�b�v
	int ReferMapX() { return mapX; }
	int ReferMapZ() { return mapZ; }

	int *ReferMapHandle() { return &mapHandle; }

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
	int shipSizeX;
	int shipSizeZ;

	/*�}�b�v�I�u�W�F�N�g�f�[�^*/
	int **mapObjectHandle;

	/*�}�b�v�f�[�^*/
	/*�n���h��*/
	int mapHandle;
	/*�T�C�Y*/
	int mapX;
	int mapZ;

	/*�e�f�[�^*/
	/*�n���h��*/
	int **ammoHandle;
	/*�T�C�Y*/
	int *ammoX;
	int *ammoZ;

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

