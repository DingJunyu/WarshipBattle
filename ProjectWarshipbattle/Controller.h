#pragma once
#include"DefinedData.h"
#include"SoundLoader.h"
#include"DxLib.h"
/*ここのコントローラーでは、キーボードの入力を受け取って信号に変更します。
マウス操作などはClickableUserInterfaceに実現します*/
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

