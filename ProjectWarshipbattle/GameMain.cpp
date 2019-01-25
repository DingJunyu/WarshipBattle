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

	PL.AllInif();
	IDM.registerTeamA(PL);
	IDM.registerTeamB(PL);
	
	while (!TDMC.GameOver()) {
		IDM.CrashDecision();
		IDM.HitDecision();
		IDM.DeleteUseless();
		IDM.DrawAll();
		FC.Wait();
	}
	TDMC.DrawBoard();
	PL.FREE_ALL();
}