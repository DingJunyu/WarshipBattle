#include "ButtonCollection.h"

ButtonCollection::~ButtonCollection(){
}

void ButtonCollection::Inif(PictureLoader *PL) {
	buttonContainer = new Button[ButtonEvent::BUTTON_AMOUNT];

	//メインメニューボタンの初期化
	buttonContainer[ButtonEvent::NEW_GAME].Inif(
		PL->ReferButtonHandle(ButtonEvent::NEW_GAME),
		PL->ReferButtonPressedHandle(ButtonEvent::NEW_GAME)
	);
	buttonContainer[ButtonEvent::CONTINUE_GAME].Inif(
		PL->ReferButtonHandle(ButtonEvent::CONTINUE_GAME),
		PL->ReferButtonPressedHandle(ButtonEvent::CONTINUE_GAME)
	);
	buttonContainer[ButtonEvent::LOAD_GAME].Inif(
		PL->ReferButtonHandle(ButtonEvent::LOAD_GAME),
		PL->ReferButtonPressedHandle(ButtonEvent::LOAD_GAME)
	);
	buttonContainer[ButtonEvent::OPTION].Inif(
		PL->ReferButtonHandle(ButtonEvent::OPTION),
		PL->ReferButtonPressedHandle(ButtonEvent::OPTION)
	);
	buttonContainer[ButtonEvent::GAME_OVER].Inif(
		PL->ReferButtonHandle(ButtonEvent::GAME_OVER),
		PL->ReferButtonPressedHandle(ButtonEvent::GAME_OVER)
	);
}

void ButtonCollection::InifForUserInterface(PictureLoader *PL) {

}


void ButtonCollection::FREE() {
	delete[] buttonContainer;
}