#pragma once
enum ShipType {
	DESTROYER = 10001,
	LIGHT_CRUISER,
	HEAVEY_CRUISER,
	BATTLE_CRUISER,
	BATTLESHIP,
	AIRCRAFT_CARRIER,
	LIGHT_AIRCRAFT_CARRIER,
	CVE
};

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
	APPROACH,//どの級まで知る
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