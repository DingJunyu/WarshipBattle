#include "ShipCrashParts.h"



ShipCrashParts::ShipCrashParts()//������
{
	damaged = false;
	isMainPart = false;
}


ShipCrashParts::~ShipCrashParts()
{
}

void ShipCrashParts::MinusHP(double damage) {
	//�p�[�c��HP�����鎞�͐������Ԃ��m�F
	heartPoint -= damage;
	if (heartPoint <= 0)
		damaged = true;
}