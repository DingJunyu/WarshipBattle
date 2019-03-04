#pragma once
#include"DxLib.h"
#include"DefinedData.h"

class PictureLoader
{
public:
	PictureLoader() {}
	~PictureLoader();

	/*�������֐�*/
	void AllInif() { MemorySecure(); LoadPicture(); }
	void InifForMainMenu();

	/*���������*/
	/*�K���Ō�Ɏg���I�I�I*/
	void FREE_ALL() { FreePicture(); FreeMemory(); }
	void FREE_FOR_MAINMENU();
	
	//�₢���킹�֐�
	//�D
	int ReferShipSizeX() { return shipSizeX; }
	int ReferShipSizeZ() { return shipSizeZ; }

	int *ReferBattleCrusierHandle(int x) {
		return &battleCruiserHandle
		[x - ShipType::BATTLE_CRUISER*RESERVED_NUMBER_FOR_SHIPS]
		[SerialNumberOfShipHandle::SHIP_HANDLE];
	}

	int *ReferBattleCrusierShadowHandle(int x) {
		return &battleCruiserHandle
			[x - ShipType::BATTLE_CRUISER*RESERVED_NUMBER_FOR_SHIPS]
		[SerialNumberOfShipHandle::SHIP_SHADOW_HANDLE];
	}

	//�}�b�v
	int ReferMapX() { return mapX; }
	int ReferMapZ() { return mapZ; }

	int *ReferMapHandle() { return &mapHandle; }

	//UI
	int *ReferMatHandle() { return &matHandle; }
	int ReferMatHandleX() { return matHandleX; }
	int ReferMatHandleZ() { return matHandleZ; }

	int *ReferShipCardMatHandle() { return &shipCardMatHandle; }
	int ReferShipCardMatHandleX() { return shipCardMatHandleX; }
	int ReferShipCardMatHandleZ() { return shipCardMatHandleZ; }

	int *ReferMiniMapMatHandle() { return &miniMapMatHandle; }
	int *ReferMiniMapPaperHandle() { return &miniMapPaperHandle; }

	//�G�t�F�N�g
	int *ReferBubbleHandle() { return &bubbleHandle; }
	int *ReferSmokeHandle() { return &smokeHandle; }

	//�{�^��
	int *ReferButtonHandle(int num) { return &buttonHandle[num]; }
	int *ReferButtonPressedHandle(int num) {
		return &buttonPressedHandle[num];}

	//�^�C�g���֌W
	int *ReferTitle() { return &title; }
	int *ReferPressedToStart() { return &pressedToStart; }
	int *ReferPressedToStartDown() { return &pressedToStartDown; }
	int *ReferBackGround() { return &backGround; }

	//�e
	int *ReferAmmoHandle(int x) { return &ammoHandle[x]; }

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
	int *ammoHandle;
	/*�T�C�Y*/
	int *ammoX;
	int *ammoZ;

	/*UI�f�[�^*/
	/*UI�x�[�X*/
	int matHandle;
	int matHandleX;
	int matHandleZ;
	int shipCardMatHandle;
	int shipCardMatHandleX;
	int shipCardMatHandleZ;
	int miniMapMatHandle;
	int miniMapPaperHandle;

	/*�̓}�[�N*/
	int **markForAllies;
	int **markForEnemies;

	/*�G�t�F�N�g*/
	int bubbleHandle;
	int smokeHandle;

	//�{�^��
	int *buttonHandle;
	int *buttonPressedHandle;

	//�^�C�g���֌W
	int title;
	int pressedToStart;
	int pressedToStartDown;
	int backGround;
};