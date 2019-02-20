#include "PictureLoader.h"

PictureLoader::PictureLoader()
{
}

PictureLoader::~PictureLoader()
{
}

void PictureLoader::MemorySecure() {
	
	battleCruiserHandle
		= new int *[COUNT_OF_EVERYTYPE::BATTLE_CRUSIER_TYPE_COUNT];
	for (int i = 0;
		i < COUNT_OF_EVERYTYPE::BATTLE_CRUSIER_TYPE_COUNT;
		i++) {
		battleCruiserHandle[i] 
			= new int [SerialNumberOfShipHandle::ARRAY_SIZE];
	}

	//�{�^��
	buttonHandle = new int[buttonAmount];
	buttonPressedHandle = new int[buttonAmount];
}

void PictureLoader::FreeMemory() {
	for (int i = 0;
		i < COUNT_OF_EVERYTYPE::BATTLE_CRUSIER_TYPE_COUNT;
		i++) {
		delete[] battleCruiserHandle[i];
	}
	delete[] battleCruiserHandle;

	//�{�^��
	delete[] buttonHandle;
	delete[] buttonPressedHandle;
}

void PictureLoader::LoadPicture() {
	/*���[�h�퓬���m��*/
	battleCruiserHandle[0][SerialNumberOfShipHandle::SHIP_HANDLE] =
	LoadGraph(
	"GraphicData/Ship_TopView/BattleCrusier/BattleCrusier_TopView_00_Lvtzow.png");
	GetGraphSize(battleCruiserHandle[0][SerialNumberOfShipHandle::SHIP_HANDLE],
		&shipSizeX, &shipSizeZ);
	battleCruiserHandle[0][SerialNumberOfShipHandle::SHIP_SHADOW_HANDLE] =
	LoadGraph(
	"GraphicData/Ship_Shadow/BattleCrusier/BattleCrusier_Shadow_01_Lvtzow.png");

	/*�C*/
	mapHandle =
	LoadGraph("GraphicData/Sea/Sea.jpg");
	GetGraphSize(mapHandle, &mapX, &mapZ);

	/*UI*/
	matHandle = LoadGraph(
	"GraphicData/User_Interface/UI_Mat.jpg");
	GetGraphSize(matHandle, &matHandleX, &matHandleZ);
	shipCardMatHandle = LoadGraph(
	"GraphicData/User_Interface/Ship_Card_Mat.jpg");
	GetGraphSize(shipCardMatHandle, &shipCardMatHandleX, &shipCardMatHandleZ);

	/*�~�j�}�b�v*/
	miniMapMatHandle = LoadGraph(
	"GraphicData/User_Interface/MiniMap_Mat.jpg");
	miniMapPaperHandle = LoadGraph(
	"GraphicData/User_Interface/MiniMap_Paper.jpg");

	/*�G�t�F�N�g*/
	bubbleHandle = LoadGraph(
	"GraphicData/Effect/Bubble.png");
	smokeHandle = LoadGraph(
	"GraphicData/Effect/Smoke.png");

	//�{�^��

}

void PictureLoader::FreePicture() {
	for (int i = 0;
		i < COUNT_OF_EVERYTYPE::BATTLE_CRUSIER_TYPE_COUNT;
		i++) {
		DeleteGraph(
			battleCruiserHandle[i][SerialNumberOfShipHandle::SHIP_HANDLE]);
		DeleteGraph(
			battleCruiserHandle[i][SerialNumberOfShipHandle::SHIP_SHADOW_HANDLE]);
	}
	/*�}�b�v*/
	DeleteGraph(mapHandle);
	/*UI*/
	DeleteGraph(matHandle);
	DeleteGraph(shipCardMatHandle);
	DeleteGraph(miniMapMatHandle);
	DeleteGraph(miniMapPaperHandle);
	/*�G�t�F�N�g*/
	DeleteGraph(bubbleHandle);
	DeleteGraph(smokeHandle);
}