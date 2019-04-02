#include "ClickableUserInterface.h"

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

	for (int i = CommandSerial::INCREASE_OUTPUT; i <= CommandSerial::EXIT; i++) {
		for (int j = 0; j < 6; j++)
			buttonPosition[i][j] = 1;
	}

	SetThisOne(CommandSerial::MENU, BUTTON_POSITION_INGAME::MENU_X,
		BUTTON_POSITION_INGAME::MENU_Z, BUTTON_POSITION_INGAME::MENU_MULTI);
	SetThisOne(CommandSerial::CONTINUE, BUTTON_POSITION_INGAME::CONTINUE_X,
		BUTTON_POSITION_INGAME::CONTINUE_Z, BUTTON_POSITION_INGAME::CONTINUE_MULTI);
	SetThisOne(CommandSerial::SETTING, BUTTON_POSITION_INGAME::SETTING_X,
		BUTTON_POSITION_INGAME::SETTING_Z, BUTTON_POSITION_INGAME::SETTING_MULTI);
	SetThisOne(CommandSerial::EXIT, BUTTON_POSITION_INGAME::EXIT_X,
		BUTTON_POSITION_INGAME::EXIT_Z, BUTTON_POSITION_INGAME::EXIT_MULTI);

	SetThisOne(CommandSerial::SHOOT, BUTTON_POSITION_INGAME::SHOOT_X,
		BUTTON_POSITION_INGAME::SHOOT_Z, BUTTON_POSITION_INGAME::SHOOT_MULTI);
	SetThisOne(CommandSerial::TURRET_TURN_RIGHT, BUTTON_POSITION_INGAME::TURRET_TURN_RIGHT_X,
		BUTTON_POSITION_INGAME::TURRET_TURN_RIGHT_Z, BUTTON_POSITION_INGAME::TURRET_TURN_RIGHT_MULTI);
	SetThisOne(CommandSerial::TURRET_TURN_LEFT, BUTTON_POSITION_INGAME::TURRET_TURN_LEFT_X,
		BUTTON_POSITION_INGAME::TURRET_TURN_LEFT_Z, BUTTON_POSITION_INGAME::TURRET_TURN_LEFT_MULTI);
	SetThisOne(CommandSerial::TURRET_PULLUP, BUTTON_POSITION_INGAME::TURRET_PULLUP_X,
		BUTTON_POSITION_INGAME::TURRET_PULLUP_Z, BUTTON_POSITION_INGAME::TURRET_PULLUP_MULTI);
	SetThisOne(CommandSerial::TURRET_PULLDOWN, BUTTON_POSITION_INGAME::TURRET_PULLDOWN_X,
		BUTTON_POSITION_INGAME::TURRET_PULLDOWN_Z, BUTTON_POSITION_INGAME::TURRET_PULLDOWN_MULTI);

	SetThisOne(CommandSerial::INCREASE_OUTPUT, BUTTON_POSITION_INGAME::INCREASE_OUTPUT_X,
		BUTTON_POSITION_INGAME::INCREASE_OUTPUT_Z, BUTTON_POSITION_INGAME::INCREASE_OUTPUT_MULTI);
	SetThisOne(CommandSerial::DECREASE_OUTPUT, BUTTON_POSITION_INGAME::DECREASE_OUTPUT_X,
		BUTTON_POSITION_INGAME::DECREASE_OUTPUT_Z, BUTTON_POSITION_INGAME::DECREASE_OUTPUT_MULTI);
	
	SetThisOne(CommandSerial::TURN_RIGHT, BUTTON_POSITION_INGAME::TURN_RIGHT_X,
		BUTTON_POSITION_INGAME::TURN_RIGHT_Z, BUTTON_POSITION_INGAME::TURN_RIGHT_MULTI);
	SetThisOne(CommandSerial::TURN_LEFT, BUTTON_POSITION_INGAME::TURN_LEFT_X,
		BUTTON_POSITION_INGAME::TURN_LEFT_Z, BUTTON_POSITION_INGAME::TURN_LEFT_MULTI);
	SetThisOne(CommandSerial::TURN_RETURN, BUTTON_POSITION_INGAME::TURN_RETURN_X,
		BUTTON_POSITION_INGAME::TURN_RETURN_Z, BUTTON_POSITION_INGAME::TURN_RETURN_MULTI);


	for (int i = CommandSerial::INCREASE_OUTPUT; i <= CommandSerial::EXIT; i++)
		BC.buttonContainer[i].SetXZ(
			buttonPosition[i][0],
			buttonPosition[i][1],
			buttonPosition[i][4]
		);
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

	for (int i = CommandSerial::INCREASE_OUTPUT; i <= CommandSerial::EXIT; i++) {
		if(buttonPosition[i][5] == 0)
		if (mouseX > buttonPosition[i][0] * Screen::SCREEN_X &&
			mouseX < buttonPosition[i][0] *
			Screen::SCREEN_X + buttonPosition[i][2] * buttonPosition[i][4] &&
			mouseZ > buttonPosition[i][1] * Screen::SCREEN_Z &&
			mouseZ < buttonPosition[i][1] *
			Screen::SCREEN_Z + buttonPosition[i][3] * buttonPosition[i][4]) {

			BC.buttonContainer[i].ChangePressed();

			if (pressed) {
				answer = i;
			}
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
	for (int i = CommandSerial::INCREASE_OUTPUT; i <= CommandSerial::EXIT; i++) {
		if (buttonPosition[i][5] == 0)
			BC.buttonContainer[i].DrawThisButton();
	}
}

void ClickableUserInterface::SetNormalStatus() {
	buttonPosition[CommandSerial::MENU][5] = 0;
	buttonPosition[CommandSerial::SHOOT][5] = 0;
	buttonPosition[CommandSerial::INCREASE_OUTPUT][5] = 0;
	buttonPosition[CommandSerial::DECREASE_OUTPUT][5] = 0;
	buttonPosition[CommandSerial::TURN_RIGHT][5] = 0;
	buttonPosition[CommandSerial::TURN_LEFT][5] = 0;
	buttonPosition[CommandSerial::TURN_RETURN][5] = 0;
	buttonPosition[CommandSerial::TURRET_TURN_RIGHT][5] = 0;
	buttonPosition[CommandSerial::TURRET_TURN_LEFT][5] = 0;
	buttonPosition[CommandSerial::TURRET_PULLUP][5] = 0;
	buttonPosition[CommandSerial::TURRET_PULLDOWN][5] = 0;
}

void ClickableUserInterface::LetMeSeeMenu() {
	for (int i = CommandSerial::CONTINUE; i <= CommandSerial::EXIT; i++) {
		buttonPosition[i][5] = 0;
	}
	menuOpened = true;
}

void ClickableUserInterface::CloseMenu() {
	for (int i = CommandSerial::CONTINUE; i <= CommandSerial::EXIT; i++) {
		buttonPosition[i][5] = 1;
	}
	menuOpened = false;
}
