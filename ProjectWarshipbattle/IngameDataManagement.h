#pragma once
#include"HeaderForIngameDataManagement.h"
class IngameDataManagement
{
public:
	IngameDataManagement() :MainCamera(CameraType::MAIN) {
		TEST_SHOW_ON = false;
	}
	~IngameDataManagement();

	void Update();

	//�Q�[��������������
	//�����̊֐��Ƀt�@�C��������܂�
	void Inif();
	void registerTeamA(PictureLoader PL);
	void registerTeamB(PictureLoader PL);
	void Free();

	//�f�[�^����
	void CrashDecision();
	void HitDecision();//�Q�[���R���g���[���[�ɓ����鐔��Ԃ�
	void GetNewEffect();

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
	//���̃R���g���[���[
	PictureLoader PL;
	FrameControl FC;
	Camera MainCamera;
	Controller CT;
	UserInterface UI;

	//�`���֐�
	void DrawSea();
	void DrawShips();
	void DrawShipsOnMiniMap();
	void DrawPlanes();
	void DrawAmmo();
	void DrawBomb();
	void DrawTorpedo();
	void DrawEffect();
	
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
	std::list<Effect> bubbleList;
};

