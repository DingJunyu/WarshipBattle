#pragma once
#include"DxLib.h"
class SoundLoader
{
public:
	SoundLoader();
	~SoundLoader();

	void Inif();
	void FreeAll();

private:
	void LoadSound();
	void DeleteSound();

	int shipSoundEngine;

	int shipSoundMoving;

	int shipHordLargeShip;
	int shipHordMediumShip;
	int shipHordSmallShip;

};