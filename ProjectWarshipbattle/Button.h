#pragma once
#include"DxLib.h"
#include"DefinedData.h"
class Button {
public:
	Button() {
		pressed = false;
		zoomMutliple = 1.0f;
	}
	~Button();

	void Inif(int *bH, int *bPH, double zM);
	void SetXZ(double xP, double zP);
	void CheckXZ();

	void DrawThisButton();
	void CheckMousePosition(int mouseX, int mouseZ);
	void ChangePressed() { pressed = !pressed; }

private:
	int coordX;
	int coordZ;

	double xPercent;
	double zPercent;
	
	int *buttonHandle;
	int *buttonPressedHandle;

	int graphSizeX;
	int graphSizeZ;

	double zoomMutliple;

	int time;
	bool pressed;
};