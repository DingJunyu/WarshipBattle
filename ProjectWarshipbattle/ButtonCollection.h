#pragma once
#include"Button.h"
#include"PictureLoader.h"
#include"SoundLoader.h"
class ButtonCollection{
public:
	ButtonCollection(int bA):buttonAmount(20){}
	~ButtonCollection();

	void Inif(PictureLoader *PL,SoundLoader *SL);
	void Destroy();

	Button * buttonContainer;

private:
	int buttonAmount;
};

