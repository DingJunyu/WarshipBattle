#pragma once
#include"DxLib.h"
#include"DefinedData.h"
class Button {
public:
	Button() {
		pressed = false;
		zoomMultiple = 1.0f;
	}
	~Button();

	void Inif(int *bH, int *bPH);
	void SetXZ(double xP, double zP, double zM);
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

	double zoomMultiple;

	int time;
	bool pressed;
};