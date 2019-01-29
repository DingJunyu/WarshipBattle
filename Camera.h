#pragma once
const double ZOOM_RATE = 1.0f;
class Camera
{
public:
	Camera(int CT): cameraType(CT) {}
	~Camera();

	//�J�������W�₢���킹
	double ReferCameraX() { return cameraX; }
	double ReferCameraZ() { return cameraZ; }

	//�f�[�^�ݒu�֐�
	double SetScreenSizeX(double SSX) { screenSizeX = SSX; }
	double SetScreenSizeZ(double SSZ) { screenSizeZ = SSZ; }
	double SetMapSizeX(double MSX) { mapSizeX = MSX; }
	double SetMapSizeY(double MSZ) { mapSIzeZ = MSZ; }

	//�J�������W�ݒ�
	void GetXZ(int X, int Z) { GetX(X); GetZ(Z); }
	//�J�����{���ݒ�
	void ZoomIn() { zoomRatio += ZOOM_RATE; }
	void ZoomOut() { zoomRatio -= ZOOM_RATE; }
	//�J�����{���₢���킹
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

