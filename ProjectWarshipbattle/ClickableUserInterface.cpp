#include "ClickableUserInterface.h"



ClickableUserInterface::ClickableUserInterface()
{
}


ClickableUserInterface::~ClickableUserInterface()
{
}

/*ƒƒ‚ƒŠŠÖ˜A‘€ì*/
void ClickableUserInterface::MemorySecure(int Count) {
	buttonPosition = new double *[Count];
	for (int i = 0; i < Count; i++) {
		buttonPosition[i] = new double[7];
	}
}

void ClickableUserInterface::MemoryFree(int Count) {
	for (int i = 0; i < Count; i++) {
		delete[] buttonPosition[i];
	}
	delete[] buttonPosition;
}

/*‰Šú‰»ŠÖ”‚È‚Ç*/
void ClickableUserInterface::IngameInif(PictureLoader *PL, SoundLoader *SL) {
	MemorySecure(CommandSerial::COUNT);
	BC.InifForUserInterface(PL);

	for (int i = CommandSerial::MENU; i <= CommandSerial::EXIT; i++) {
		for (int j = 0; j < 6; j++)
			buttonPosition[i][j] = 1;
	}

	SetThisOne(CommandSerial::MENU, BUTTON_POSITION_INGAME::MENU_X,
		BUTTON_POSITION_INGAME::MENU_Z, BUTTON_POSITION_INGAME::MENU_MULTI);

	BC.buttonContainer[CommandSerial::MENU].SetXZ(buttonPosition[CommandSerial::MENU][0],
		buttonPosition[CommandSerial::MENU][1], buttonPosition[CommandSerial::MENU][4]);
}

void ClickableUserInterface::Free() {
	MemoryFree(CommandSerial::COUNT);
}

int ClickableUserInterface::CheckChoice() {

	int answer = CommandSerial::NONE_COMMAND;
	bool pressed = false;

	int mouseX, mouseZ;

	GetMousePoint(&mouseX, &mouseZ);
	if (GetMouseInput() == MOUSE_INPUT_LEFT) {
		pressed = true;
	}

	for (int i = CommandSerial::MENU; i <= CommandSerial::EXIT; i++) {
		if (mouseX > buttonPosition[i][0] * Screen::SCREEN_X &&
			mouseX < buttonPosition[i][0] *
			Screen::SCREEN_X + buttonPosition[i][2] * buttonPosition[i][4] &&
			mouseZ > buttonPosition[i][1] * Screen::SCREEN_Z &&
			mouseZ < buttonPosition[i][1] *
			Screen::SCREEN_Z + buttonPosition[i][2] * buttonPosition[i][4]) {

			BC.buttonContainer[i].ChangePressed();

			if (pressed)
				answer = i;
		}
	}

	return answer;
}

void ClickableUserInterface::SetThisOne(int num, double x, double z, double mt) {
	buttonPosition[num][2] = BC.buttonContainer[num].ReferGraphSizeX();
	buttonPosition[num][3] = BC.buttonContainer[num].ReferGraphSizeZ();

	buttonPosition[num][0] = x;
	buttonPosition[num][1] = z;
	buttonPosition[num][4] = mt;
	buttonPosition[num][5] = 1;
}

void ClickableUserInterface::Draw() {
	for (int i = CommandSerial::MENU; i <= CommandSerial::EXIT; i++) {
		if (buttonPosition[i][5] == 0)
			BC.buttonContainer[i].DrawThisButton();
	}
}

void ClickableUserInterface::SetNormalStatus() {
	buttonPosition[CommandSerial::MENU][5] = 0;
}