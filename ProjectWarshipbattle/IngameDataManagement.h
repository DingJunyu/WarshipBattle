#pragma once
//標準ヘッダー
#include<list>
#include<vector>
//DXヘッダー
#include"DxLib.h"
//自作ヘッダー
#include"ShipMain.h"
#include"Ammo.h"
#include"Bomb.h"
#include"Torpedo.h"
#include"PictureLoader.h"
class IngameDataManagement
{
public:
	IngameDataManagement();
	~IngameDataManagement();

	//ゲームを初期化操作
	//ここの関数にファイル操作も含む
	void registerTeamA(PictureLoader PL);
	void registerTeamB(PictureLoader PL);

	//データ操作
	void CrashDecision();
	void HitDecision();//ゲームコントローラーに当たる数を返す

	void DeleteUseless();

	//GameController問い合わせ
	int ReferRemainedAlliesNum();
	int ReferRemainedEnemiesNum();
	int ReferRemainedAlliesNumInHanger();
	int ReferRemainedAlliesNumInSky();
	int ReferRemainedEnemiesNumInHanger();
	int ReferRemainedEnemiesNumInSky();

	//統計データ
	int ShootCount();//実現はあとでいい


	//画像描く
	void DrawAll();

	void DrawShips();
	void DrawPlanes();
	void DrawAmmo();
	void DrawBomb();
	void DrawTorpedo();
	
	std::vector<ShipMain> alliesFleet;
	std::vector<ShipMain> enemyFleet;
	std::list<ShipMain> sinkingShip;

	std::list<Ammo> shellList;
	std::list<Bomb> bombList;
	std::list<Torpedo> torpedoList;

private:
	int shootCount;
	int hitCount;
};

