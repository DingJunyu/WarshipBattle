#pragma once
//�W���w�b�_�[
#include<list>
#include<vector>
#include<stdlib.h>
//DX�w�b�_�[
#include"DxLib.h"
//����w�b�_�[
#include"DefinedData.h"
#include"Camera.h"
#include"ShipMain.h"
#include"Ammo.h"
#include"Bomb.h"
#include"Torpedo.h"
#include"PictureLoader.h"
#include"ShipData.h"
#include"FrameControl.h"
#include"Controller.h"
#include"FunctionsForCal.h"
class IngameDataManagement
{
public:
	IngameDataManagement() :MainCamera(CameraType::MAIN) {
		TEST_SHOW_ON = true;
	}
	~IngameDataManagement();

	//���̃R���g���[���[
	PictureLoader PL;
	FrameControl FC;
	Camera MainCamera;
	Controller CT;

	void Update();

	//�Q�[��������������
	//�����̊֐��Ƀt�@�C��������܂�
	void registerTeamA(PictureLoader PL);
	void registerTeamB(PictureLoader PL);

	//�f�[�^����
	void CrashDecision();
	void HitDecision();//�Q�[���R���g���[���[�ɓ����鐔��Ԃ�

	void DeleteUseless();

	//�J�����p���W�₢���킹
	double ReferPlayerX() { return alliesFleet[0].ReferCoordX(); }
	double ReferPlayerZ() { return alliesFleet[0].ReferCoordZ(); }

	//GameController�₢���킹
	int ReferRemainedAlliesNum();
	int ReferRemainedEnemiesNum();
	int ReferRemainedAlliesNumInHanger();
	int ReferRemainedAlliesNumInSky();
	int ReferRemainedEnemiesNumInHanger();
	int ReferRemainedEnemiesNumInSky();

	bool TeamDestroyed() { return false; }

	//���v�f�[�^
	int ShootCount();//�����͂��Ƃł���

	//���ׂẴe�X�g�͂����ōs��
	void TEST();

	void Control();

	//�摜�`��
	void DrawAll();
	void TEST_DRAW();

	void MoveAll();
	
private:
	//�`���֐�
	void DrawSea();
	void DrawShips();
	void DrawPlanes();
	void DrawAmmo();
	void DrawBomb();
	void DrawTorpedo();
	
	//�ړ��֐�
	void MoveShips();

	int shootCount;
	int hitCount;

	int numOfMapOnX;
	int numOfMapOnZ;

	bool TEST_SHOW_ON;

	std::vector<ShipMain> alliesFleet;
	std::vector<ShipMain> enemyFleet;
	std::list<ShipMain> sinkingShip;

	std::list<Ammo> shellList;
	std::list<Bomb> bombList;
	std::list<Torpedo> torpedoList;
};

