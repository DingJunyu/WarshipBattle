#include "UserInterface.h"

UserInterface::~UserInterface()
{
}

void UserInterface::InifUI(PictureLoader *PL) {
	mat = PL->ReferMatHandle();
	shipCardMat = PL->ReferShipCardMatHandle();
}

void UserInterface::DrawUI() {
	//ï`Ç≠èáî‘Çíçà”ÅI
	DrawExtendGraph(0, 0, Screen::SCREEN_X/20, Screen::SCREEN_Z,
		*shipCardMat, FALSE);
	DrawExtendGraph(Screen::SCREEN_X*19/20,0 ,Screen::SCREEN_X, 
		Screen::SCREEN_Z,
		*shipCardMat, FALSE);

	DrawExtendGraph(matStartX, Screen::SCREEN_Z - matStartZ,
		Screen::SCREEN_X - 1, Screen::SCREEN_Z - 1, *mat, FALSE);
}