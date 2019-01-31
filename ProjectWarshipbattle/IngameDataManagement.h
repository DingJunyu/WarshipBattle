#pragma once
//標準ヘッダー
#include<list>
#include<vector>
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
class IngameDataManagement
{
public:
	IngameDataManagement();
	~IngameDataManagement();

	void Update(Camera CM, PictureLoader PL);

	//ゲームを初期化操作
	//ここの関数にファイル操作も含む
	void registerTeamA(PictureLoader PL);
	void registerTeamB(PictureLoader PL);

	//データ操作
	void CrashDecision();
	void HitDecision();//ゲームコントローラーに当たる数を返す

	void DeleteUseless();

	//カメラ用座標問い合わせ
//	double ReferPlayerX() { return alliesFleet[0].ReferCoordX(); }
//	double ReferPlayerZ() { return alliesFleet[0].ReferCoordZ(); }

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


	//画像描く
	void DrawAll(double CX, double CZ, PictureLoader PL);
	
private:
	void DrawSea(double CX,double CZ, PictureLoader PL);
	void DrawShips(double CX, double CZ, PictureLoader PL);
	void DrawPlanes(double CX, double CZ, PictureLoader PL);
	void DrawAmmo(double CX, double CZ, PictureLoader PL);
	void DrawBomb(double CX, double CZ, PictureLoader PL);
	void DrawTorpedo(double CX, double CZ, PictureLoader PL);

	int shootCount;
	int hitCount;

	int numOfMapOnX;
	int numOfMapOnZ;

	std::vector<ShipMain> alliesFleet;
	std::vector<ShipMain> enemyFleet;
	std::list<ShipMain> sinkingShip;

	std::list<Ammo> shellList;
	std::list<Bomb> bombList;
	std::list<Torpedo> torpedoList;
};

