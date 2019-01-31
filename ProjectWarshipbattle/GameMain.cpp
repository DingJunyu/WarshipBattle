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

	SingleGame_DeathMatch_Progress();

	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
}

void SingleGame_DeathMatch_Progress() {
	
	//�Q�[���Ǘ��̕��i��錾
	PictureLoader PL;
	IngameDataManagement IDM;
	FrameControl FC;
	TeamDeathMatchControl TDMC;
	Camera MainCamera(CameraType::MAIN);

	/*������*/
	PL.AllInif();
//	IDM.registerTeamA(PL);
//	IDM.registerTeamB(PL);
	
	/*�Q�[�����C���v���O���X*/
	while (!TDMC.GameOver(IDM.TeamDestroyed())) {
//		MainCamera.GetXZ(IDM.ReferPlayerX(), IDM.ReferPlayerZ());
		IDM.Update(MainCamera,PL);
		FC.Wait();
		if (CheckHitKey(KEY_INPUT_RETURN) == 1)
			break;
	}
	/*���ʔ��\*/
//	TDMC.DrawBoard(IDM);
	/*���������*/
	PL.FREE_ALL();
}