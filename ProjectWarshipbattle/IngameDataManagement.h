#pragma once
//�W���w�b�_�[
#include<list>
#include<vector>
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
class IngameDataManagement
{
public:
	IngameDataManagement();
	~IngameDataManagement();

	void Update(Camera CM, PictureLoader PL);

	//�Q�[��������������
	//�����̊֐��Ƀt�@�C��������܂�
	void registerTeamA(PictureLoader PL);
	void registerTeamB(PictureLoader PL);

	//�f�[�^����
	void CrashDecision();
	void HitDecision();//�Q�[���R���g���[���[�ɓ����鐔��Ԃ�

	void DeleteUseless();

	//�J�����p���W�₢���킹
//	double ReferPlayerX() { return alliesFleet[0].ReferCoordX(); }
//	double ReferPlayerZ() { return alliesFleet[0].ReferCoordZ(); }

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


	//�摜�`��
	void DrawAll(double CX, double CZ, PictureLoader PL);
	
private:
	void DrawSea(double CX,double CZ, PictureLoader PL);
	void DrawShips(double CX, double CZ, PictureLoader PL);
	void DrawPlanes(double CX, double CZ, PictureLoader PL);
	void DrawAmmo(double CX, double CZ, PictureLoader PL);
	void DrawBomb(double CX, double CZ, PictureLoader PL);
	void DrawTorpedo(double CX, double CZ, PictureLoader PL);

	int shootCount;
	int hitCount;

	int numOfMapOnX;
	int numOfMapOnZ;

	std::vector<ShipMain> alliesFleet;
	std::vector<ShipMain> enemyFleet;
	std::list<ShipMain> sinkingShip;

	std::list<Ammo> shellList;
	std::list<Bomb> bombList;
	std::list<Torpedo> torpedoList;
};

