#pragma once
const double ZOOM_RATE = 1.0f;
class Camera
{
public:
	Camera(int CT): cameraType(CT) {}
	~Camera();

	//カメラ座標問い合わせ
	double ReferCameraX() { return cameraX; }
	double ReferCameraZ() { return cameraZ; }

	//データ設置関数
	double SetScreenSizeX(double SSX) { screenSizeX = SSX; }
	double SetScreenSizeZ(double SSZ) { screenSizeZ = SSZ; }
	double SetMapSizeX(double MSX) { mapSizeX = MSX; }
	double SetMapSizeY(double MSZ) { mapSIzeZ = MSZ; }

	//カメラ座標設定
	void GetXZ(int X, int Z) { GetX(X); GetZ(Z); }
	//カメラ倍率設定
	void ZoomIn() { zoomRatio += ZOOM_RATE; }
	void ZoomOut() { zoomRatio -= ZOOM_RATE; }
	//カメラ倍率問い合わせ
	double ReferZoomRatio() { return zoomRatio; }

private:
	void GetX(int X) { cameraX = X; }
	void GetZ(int Z) { cameraZ = Z; }

	double cameraX;
	double cameraZ;

	int cameraType;

	double mapSizeX;
	double mapSIzeZ;

	double screenSizeX;
	double screenSizeZ;

	double zoomRatio;
};

