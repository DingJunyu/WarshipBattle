#pragma once
//�W���w�b�_�[
#include<list>
#include<vector>
//DX�w�b�_�[
#include"DxLib.h"
//����w�b�_�[
#include"ShipMain.h"
#include"Ammo.h"
#include"Bomb.h"
#include"Torpedo.h"
#include"PictureLoader.h"
class IngameDataManagement
{
public:
	IngameDataManagement();
	~IngameDataManagement();

	//�Q�[��������������
	//�����̊֐��Ƀt�@�C��������܂�
	void registerTeamA(PictureLoader PL);
	void registerTeamB(PictureLoader PL);

	//�f�[�^����
	void CrashDecision();
	void HitDecision();//�Q�[���R���g���[���[�ɓ����鐔��Ԃ�

	void DeleteUseless();

	//GameController�₢���킹
	int ReferRemainedAlliesNum();
	int ReferRemainedEnemiesNum();
	int ReferRemainedAlliesNumInHanger();
	int ReferRemainedAlliesNumInSky();
	int ReferRemainedEnemiesNumInHanger();
	int ReferRemainedEnemiesNumInSky();

	//���v�f�[�^
	int ShootCount();//�����͂��Ƃł���


	//�摜�`��
	void DrawAll();

	void DrawShips();
	void DrawPlanes();
	void DrawAmmo();
	void DrawBomb();
	void DrawTorpedo();
	
	std::vector<ShipMain> alliesFleet;
	std::vector<ShipMain> enemyFleet;
	std::list<ShipMain> sinkingShip;

	std::list<Ammo> shellList;
	std::list<Bomb> bombList;
	std::list<Torpedo> torpedoList;

private:
	int shootCount;
	int hitCount;
};

