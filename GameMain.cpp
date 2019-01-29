#include"DxLib.h"
#include"HeaderForMain.h"

// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(TRUE);
	SetGraphMode(1028, 768, 32);
	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}
	SetAlwaysRunFlag(TRUE);

	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}

void GameMain();
void SingleGame_Mission_Progress();
void SingleGame_DeathMatch_Progress();
void MainMenu();

void SingleGame_DeathMatch_Progress() {
	
	//ゲーム管理の部品を宣言
	PictureLoader PL;
	IngameDataManagement IDM;
	FrameControl FC;
	TeamDeathMatchControl TDMC;
	Camera MainCamera(CameraType::MAIN);

	/*初期化*/
	PL.AllInif();
	IDM.registerTeamA(PL);
	IDM.registerTeamB(PL);
	
	/*ゲームメインプログレス*/
	while (!TDMC.GameOver(IDM.TeamDestroyed())) {
		MainCamera.GetXZ(IDM.ReferPlayerX(), IDM.ReferPlayerZ());
		IDM.Update(MainCamera);
		FC.Wait();
	}
	/*結果発表*/
	TDMC.DrawBoard(IDM);
	/*メモリ解放*/
	PL.FREE_ALL();
}