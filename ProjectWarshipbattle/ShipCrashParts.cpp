#include "ShipCrashParts.h"



ShipCrashParts::ShipCrashParts()//初期化
{
	damaged = false;
	isMainPart = false;
}


ShipCrashParts::~ShipCrashParts()
{
}

void ShipCrashParts::MinusHP(double damage) {
	//パーツのHPが減る時は生きる状態を確認
	heartPoint -= damage;
	if (heartPoint <= 0)
		damaged = true;
}