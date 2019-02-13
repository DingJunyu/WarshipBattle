#pragma once
#include"DefinedData.h"
#include"SoundLoader.h"
#include"DxLib.h"
class Controller
{
public:
	Controller();
	~Controller();

	void Inif(SoundLoader *SL);

	int GetCommand();

private:
	int Action;
	char KeyBuf[256];

	int shipHordType;
	int *shipHordHigh;
	int *shipHordLow;
};

