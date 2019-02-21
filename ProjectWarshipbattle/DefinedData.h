#pragma once
namespace Screen {
	const int SCREEN_X = 1280;
	const int SCREEN_Z = 720;
	const int COLOR = 32;
}

//コントローラー用指令集
enum CommandSerial {
	TEST_VIEW_ON = 20000,
	INCREASE_OUTPUT = 20001,
	DECREASE_OUTPUT,
	TURN_RIGHT,
	TURN_LEFT,
	TURN_RETURN
};

//船型の番号
const int RESERVED_NUMBER_FOR_SHIPS = 1000;
enum ShipType {
	DESTROYER = 1,//1
	LIGHT_CRUISER,//2
	HEAVEY_CRUISER,//3
	BATTLE_CRUISER,//4
	BATTLESHIP,//5
	AIRCRAFT_CARRIER,//6
	LIGHT_AIRCRAFT_CARRIER,//7
	CVE//8
};


//カメラ種類番号
enum CameraType {
	MAIN = 100,
	SHIP = 101,
	AMMO,
	TORPEDO,
	BOMB,
	PLANE
};

enum Discoverd {
	DISCOVERD = 0,//名前まで知る
	APPROACH,//どの型まで知る
	DETECTED,//種類を知る
	UNDETECTED //全く知らない
};

enum PlaneType {
	FIGHTER = 201,
	BOMBER,
	ATTACKER
};

enum PlaneWeaponType {
	BOMB_PW = 301,
	TORPEDO_PW,
	MACHINE_GUN_PW
};

enum PlaneStatus {
	FLYING = 401,
	FIGHTING,
	TAKINGOFF,
	LANDING,
	FALLING,
	SPEEDUP,
	SPEEDDOWN
};

enum SerialNumberOfShipHandle {
	SHIP_HANDLE = 0,
	SHIP_SHADOW_HANDLE,
	SHIP_SIDEVIEW_HANDLE,
	SHIP_SINKING,
	ARRAY_SIZE = 20
};

enum SerialNumberOfMapObjectHandle {
	MO_HANDLE = 0,
	MO_MINI_VER_HANDLE,
	MO_SHADOW_HANDLE,
	MO_SIZE_X,
	MO_SIZE_Z
};

enum TypeOfEffect {
	EXPLOSION = 0,
	BUBBLE,
	SMOKE
};

enum TypeOfHord {
	LARGE,
	MEDIUM,
	SMALL
};

enum ButtonEvent {
	BUTTON_AMOUNT = 20,
	//メインメニューボタン集
	NEW_GAME = 0,
	CONTINUE_GAME,
	LOAD_GAME,
	OPTION,
	GAME_OVER
};

/*各種類の船の数*/
namespace COUNT_OF_EVERYTYPE {
	const int DESTROYER_TYPE_COUNT = 0;
	const int LIGHT_CRUSIER_TYPE_COUNT = 0;
	const int HEAVEY_CRUSIER_TYPE_COUNT = 0;
	const int BATTLE_CRUSIER_TYPE_COUNT = 1;
	const int BATTLESHIP_TYPE_COUNT = 0;
	const int AIRCRAFT_CARRIER_TYPE_COUNT = 0;
	const int LIGHT_AIRCRAFT_CARRIER_TYPE_COUNT = 0;
	const int CVE_TYPE_COUNT = 0;
}

/*船の番号*/
namespace ShipSerial {
	const int BATTLE_CRUSIER_LVWZOV = 4000;
}

/*数学&物理定義*/
namespace MathAndPhysics {
	const double GRAVITATIONAL_ACCELERATION = 9.80665;
	const int GRAVITATIONAL_ACCELERATION_INT = 10;
	const double MIN_AIR_RESISTANCE = 0.5;
	const double PI = 3.14159265358;
}

namespace MapSize {
	const int xSize = 20000;
	const int zSize = 20000;
	const int safeZone = 1000;
}

