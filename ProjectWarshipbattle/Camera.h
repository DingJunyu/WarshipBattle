#pragma once
#include"DefinedData.h"
#include"IncludeForAll.h"
const double ZOOM_RATE = 1.0f;
class Camera
{
public:
	Camera(int CT): cameraType(CT) {}
	~Camera();

	//カメラ座標問い合わせ
	double ReferCameraX() { return cameraX; }
	double ReferCameraZ() { return cameraZ; }
	double ReferRealCameraX() { return realCameraX; }
	double ReferRealCameraZ() { return realCameraZ; }
	double ReferPrintOutX(double PS) { return fmod(cameraX, PS); }
	double ReferPrintOutZ(double PS) { return fmod(cameraZ, PS); }

	void SetCameraX(double CX) { cameraX = CX; }
	void SetCameraZ(double CZ) { cameraZ = CZ; }

	//データ設置関数
	double SetScreenSizeX(double SSX) { screenSizeX = SSX; }
	double SetScreenSizeZ(double SSZ) { screenSizeZ = SSZ; }
	double SetMapSizeX(double MSX) { mapSizeX = MSX; }
	double SetMapSizeY(double MSZ) { mapSIzeZ = MSZ; }

	//カメラ座標設定
	void GetXZ(double X, double Z) { 
		GetX(X); GetZ(Z);
		realCameraX = cameraX - Screen::SCREEN_X / 2;
		realCameraZ = cameraZ - Screen::SCREEN_Z / 2;
	}
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

