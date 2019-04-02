#include "UserInterface.h"

UserInterface::~UserInterface()
{
}

void UserInterface::InifUI(PictureLoader *PL) {
	mat = PL->ReferMatHandle();
	shipCardMat = PL->ReferShipCardMatHandle();
	miniMapMat = PL->ReferMiniMapMatHandle();
	miniMapPaper = PL->ReferMiniMapPaperHandle();

	handleList[UI_LIST::RADAR] = PL->ReferUIList(UI_LIST::RADAR);
	handleList[UI_LIST::ARROW_RED] = PL->ReferUIList(UI_LIST::ARROW_RED);
}

void UserInterface::DrawUI() {
	int graphSizeX, graphSizeZ;
	int startX, startZ;
	//描く順番を注意！
	DrawExtendGraph(0, 0, Screen::SCREEN_X / 20, Screen::SCREEN_Z,
		*shipCardMat, FALSE);
	DrawExtendGraph(Screen::SCREEN_X * 19/20,0 ,Screen::SCREEN_X, 
		Screen::SCREEN_Z,
		*shipCardMat, FALSE);

	/**/
	DrawExtendGraph((int)matStartX, Screen::SCREEN_Z - (int)matStartZ,
		Screen::SCREEN_X - 1, Screen::SCREEN_Z - 1, *mat, FALSE);

	/*ミニマップ*/
	DrawExtendGraph(Screen::SCREEN_X / 2 - (int)mapMatSize,
		Screen::SCREEN_Z - (int)(1.2 * mapMatSize),
		Screen::SCREEN_X / 2 + (int)mapMatSize ,
		Screen::SCREEN_Z, *miniMapMat, FALSE);

	DrawExtendGraph(Screen::SCREEN_X / 2 - (int)mapPaperSize,
		Screen::SCREEN_Z - (int)(1.2 * (int)mapPaperSize),
		Screen::SCREEN_X/2 + (int)mapPaperSize,
		Screen::SCREEN_Z - 5, *miniMapPaper, FALSE);

	/*レーダーA*/
	GetGraphSize(*handleList[UI_LIST::RADAR], &graphSizeX, &graphSizeZ);
	startX = (int)(Screen::SCREEN_X * USER_INTERFACE_POSITION::RADAR_A_X);
	startZ = (int)(Screen::SCREEN_Z * USER_INTERFACE_POSITION::RADAR_A_Z);
	DrawExtendGraph(
		startX, startZ,
		(int)(startX+graphSizeX*USER_INTERFACE_POSITION::RADAR_A_MULTI),
		(int)(startZ+graphSizeZ*USER_INTERFACE_POSITION::RADAR_A_MULTI),
		*handleList[UI_LIST::RADAR],TRUE
	);

	/*武器CD*/
	unsigned int Cr;
	Cr = GetColor(0, 0, 0);

	DrawBox(
		(int)(USER_INTERFACE_POSITION::SHOOT_CD_MAIN_X * Screen::SCREEN_X),
		(int)(USER_INTERFACE_POSITION::SHOOT_CD_MAIN_Z * Screen::SCREEN_Z),
		(int)(USER_INTERFACE_POSITION::SHOOT_CD_MAIN_X * Screen::SCREEN_X) +
		(int)USER_INTERFACE_POSITION::SHOOT_CD_MAIN_SIZE_X,
		(int)(USER_INTERFACE_POSITION::SHOOT_CD_MAIN_Z * Screen::SCREEN_Z) +
		(int)USER_INTERFACE_POSITION::SHOOT_CD_MAIN_SIZE_Z,
		Cr,TRUE
	);
}

void UserInterface::DrawUINeedInput(ShipMain *ship) {
	int graphSizeX, graphSizeZ;
	int startX, startZ;

	double radian;

	/*レーダーの上の矢印*/
	radian = ship->ReferMainWeaponRadianOnZ() + ship->ReferRadianOnZ()
		- MathAndPhysics::PI/4;
	GetGraphSize(*handleList[UI_LIST::ARROW_RED], &graphSizeX, &graphSizeZ);

	DrawRotaGraph3(
		(int)(Screen::SCREEN_X * USER_INTERFACE_POSITION::ARROW_RED_A_X),
		(int)(Screen::SCREEN_Z * USER_INTERFACE_POSITION::ARROW_RED_A_Z),
		0, 0,
		USER_INTERFACE_POSITION::ARROW_RED_A_MULTI,
		USER_INTERFACE_POSITION::ARROW_RED_A_MULTI,
		radian,*handleList[UI_LIST::ARROW_RED],TRUE,FALSE
	);

	/*武器CD*/
	unsigned int Cr;
	Cr = GetColor(0, 255, 0);
	
	int realX;
	if (ship->ReferMainWeaponCD() >= ship->ReferMainWeaponCoolDownTime())
		realX = USER_INTERFACE_POSITION::SHOOT_CD_MAIN_SIZE_X;
	else
		realX = (int)(((double)ship->ReferMainWeaponCD() /
		(double)ship->ReferMainWeaponCoolDownTime())*
			USER_INTERFACE_POSITION::SHOOT_CD_MAIN_SIZE_X);

	DrawBox(
		(int)(USER_INTERFACE_POSITION::SHOOT_CD_MAIN_X * Screen::SCREEN_X),
		(int)(USER_INTERFACE_POSITION::SHOOT_CD_MAIN_Z * Screen::SCREEN_Z),
		(int)(USER_INTERFACE_POSITION::SHOOT_CD_MAIN_X * Screen::SCREEN_X) +
		realX,
		(int)(USER_INTERFACE_POSITION::SHOOT_CD_MAIN_Z * Screen::SCREEN_Z) +
		(int)USER_INTERFACE_POSITION::SHOOT_CD_MAIN_SIZE_Z,
		Cr, TRUE
	);
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
		Screen::SCREEN_X / 2 - (int)mapPaperSize + (int)realX - 3,
		Screen::SCREEN_Z - (int)(((1.2 * (int)mapPaperSize) - realZ)),
		Screen::SCREEN_X / 2 - (int)mapPaperSize + (int)realX + 3,
		Screen::SCREEN_Z - (int)(((1.2 * (int)mapPaperSize) - realZ) - 4),
		realCr,TRUE);
}