#pragma once
#include"DefinedData.h"
#include"DxLib.h"
class Controller
{
public:
	Controller();
	~Controller();

	int GetCommand();
private:
	int Action;
	char KeyBuf[256];
};

