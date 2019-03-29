#include "ButtonCollection.h"

ButtonCollection::~ButtonCollection(){
}

void ButtonCollection::Inif(PictureLoader *PL) {
	buttonContainer = new Button[ButtonEvent::BUTTON_AMOUNT];

	//メインメニューボタンの初期化
	for (int i = ButtonEvent::NEW_GAME; i <= ButtonEvent::GAME_OVER; i++)
		buttonContainer[i].Inif(
			PL->ReferButtonHandle(i),
			PL->ReferButtonPressedHandle(i)
		);
}

void ButtonCollection::InifForUserInterface(PictureLoader *PL) {
	buttonContainer = new Button[CommandSerial::COUNT];

	//ボタン初期化
	for (int i = CommandSerial::INCREASE_OUTPUT; i <= CommandSerial::EXIT; i++)
		buttonContainer[i].Inif(
			PL->ReferButtonIntheGame(i),
			PL->ReferButtonPressedIntheGame(i)
		);
}

void ButtonCollection::FREE() {
	delete[] buttonContainer;
}