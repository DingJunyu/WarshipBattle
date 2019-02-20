#include "ButtonCollection.h"

ButtonCollection::~ButtonCollection(){
}

void ButtonCollection::Inif(PictureLoader *PL, SoundLoader *SL) {
	buttonContainer = new Button[buttonAmount];

	//メインメニューボタンの初期化
	buttonContainer[0];
}

void ButtonCollection::Destroy() {
	delete [] buttonContainer;
}