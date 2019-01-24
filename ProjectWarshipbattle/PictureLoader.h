#pragma once
#include"DxLib.h"

class PictureLoader
{
public:
	PictureLoader();
	~PictureLoader();

	/*初期化関数*/
	void AllInif();

	/*メモリ回収*/
	void FreeMemory();
	void FreePicture();
	void FREE_ALL() { FreeMemory(); FreePicture(); }

private:
	/*船画像データ*/
	/*a[x][0]は船の画像データ、[1][2]はサイズ、[4]は側面図、
	[5]は影、[6]からは沈む動画*/
	int **destroyerHandle;
	int **lightCruiserHandle;
	int **heaveyCruiserHandle;
	int **battleCruiserHandle;
	int **battleShipHandle;
	int **aircraftCarrierHandle;
	int **lightAircraftCarrierHandle;
	int **CVEHandle;

	/*マップオブジェクトデータ*/
	int *mapObjectHandle;
	int *mapObjectOnMiniMapHandle;
	int *mapObjectShadowHandle;
	int *MOX;
	int *MOY;

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

