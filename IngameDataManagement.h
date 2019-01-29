#pragma once
//標準ヘッダー
#include<list>
#include<vector>
//DXヘッダー
#include"DxLib.h"
//自作ヘッダー
#include"Camera.h"
#include"ShipMain.h"
#include"Ammo.h"
#include"Bomb.h"
#include"Torpedo.h"
#include"PictureLoader.h"
#include"ShipData.h"
class IngameDataManagement
{
public:
	IngameDataManagement();
	~IngameDataManagement();

	void Update(Camera CM);

	//ゲームを初期化操作
	//ここの関数にファイル操作も含む
	void registerTeamA(PictureLoader PL);
	void registerTeamB(PictureLoader PL);

	//データ操作
	void CrashDecision();
	void HitDecision();//ゲームコントローラーに当たる数を返す

	void DeleteUseless();

	//カメラ用座標問い合わせ
	int ReferPlayerX() { return alliesFleet[0].ReferCoordX(); }
	int ReferPlayerZ() { return alliesFleet[0].ReferCoordZ(); }

	//GameController問い合わせ
	int ReferRemainedAlliesNum();
	int ReferRemainedEnemiesNum();
	int ReferRemainedAlliesNumInHanger();
	int ReferRemainedAlliesNumInSky();
	int ReferRemainedEnemiesNumInHanger();
	int ReferRemainedEnemiesNumInSky();

	bool TeamDestroyed();

	//統計データ
	int ShootCount();//実現はあとでいい


	//画像描く
	void DrawAll(int CX, int CZ);


	
private:
	void DrawSea(int CX,int CZ);
	void DrawShips(int CX, int CZ);
	void DrawPlanes(int CX, int CZ);
	void DrawAmmo(int CX, int CZ);
	void DrawBomb(int CX, int CZ);
	void DrawTorpedo(int CX, int CZ);

	int shootCount;
	int hitCount;

	std::vector<ShipMain> alliesFleet;
	std::vector<ShipMain> enemyFleet;
	std::list<ShipMain> sinkingShip;

	std::list<Ammo> shellList;
	std::list<Bomb> bombList;
	std::list<Torpedo> torpedoList;
};

