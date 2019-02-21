#include"DxLib.h"
#include"HeaderForMain.h"

void GameMain();
void SingleGame_Mission_Progress();
void SingleGame_DeathMatch_Progress();
void MainMenu();

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(TRUE);
	SetGraphMode(Screen::SCREEN_X, Screen::SCREEN_Z, Screen::COLOR);
	if (DxLib_Init() == -1)		// �c�w���C�u��������������
	{
		return -1;			// �G���[���N�����璼���ɏI��
	}
	/*�����ɂ̓E�C���h�[�Y���b�Z�[�W�̖�肪����A
	DXLIB�̏ꍇ�͖��O��ς���Ή����ł��邪�A
	WINAPI�̏ꍇ�͂ق��̏��������Ȃ��Ƃ����Ȃ�*/
	SetMainWindowText("WarshipBattle");	
	SetAlwaysRunFlag(TRUE);
	srand((unsigned)time(NULL));

	MainMenuController MMC;

	MMC.Inif();
	while (CheckHitKeyAll()==0) {
		MMC.DrawTitle();
	}

	MMC.FREE();
	SingleGame_DeathMatch_Progress();

	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
}

void SingleGame_DeathMatch_Progress() {
	
	//�Q�[���Ǘ��̕��i��錾
	IngameDataManagement IDM;
	TeamDeathMatchControl TDMC;

	/*������*/
	IDM.Inif();
	IDM.TEST();

	/*�Q�[�����C���v���O���X*/
	while (!TDMC.GameOver(IDM.TeamDestroyed())) {
		IDM.Update();
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)
			break;
	}
	/*���ʔ��\*/
//	TDMC.DrawBoard(IDM);
	/*���������*/
	IDM.Free();
}