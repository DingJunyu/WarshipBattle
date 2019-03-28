#include"DxLib.h"
#include"HeaderForMain.h"

void GameMain();
void SingleGame_Mission_Progress();
void SingleGame_DeathMatch_Progress();
int MainMenu();

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
	srand((unsigned)time(NULL));

	if (SetConsoleCtrlHandler((PHANDLER_ROUTINE)ctrlhandler, true)){}
	else
	{
		return -1;
	}

	MainMenuController MMC;
	int choice = -1;
	bool endGame = false;

	while (!endGame) {

		choice = MainMenu();

		if (ProcessMessage() == -1)
			break;

		//メニューから取ったコマンドに合わせて関数を呼び出す
		switch (choice) {
		case ButtonEvent::NEW_GAME:
			SingleGame_DeathMatch_Progress(); break;
		case ButtonEvent::GAME_OVER:endGame = true; break;
		}
	}

	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}

int MainMenu(){
	MainMenuController MMC;
	int choice = -1;

		MMC.Inif();//メニュー部分初期化
		MMC.DrawTitle();//タイトル描く
		MMC.DrawLoading();
		choice = -1;//選択を初期化

		while (choice == -1) {
			MMC.DrawMainMenu();//メインメニューを描く
			choice = MMC.CheckChoice();//選択を確認・バー状態更新
									   //メインメニューから脱出
			if (CheckHitKey(KEY_INPUT_ESCAPE) == TRUE &&
				GetInputChar(TRUE)) {
				choice = ButtonEvent::GAME_OVER;
			}
			if (ProcessMessage() == -1)
				break;
		}

		MMC.FREE();
		MMC.DrawLoading();//この関数はほかの部分に移動する？

		return choice;
}

void SingleGame_DeathMatch_Progress() {
	
	//ゲーム管理の部品を宣言
	IngameDataManagement IDM;
	TeamDeathMatchControl TDMC;

	/*初期化*/
	IDM.Inif();
	IDM.TEST();

	/*ゲームメインプログレス*/
	while (!TDMC.GameOver(IDM.TeamDestroyed())) {
		IDM.Update();
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)
			break;

		if (ProcessMessage() == -1)//エラー処理
			break;
	}
	/*結果発表*/
//	TDMC.DrawBoard(IDM);
	/*メモリ解放*/
	IDM.Free();
}