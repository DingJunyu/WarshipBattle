#pragma once
#include"DefinedData.h"
const double ZOOM_RATE = 1.0f;
class Camera
{
public:
	Camera(int CT): cameraType(CT),realCameraX(Screen::SCREEN_X/2),
		realCameraZ(Screen::SCREEN_Z/2) {}
	~Camera();

	//カメラ座標問い合わせ
	double ReferCameraX() { return cameraX; }
	double ReferCameraZ() { return cameraZ; }
	double ReferRealCameraX() { return realCameraX; }
	double ReferRealCameraZ() { return realCameraZ; }
	double ReferPrintOutX() { return cameraX - Screen::SCREEN_X/2; }
	double ReferPrintOutZ() { return cameraZ - Screen::SCREEN_Z / 2; }

	void SetCameraX(double CX) { cameraX = CX; }
	void SetCameraZ(double CZ) { cameraZ = CZ; }

	//データ設置関数
	double SetScreenSizeX(double SSX) { screenSizeX = SSX; }
	double SetScreenSizeZ(double SSZ) { screenSizeZ = SSZ; }
	double SetMapSizeX(double MSX) { mapSizeX = MSX; }
	double SetMapSizeY(double MSZ) { mapSIzeZ = MSZ; }

	//カメラ座標設定
	void GetXZ(double X, double Z) { GetX(X); GetZ(Z); }
	//カメラ倍率設定
	void ZoomIn() { zoomRatio += ZOOM_RATE; }
	void ZoomOut() { zoomRatio -= ZOOM_RATE; }
	//カメラ倍率問い合わせ
	double ReferZoomRatio() { return zoomRatio; }

private:
	void GetX(double X) { cameraX = X; }
	void GetZ(double Z) { cameraZ = Z; }

	double cameraX;
	double cameraZ;

	double realCameraX;
	double realCameraZ;

	double printOutX;
	double printOutZ;

	int cameraType;

	double mapSizeX;
	double mapSIzeZ;

	double screenSizeX;
	double screenSizeZ;

	double zoomRatio;
};

