#include "Button.h"

Button::~Button() {
}

void Button::Inif(int *bH, int *bPH) {
	buttonHandle = bH;
	buttonPressedHandle = bPH;
	GetGraphSize(*bH, &graphSizeX, &graphSizeZ);
	pressed = false;
}

void Button::SetXZ(double xP, double zP, double zM) {
	xPercent = xP;
	zPercent = zP;

	coordX = (int)(xP * Screen::SCREEN_X);
	coordZ = (int)(zP * Screen::SCREEN_Z);

	zoomMultiple = zM;
}

void Button::CheckXZ() {
	coordX = (int)(xPercent * Screen::SCREEN_X);
	coordZ = (int)(zPercent * Screen::SCREEN_Z);
}

void Button::CheckMousePosition(int mouseX, int mouseZ) {
	if (mouseX > coordX && mouseX < coordX + graphSizeX * zoomMultiple) {
		if (mouseZ > coordZ && mouseZ < coordZ + graphSizeZ * zoomMultiple) {
			pressed = true;
		}
	}
	pressed = false;
}

void Button::DrawThisButton() {
	if (!pressed)
		DrawExtendGraph((int)coordX, (int)coordZ,
			(int)(coordX + graphSizeX * zoomMultiple),
			(int)(coordZ + graphSizeZ * zoomMultiple), 
			*buttonHandle, TRUE);
	else
		DrawExtendGraph((int)coordX, (int)coordZ,
			(int)(coordX + graphSizeX * zoomMultiple),
			(int)(coordZ + graphSizeZ * zoomMultiple),
			*buttonPressedHandle, TRUE);

	pressed = false;
}