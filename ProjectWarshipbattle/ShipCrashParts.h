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
	//パーツのHP
	int heartPoint;
	int MaxHeartPoint;
	//パーツの相対位置とサイズ
	double relativeCoordX;
	double relativeCoordY;
	double length;
	double width;
	//パーツはも壊れたか
	bool damaged;
	bool isMainPart;//このパーツは大事なパーツだか
	double armorOntheSide;
	double armorOntheTop;
};