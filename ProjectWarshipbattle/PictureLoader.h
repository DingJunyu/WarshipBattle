#pragma once
#include"DxLib.h"
#include"DefinedData.h"

class PictureLoader
{
public:
	PictureLoader();
	~PictureLoader();

	/*初期化関数*/
	void AllInif() { MemorySecure(); LoadPicture(); }

	/*メモリ回収*/
	/*必ず最後に使う！！！*/
	void FREE_ALL() { FreePicture(); FreeMemory(); }

private:
	/*初期化関数*/
	void MemorySecure();
	void LoadPicture();

	/*メモリ回収*/
	void FreeMemory();
	void FreePicture();

	/*船画像データ*/
	/*参考：DefinedData.h-SerialNumberOfShipHandle*/
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

	/*マップオブジェクトデータ*/
	int **mapObjectHandle;

	/*マップデータ*/
	/*ハンドル*/
	int *mapHandle;
	/*サイズ*/
	int *mapX;
	int *mapY;

	/*弾データ*/
	/*ハンドル*/
	int **ammoHandle;
	/*サイズ*/
	int *ammoX;
	int *ammoY;

	/*UIデータ*/
	/*UIベース*/
	int lowerBoardHandle;
	int leftBoardHandle;
	int rightBoardHandle;
	int miniMapBoardHandle;

	/*艦マーク*/
	int **markForAllies;
	int **markForEnemies;
};

