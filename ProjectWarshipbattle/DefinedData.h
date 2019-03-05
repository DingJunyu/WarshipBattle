#pragma once
namespace Screen {
	const int SCREEN_X = 1280;
	const int SCREEN_Z = 720;
	const int COLOR = 32;
}

//コントローラー用指令集
enum CommandSerial {
	NONE_COMMAND = -1,
	TEST_VIEW_ON = 0,
	INCREASE_OUTPUT = 1,
	DECREASE_OUTPUT,
	TURN_RIGHT,
	TURN_LEFT,
	TURN_RETURN,
	SHOOT
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

namespace BUTTON_POSITION {
	const double START_POSITION_ON_X = .2;
	const double NEW_GAME = .4;
	const double CONTINUE_GAME = .5;
	const double LOAD_GAME = .6;
	const double OPTION = .7;
	const double GAME_OVER = .8;
}

enum AmmoType {
	TYPE_COUNT = 4,
	SMALL_CALIBER = 0,
	MEDIUM_CALIBER,
	HEAVY_CALIBER,
	HUGE_CALIBER
};

enum ButtonEventForUserInterface {

};

namespace BUTTON_POSITION_UI {

}

enum MouseEventCollection {

};

enum IngameButtonEventCollection {

};

/*座標の保存方式はこんな風にしたほうがいいが、
時間上も問題があるので今回は挙げるだけで、
実際のゲームに使ってない*/
template <typename T>
struct Coordinate {
	T x;
	T y;
	T z;
};


struct FiringData {
	bool isThisMainWeapon;
	bool selected[50];
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
	const double GRAVITATIONAL_ACCELERATION = 0.00980665;
	const int GRAVITATIONAL_ACCELERATION_INT = 10;
	const double MIN_AIR_RESISTANCE = 0.5;
	const double PI = 3.14159265358;
}

namespace MapSize {
	const int xSize = 20000;
	const int zSize = 20000;
	const int safeZone = 1000;
}

