#pragma once
#include"Button.h"
#include"PictureLoader.h"
#include"SoundLoader.h"
class ButtonCollection{
public:
	ButtonCollection() {}
	~ButtonCollection();

	void Inif(PictureLoader *PL);
	void FREE();

	Button * buttonContainer;

private:
	int buttonAmount;
};

