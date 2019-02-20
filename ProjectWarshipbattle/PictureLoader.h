#pragma once
#include"DxLib.h"
#include"DefinedData.h"

class PictureLoader
{
public:
	PictureLoader() {
		buttonAmount = 30;
	}
	~PictureLoader();

	/*初期化関数*/
	void AllInif() { MemorySecure(); LoadPicture(); }

	/*メモリ回収*/
	/*必ず最後に使う！！！*/
	void FREE_ALL() { FreePicture(); FreeMemory(); }
	
	//問い合わせ関数
	//船
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

	//マップ
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

	//エフェクト
	int *ReferBubbleHandle() { return &bubbleHandle; }
	int *ReferSmokeHandle() { return &smokeHandle; }

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
	int shipSizeX;
	int shipSizeZ;

	/*マップオブジェクトデータ*/
	int **mapObjectHandle;

	/*マップデータ*/
	/*ハンドル*/
	int mapHandle;
	/*サイズ*/
	int mapX;
	int mapZ;

	/*弾データ*/
	/*ハンドル*/
	int **ammoHandle;
	/*サイズ*/
	int *ammoX;
	int *ammoZ;

	/*UIデータ*/
	/*UIベース*/
	int matHandle;
	int matHandleX;
	int matHandleZ;
	int shipCardMatHandle;
	int shipCardMatHandleX;
	int shipCardMatHandleZ;
	int miniMapMatHandle;
	int miniMapPaperHandle;

	/*艦マーク*/
	int **markForAllies;
	int **markForEnemies;

	/*エフェクト*/
	int bubbleHandle;
	int smokeHandle;

	//ボタン
	int *buttonHandle;
	int *buttonPressedHandle;
	int buttonAmount;
};