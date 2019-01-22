#pragma once
class Camera
{
public:
	Camera();
	~Camera();

	//カメラ座標問い合わせ
	double ReferCameraX;
	double ReferCameraZ;

	//データ設置関数
	double SetScreenSizeX(double SSX) { screenSizeX = SSX; }
	double SetScreenSizeZ(double SSZ) { screenSizeZ = SSZ; }
	double SetMapSizeX(double MSX) { mapSizeX = MSX; }
	double SetMapSizeY(double MSZ) { mapSIzeZ = MSZ; }

private:
	double cameraX;
	double cameraZ;

	int CameraType;

	double mapSizeX;
	double mapSIzeZ;

	double screenSizeX;
	double screenSizeZ;
};

