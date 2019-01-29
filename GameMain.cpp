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
	Camera MainCamera(CameraType::MAIN);

	/*������*/
	PL.AllInif();
	IDM.registerTeamA(PL);
	IDM.registerTeamB(PL);
	
	/*�Q�[�����C���v���O���X*/
	while (!TDMC.GameOver(IDM.TeamDestroyed())) {
		MainCamera.GetXZ(IDM.ReferPlayerX(), IDM.ReferPlayerZ());
		IDM.Update(MainCamera);
		FC.Wait();
	}
	/*���ʔ��\*/
	TDMC.DrawBoard(IDM);
	/*���������*/
	PL.FREE_ALL();
}