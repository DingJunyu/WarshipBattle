#include "ButtonCollection.h"

ButtonCollection::~ButtonCollection(){
}

void ButtonCollection::Inif(PictureLoader *PL, SoundLoader *SL) {
	buttonContainer = new Button[buttonAmount];

	//���C�����j���[�{�^���̏�����
	buttonContainer[0];
}

void ButtonCollection::Destroy() {
	delete [] buttonContainer;
}