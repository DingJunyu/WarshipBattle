#pragma once
class ShipCrashParts
{
public:
	ShipCrashParts(bool mainPart, double dft) :isMainPart(mainPart),
		draft(dft) {
		damaged = false;
		isMainPart = false;
	}
	~ShipCrashParts();

	//�f�[�^�₢���킹�֐�
	double ReferRelativeCoordX() { return relativeCoordX; }
	double ReferRelativeCoordZ() { return relativeCoordZ; }
	double ReferLength() { return length; }
	double ReferWidth() { return width; }
	int ReferHeartPoint() { return heartPoint; }

	//��Ԗ₢���킹�֐�
	bool ReferDamaged() { return damaged; }
	bool ReferMainPart() { return isMainPart; }

	//����֐�
	void MinusHP(int damage);

	//�������֐��Ȃ�
	void SetRelativeCoordX(double RCX) { relativeCoordX = RCX; }
	void SetRelativeCoordZ(double RCZ) { relativeCoordZ = RCZ; }
	void SetLength(double L) { length = L; }
	void SetWidth(double W) { width = W; }

private:
	//�p�[�c��HP
	int heartPoint;
	int MaxHeartPoint;
	//�p�[�c�̑��Έʒu�ƃT�C�Y
	double relativeCoordX;
	double relativeCoordZ;
	double length;
	double draft;
	double width;
	double height;//����-�����蔻��p
	//�p�[�c�͂���ꂽ��
	bool damaged;
	bool isMainPart;//���̃p�[�c�͑厖�ȃp�[�c����
	double armorOntheSide;
	double armorOntheTop;
};