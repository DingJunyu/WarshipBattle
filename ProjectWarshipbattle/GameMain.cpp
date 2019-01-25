#include"DxLib.h"
#include"HeaderForMain.h"

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(TRUE);
	SetGraphMode(1028, 768, 32);
	if (DxLib_Init() == -1)		// �c�w���C�u��������������
	{
		return -1;			// �G���[���N�����璼���ɏI��
	}
	SetAlwaysRunFlag(TRUE);

	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
}

void GameMain();
void SingleGame_Mission_Progress();
void SingleGame_DeathMatch_Progress();
void MainMenu();

void SingleGame_DeathMatch_Progress() {
	
	//�Q�[���Ǘ��̕��i��錾
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