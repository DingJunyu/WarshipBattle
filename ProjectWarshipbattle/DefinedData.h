#pragma once
namespace Screen {
	const int SCREEN_X = 1280;
	const int SCREEN_Z = 720;
	const int COLOR = 32;
}

//�R���g���[���[�p�w�ߏW
enum CommandSerial {
	INCREASE_OUTPUT = 20001,
	DECREASE_OUTPUT,
	TURN_RIGHT,
	TURN_LEFT
};

//�D�^�̔ԍ�
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


//�J������ޔԍ�
enum CameraType {
	MAIN = 100,
	SHIP = 101,
	AMMO,
	TORPEDO,
	BOMB,
	PLANE
};

enum Discoverd {
	DISCOVERD = 0,//���O�܂Œm��
	APPROACH,//�ǂ̌^�܂Œm��
	DETECTED,//��ނ�m��
	UNDETECTED //�S���m��Ȃ�
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

/*�e��ނ̑D�̐�*/
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

/*�D�̔ԍ�*/
namespace ShipSerial {
	const int BATTLE_CRUSIER_LVWZOV = 4000;
}

/*���w&������`*/
namespace MathAndPhysics {
	const double GRAVITATIONAL_ACCELERATION = 9.80665;
	const int GRAVITATIONAL_ACCELERATION_INT = 10;
	const double MIN_AIR_RESISTANCE = 0.5;
	const double PI = 3.14159265358;
}