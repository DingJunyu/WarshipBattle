#include "Button.h"

Button::~Button() {
}

void Button::Inif(int *bH, int *bPH) {
	*buttonHandle = *bH;
	*buttonHandle = *bPH;
	GetGraphSize(*bH, &graphSizeX, &graphSizeZ);
}

void Button::SetXZ(double xP, double zP, double zM) {
	xPercent = xP;
	zPercent = zP;

	coordX = xP * Screen::SCREEN_X;
	coordZ = zP * Screen::SCREEN_Z;

	zoomMultiple = zM;
}

void Button::CheckXZ() {
	coordX = xPercent * Screen::SCREEN_X;
	coordZ = zPercent * Screen::SCREEN_Z;
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
	if (pressed)
		DrawExtendGraph(coordX, coordZ, coordX + graphSizeX * zoomMultiple,
			coordZ + graphSizeZ * zoomMultiple, *buttonHandle, TRUE);
	else
		DrawExtendGraph(coordX, coordZ, coordX + graphSizeX * zoomMultiple,
			coordZ + graphSizeZ * zoomMultiple, *buttonPressedHandle, TRUE);
}