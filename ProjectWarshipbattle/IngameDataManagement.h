#pragma once
#include"HeaderForIngameDataManagement.h"
/*関数のプライベート化はこれからする*/
class IngameDataManagement
{
public:
	IngameDataManagement() :MainCamera(CameraType::MAIN) {
		TEST_SHOW_ON = false;
		GameOver = false;
	}
	~IngameDataManagement();

	void Update();

	//ゲームを初期化操作
	//ここの関数にファイル操作も含む
	void Inif();
	void registerTeamA(PictureLoader PL);
	void registerTeamB(PictureLoader PL);
	void Free();

	//データ操作
	void CrashDecision();
	void HitDecision();//ゲームコントローラーに当たる数を返す
	void SimpleHitDecision();

	void GetNewEffect();
	void DeleteUselessEffect();

	void DeleteUseless();

	//弾管理
	void CheckSelectedWeapon();
	void InputNewAmmo(ShipMain *SM, FiringData FD);
	void DeleteUselessAmmo();

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
	bool ReferEndGame() { return GameOver; }

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
	//他のコントローラー
	PictureLoader PL;
	FrameControl FC;
	Camera MainCamera;
	Controller CT;
	UserInterface UI;
	EffectTemplate ET;
	SoundLoader SL;
	ClickableUserInterface CUI;

	//描く関数
	void DrawSea();
	void DrawShips();
	void DrawShipsOnMiniMap();
	void DrawPlanes();
	void DrawAmmo();
	void DrawBomb();
	void DrawTorpedo();
	void DrawEffectUnderShips();
	void DrawEffectBeyondShips();
	
	//移動関数
	void MoveShips();
	void MoveEffects();
	void MoveAmmo();

	//射撃テスト
	void TestShoot();

	int shootCount;
	int hitCount; 

	//テスト関連
	bool TEST_SHOW_ON;
	void SIMPLE_USER_INTERFACE();
	bool GameOver;

	/*音声関数*/
	void CheckAndPlaySound();

	std::vector<ShipMain> alliesFleet;
	std::vector<ShipMain> enemyFleet;
	std::list<ShipMain> sinkingShip;

	std::list<Ammo> shellList;
	std::list<Bomb> bombList;
	std::list<Torpedo> torpedoList;
	std::list<Effect> bubbleList;
	std::list<Effect> smokeList;
};