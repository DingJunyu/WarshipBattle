#pragma once
class Weapon
{
public:
	Weapon();
	~Weapon();

	//�₢���킹�֐�
	int ReferNumbefofGuns() { return numberofGuns; }
	int ReferReloadTime() { return reloadTime; }
	int ReferLastShootedTime() { return lastShootedTime; }
	bool ReferShootable();//�ˌ��ł����true��߂�



private:
	int numberofGuns;//�C���̘A����
	int reloadTime;//�đ��U�̎���
	int lastShootedTime;//�O��ˌ���������
	double calibre;

	int *turrentHandle;//�摜�f�[�^�ۑ��p
	
	double relativeCoordX;
	double relativeCoordY;
	double length;
	double width;
	double radianOnZ;//�����ʂ̊p�x
	double radianOnY;//�C�g�̊p�x-->����ŖC�e�����ʒu�𐄒肷��

	int heartPoint;
	int maxHeartPoint;
	double armorOntheSide;
	double armorOntheTop;

};