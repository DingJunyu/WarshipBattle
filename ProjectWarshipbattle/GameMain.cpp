#include"DxLib.h"
#include"HeaderForMain.h"

void GameMain();
void SingleGame_Mission_Progress();
void SingleGame_DeathMatch_Progress();
void MainMenu();

// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(TRUE);
	SetGraphMode(Screen::SCREEN_X, Screen::SCREEN_Z, Screen::COLOR);
	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}
	/*ここにはウインドーズメッセージの問題がある、
	DXLIBの場合は名前を変えれば解決できるが、
	WINAPIの場合はほかの処理をしないといけない*/
	SetMainWindowText("WarshipBattle");	
	SetAlwaysRunFlag(TRUE);

	SingleGame_DeathMatch_Progress();

	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}

void SingleGame_DeathMatch_Progress() {
	
	//ゲーム管理の部品を宣言
	PictureLoader PL;
	IngameDataManagement IDM;
	FrameControl FC;
	TeamDeathMatchControl TDMC;
	Camera MainCamera(CameraType::MAIN);

	/*初期化*/
	PL.AllInif();
//	IDM.registerTeamA(PL);
//	IDM.registerTeamB(PL);
	
	/*ゲームメインプログレス*/
	while (!TDMC.GameOver(IDM.TeamDestroyed())) {
//		MainCamera.GetXZ(IDM.ReferPlayerX(), IDM.ReferPlayerZ());
		IDM.Update(MainCamera,PL);
		FC.Wait();
		if (CheckHitKey(KEY_INPUT_RETURN) == 1)
			break;
	}
	/*結果発表*/
//	TDMC.DrawBoard(IDM);
	/*メモリ解放*/
	PL.FREE_ALL();
}