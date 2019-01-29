#pragma once
//�W���w�b�_�[
#include<list>
#include<vector>
//DX�w�b�_�[
#include"DxLib.h"
//����w�b�_�[
#include"Camera.h"
#include"ShipMain.h"
#include"Ammo.h"
#include"Bomb.h"
#include"Torpedo.h"
#include"PictureLoader.h"
#include"ShipData.h"
class IngameDataManagement
{
public:
	IngameDataManagement();
	~IngameDataManagement();

	void Update(Camera CM);

	//�Q�[��������������
	//�����̊֐��Ƀt�@�C��������܂�
	void registerTeamA(PictureLoader PL);
	void registerTeamB(PictureLoader PL);

	//�f�[�^����
	void CrashDecision();
	void HitDecision();//�Q�[���R���g���[���[�ɓ����鐔��Ԃ�

	void DeleteUseless();

	//�J�����p���W�₢���킹
	int ReferPlayerX() { return alliesFleet[0].ReferCoordX(); }
	int ReferPlayerZ() { return alliesFleet[0].ReferCoordZ(); }

	//GameController�₢���킹
	int ReferRemainedAlliesNum();
	int ReferRemainedEnemiesNum();
	int ReferRemainedAlliesNumInHanger();
	int ReferRemainedAlliesNumInSky();
	int ReferRemainedEnemiesNumInHanger();
	int ReferRemainedEnemiesNumInSky();

	bool TeamDestroyed();

	//���v�f�[�^
	int ShootCount();//�����͂��Ƃł���


	//�摜�`��
	void DrawAll(int CX, int CZ);


	
private:
	void DrawSea(int CX,int CZ);
	void DrawShips(int CX, int CZ);
	void DrawPlanes(int CX, int CZ);
	void DrawAmmo(int CX, int CZ);
	void DrawBomb(int CX, int CZ);
	void DrawTorpedo(int CX, int CZ);

	int shootCount;
	int hitCount;

	std::vector<ShipMain> alliesFleet;
	std::vector<ShipMain> enemyFleet;
	std::list<ShipMain> sinkingShip;

	std::list<Ammo> shellList;
	std::list<Bomb> bombList;
	std::list<Torpedo> torpedoList;
};

