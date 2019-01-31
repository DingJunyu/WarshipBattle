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
}

void PictureLoader::FreeMemory() {
	for (int i = 0;
		i < COUNT_OF_EVERYTYPE::BATTLE_CRUSIER_TYPE_COUNT;
		i++) {
		delete[] battleCruiserHandle[i];
	}
	delete[] battleCruiserHandle;
}

void PictureLoader::LoadPicture() {
	/*���[�h�퓬���m��*/
	battleCruiserHandle[0][SerialNumberOfShipHandle::SHIP_HANDLE] =
	LoadGraph
	("GraphicData/Ship_TopView/BattleCrusier/BattleCrusier_TopView_00_Lvtzow.png");

	/*�C*/
	mapHandle =
	LoadGraph("GraphicData/Sea/Sea.jpg");

	/*�摜�T�C�Y���擾*/
	GetGraphSize(battleCruiserHandle[0][SerialNumberOfShipHandle::SHIP_HANDLE],
		&shipSizeX, &shipSizeZ);
	GetGraphSize(mapHandle, &mapX, &mapZ);
}

void PictureLoader::FreePicture() {
	for (int i = 0;
		i < COUNT_OF_EVERYTYPE::BATTLE_CRUSIER_TYPE_COUNT;
		i++) {
		DeleteGraph(
			battleCruiserHandle[i][SerialNumberOfShipHandle::SHIP_HANDLE]);
	}
	DeleteGraph(mapHandle);
}