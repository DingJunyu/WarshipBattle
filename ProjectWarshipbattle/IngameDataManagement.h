#pragma once
//標準ヘッダー
#include<list>
#include<vector>
#include<stdlib.h>
//DXヘッダー
#include"DxLib.h"
//自作ヘッダー
#include"DefinedData.h"
#include"Camera.h"
#include"ShipMain.h"
#include"Ammo.h"
#include"Bomb.h"
#include"Torpedo.h"
#include"PictureLoader.h"
#include"ShipData.h"
#include"FrameControl.h"
#include"Controller.h"
#include"FunctionsForCal.h"
class IngameDataManagement
{
public:
	IngameDataManagement() :MainCamera(CameraType::MAIN) {
		TEST_SHOW_ON = true;
	}
	~IngameDataManagement();

	//他のコントローラー
	PictureLoader PL;
	FrameControl FC;
	Camera MainCamera;
	Controller CT;

	void Update();

	//ゲームを初期化操作
	//ここの関数にファイル操作も含む
	void registerTeamA(PictureLoader PL);
	void registerTeamB(PictureLoader PL);

	//データ操作
	void CrashDecision();
	void HitDecision();//ゲームコントローラーに当たる数を返す

	void DeleteUseless();

	//カメラ用座標問い合わせ
	double ReferPlayerX() { return alliesFleet[0].ReferCoordX(); }
	double ReferPlayerZ() { return alliesFleet[0].ReferCoordZ(); }

	//GameController問い合わせ
	int ReferRemainedAlliesNum();
	int ReferRemainedEnemiesNum();
	int ReferRemainedAlliesNumInHanger();
	int ReferRemainedAlliesNumInSky();
	int ReferRemainedEnemiesNumInHanger();
	int ReferRemainedEnemiesNumInSky();

	bool TeamDestroyed() { return false; }

	//統計データ
	int ShootCount();//実現はあとでいい

	//すべてのテストはここで行う
	void TEST();

	void Control();

	//画像描く
	void DrawAll();
	void TEST_DRAW();

	void MoveAll();
	
private:
	//描く関数
	void DrawSea();
	void DrawShips();
	void DrawPlanes();
	void DrawAmmo();
	void DrawBomb();
	void DrawTorpedo();
	
	//移動関数
	void MoveShips();

	int shootCount;
	int hitCount;

	int numOfMapOnX;
	int numOfMapOnZ;

	bool TEST_SHOW_ON;

	std::vector<ShipMain> alliesFleet;
	std::vector<ShipMain> enemyFleet;
	std::list<ShipMain> sinkingShip;

	std::list<Ammo> shellList;
	std::list<Bomb> bombList;
	std::list<Torpedo> torpedoList;
};

