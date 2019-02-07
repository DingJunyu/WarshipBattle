#include "UserInterface.h"

UserInterface::~UserInterface()
{
}

void UserInterface::InifUI(PictureLoader *PL) {
	mat = PL->ReferMatHandle();
	shipCardMat = PL->ReferShipCardMatHandle();
	miniMapMat = PL->ReferMiniMapMatHandle();
	miniMapPaper = PL->ReferMiniMapPaperHandle();
}

void UserInterface::DrawUI() {
	//ï`Ç≠èáî‘Çíçà”ÅI
	DrawExtendGraph(0, 0, Screen::SCREEN_X / 20, Screen::SCREEN_Z,
		*shipCardMat, FALSE);
	DrawExtendGraph(Screen::SCREEN_X * 19/20,0 ,Screen::SCREEN_X, 
		Screen::SCREEN_Z,
		*shipCardMat, FALSE);

	DrawExtendGraph((int)matStartX, Screen::SCREEN_Z - (int)matStartZ,
		Screen::SCREEN_X - 1, Screen::SCREEN_Z - 1, *mat, FALSE);

	DrawExtendGraph(Screen::SCREEN_X / 2 - (int)mapMatSize,
		Screen::SCREEN_Z - (int)(1.2 * mapMatSize),
		Screen::SCREEN_X / 2 + (int)mapMatSize ,
		Screen::SCREEN_Z, *miniMapMat, FALSE);

	DrawExtendGraph(Screen::SCREEN_X / 2 - (int)mapPaperSize,
		Screen::SCREEN_Z - (int)(1.2 * (int)mapPaperSize),
		Screen::SCREEN_X/2 + (int)mapPaperSize,
		Screen::SCREEN_Z - 5, *miniMapPaper, FALSE);
}

void UserInterface::DrawShipOnTheMap(double X, double Z,bool enemy) {
	
	unsigned int enemyCr = GetColor(255, 0, 0);
	unsigned int allyCr = GetColor(0, 0, 255);

	unsigned int realCr = enemy ? enemyCr : allyCr;

	double realX = abs((X + MapSize::xSize) /
		(MapSize::xSize * 2)) * mapPaperSize * 2;
	double realZ = abs((Z + MapSize::zSize) /
		(MapSize::zSize * 2)) * mapPaperSize * 1.2f;
	
	DrawBox(
		Screen::SCREEN_X / 2 - (int)mapPaperSize + (int)realX,
		Screen::SCREEN_Z - (int)(((1.2 * (int)mapPaperSize) - realZ)),
		Screen::SCREEN_X / 2 - (int)mapPaperSize + (int)realX + 10,
		Screen::SCREEN_Z - (int)(((1.2 * (int)mapPaperSize) - realZ) - 5),
		realCr,TRUE);
}