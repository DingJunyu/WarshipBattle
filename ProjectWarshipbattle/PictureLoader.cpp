#include "PictureLoader.h"

PictureLoader::~PictureLoader()
{
}

void PictureLoader::MemorySecure() {
	
	battleCruiserHandle
		= new int *[COUNT_OF_EVERYTYPE::BATTLE_CRUSIER_TYPE_COUNT];
	for (int i = 0;
		i < COUNT_OF_EVERYTYPE::BATTLE_CRUSIER_TYPE_COUNT;
		i++) {
		battleCruiserHandle[i] 
			= new int [SerialNumberOfShipHandle::ARRAY_SIZE];
	}

	//ボタン
	buttonHandle = new int[ButtonEvent::BUTTON_AMOUNT];
	buttonPressedHandle = new int[ButtonEvent::BUTTON_AMOUNT];
}

void PictureLoader::FreeMemory() {
	for (int i = 0;
		i < COUNT_OF_EVERYTYPE::BATTLE_CRUSIER_TYPE_COUNT;
		i++) {
		delete[] battleCruiserHandle[i];
	}
	delete[] battleCruiserHandle;

	//ボタン
	delete[] buttonHandle;
	delete[] buttonPressedHandle;
}

void PictureLoader::LoadPicture() {
	/*ロード戦闘巡洋艦*/
	battleCruiserHandle[0][SerialNumberOfShipHandle::SHIP_HANDLE] =
	LoadGraph(
	"GraphicData/Ship_TopView/BattleCrusier/BattleCrusier_TopView_00_Lvtzow.png");
	GetGraphSize(battleCruiserHandle[0][SerialNumberOfShipHandle::SHIP_HANDLE],
		&shipSizeX, &shipSizeZ);
	battleCruiserHandle[0][SerialNumberOfShipHandle::SHIP_SHADOW_HANDLE] =
	LoadGraph(
	"GraphicData/Ship_Shadow/BattleCrusier/BattleCrusier_Shadow_01_Lvtzow.png");

	/*海*/
	mapHandle =
	LoadGraph("GraphicData/Sea/Sea.jpg");
	GetGraphSize(mapHandle, &mapX, &mapZ);

	/*UI*/
	matHandle = LoadGraph(
	"GraphicData/User_Interface/UI_Mat.jpg");
	GetGraphSize(matHandle, &matHandleX, &matHandleZ);
	shipCardMatHandle = LoadGraph(
	"GraphicData/User_Interface/Ship_Card_Mat.jpg");
	GetGraphSize(shipCardMatHandle, &shipCardMatHandleX, &shipCardMatHandleZ);

	/*ミニマップ*/
	miniMapMatHandle = LoadGraph(
	"GraphicData/User_Interface/MiniMap_Mat.jpg");
	miniMapPaperHandle = LoadGraph(
	"GraphicData/User_Interface/MiniMap_Paper.jpg");

	/*エフェクト*/
	bubbleHandle = LoadGraph(
	"GraphicData/Effect/Bubble.png");
	smokeHandle = LoadGraph(
	"GraphicData/Effect/Smoke.png");

	//ボタン
	//メインメニュー部分
	buttonHandle[ButtonEvent::NEW_GAME] = LoadGraph(
	"GraphicData/Button/Button_NewGame.png");
	buttonPressedHandle[ButtonEvent::NEW_GAME] = LoadGraph(
	"GraphicData/Button/Button_Pressed_NewGame.png");
	buttonHandle[ButtonEvent::CONTINUE_GAME] = LoadGraph(
	"GraphicData/Button/Button_ContinueGame.png");
	buttonPressedHandle[ButtonEvent::CONTINUE_GAME] = LoadGraph(
	"GraphicData/Button/Button_Pressed_ContinueGame.png");
	buttonHandle[ButtonEvent::LOAD_GAME] = LoadGraph(
	"GraphicData/Button/Button_LoadGame.png");
	buttonPressedHandle[ButtonEvent::LOAD_GAME] = LoadGraph(
	"GraphicData/Button/Button_Pressed_LoadGame.png");
	buttonHandle[ButtonEvent::OPTION] = LoadGraph(
	"GraphicData/Button/Button_Option.png");
	buttonPressedHandle[ButtonEvent::OPTION] = LoadGraph(
	"GraphicData/Button/Button_Pressed_Option.png");
	buttonHandle[ButtonEvent::GAME_OVER] = LoadGraph(
	"GraphicData/Button/Button_EndGame.png");
	buttonPressedHandle[ButtonEvent::GAME_OVER] = LoadGraph(
	"GraphicData/Button/Button_Pressed_EndGame.png");

	//タイトル関係
	title = LoadGraph(
	"GraphicData/Back_Ground/Title.png");
	pressedToStart = LoadGraph(
	"GraphicData/Back_Ground/Press_To_Start.png");
	pressedToStartDown = LoadGraph(
	"GraphicData/Back_Ground/Press_To_Start_Down.png");
	backGround = LoadGraph(
	"GraphicData/Back_Ground/Title_MainMenu_BackGround.jpg");

}

void PictureLoader::FreePicture() {
	/*戦艦*/
	for (int i = 0;
		i < COUNT_OF_EVERYTYPE::BATTLE_CRUSIER_TYPE_COUNT;
		i++) {
		DeleteGraph(
			battleCruiserHandle[i][SerialNumberOfShipHandle::SHIP_HANDLE]);
		DeleteGraph(
			battleCruiserHandle[i][SerialNumberOfShipHandle::SHIP_SHADOW_HANDLE]);
	}
	/*ボタン*/
	for (int i = 0; i < ButtonEvent::BUTTON_AMOUNT; i++) {
		DeleteGraph(buttonHandle[i]);
		DeleteGraph(buttonPressedHandle[i]);
	}
	/*マップ*/
	DeleteGraph(mapHandle);
	/*UI*/
	DeleteGraph(matHandle);
	DeleteGraph(shipCardMatHandle);
	DeleteGraph(miniMapMatHandle);
	DeleteGraph(miniMapPaperHandle);
	/*エフェクト*/
	DeleteGraph(bubbleHandle);
	DeleteGraph(smokeHandle);
}