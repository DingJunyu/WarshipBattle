#pragma once
class ShipCrashParts
{
public:
	ShipCrashParts();
	~ShipCrashParts();

	double ReferRelativeCoordX() { return relativeCoordX; }
	double ReferRelativeCoordY() { return relativeCoordY; }
	double ReferLength() { return length; }
	double ReferWidth() { return width; }
	bool ReferDamaged() { return damaged; }
	int ReferHeartPoint() { return heartPoint; }
	bool ReferMainPart() { return isMainPart; }

	void MinusHP(double damage);

	void SetRelativeCoordX(double RCX) { relativeCoordX = RCX; }
	void SetRelativeCoordY(double RCY) { relativeCoordY = RCY; }
	void SetLength(double L) { length = L; }
	void SetWidth(double W) { width = W; }
	void SetMainPart() { isMainPart = true; }

private:
	//�p�[�c��HP
	int heartPoint;
	int MaxHeartPoint;
	//�p�[�c�̑��Έʒu�ƃT�C�Y
	double relativeCoordX;
	double relativeCoordY;
	double length;
	double width;
	//�p�[�c�͂���ꂽ��
	bool damaged;
	bool isMainPart;//���̃p�[�c�͑厖�ȃp�[�c����
	double armorOntheSide;
	double armorOntheTop;
};