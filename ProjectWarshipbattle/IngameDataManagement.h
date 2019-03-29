#pragma once
#include"HeaderForIngameDataManagement.h"
/*�֐��̃v���C�x�[�g���͂��ꂩ�炷��*/
class IngameDataManagement
{
public:
	IngameDataManagement() :MainCamera(CameraType::MAIN) {
		TEST_SHOW_ON = false;
		GameOver = false;
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
	void SimpleHitDecision();

	void GetNewEffect();
	void DeleteUselessEffect();

	void DeleteUseless();

	//�e�Ǘ�
	void CheckSelectedWeapon();
	void InputNewAmmo(ShipMain *SM, FiringData FD);
	void DeleteUselessAmmo();

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
	bool ReferEndGame() { return GameOver; }

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
	EffectTemplate ET;
	SoundLoader SL;
	ClickableUserInterface CUI;

	//�`���֐�
	void DrawSea();
	void DrawShips();
	void DrawShipsOnMiniMap();
	void DrawPlanes();
	void DrawAmmo();
	void DrawBomb();
	void DrawTorpedo();
	void DrawEffectUnderShips();
	void DrawEffectBeyondShips();
	
	//�ړ��֐�
	void MoveShips();
	void MoveEffects();
	void MoveAmmo();

	//�ˌ��e�X�g
	void TestShoot();

	int shootCount;
	int hitCount; 

	//�e�X�g�֘A
	bool TEST_SHOW_ON;
	void SIMPLE_USER_INTERFACE();
	bool GameOver;

	/*�����֐�*/
	void CheckAndPlaySound();

	std::vector<ShipMain> alliesFleet;
	std::vector<ShipMain> enemyFleet;
	std::list<ShipMain> sinkingShip;

	std::list<Ammo> shellList;
	std::list<Bomb> bombList;
	std::list<Torpedo> torpedoList;
	std::list<Effect> bubbleList;
	std::list<Effect> smokeList;
};