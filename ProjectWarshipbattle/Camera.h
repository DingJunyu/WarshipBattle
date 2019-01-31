#pragma once
#include"DefinedData.h"
const double ZOOM_RATE = 1.0f;
class Camera
{
public:
	Camera(int CT): cameraType(CT),realCameraX(Screen::SCREEN_X/2),
		realCameraZ(Screen::SCREEN_Z/2)
		{
		/*TEST*/
		cameraX = 400;
		cameraZ = 200;
	}
	~Camera();

	//�J�������W�₢���킹
	double ReferCameraX() { return cameraX; }
	double ReferCameraZ() { return cameraZ; }

	void SetCameraX(double CX) { cameraX = CX; }
	void SetCameraZ(double CZ) { cameraZ = CZ; }

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

	const int realCameraX;
	const int realCameraZ;

	int cameraType;

	double mapSizeX;
	double mapSIzeZ;

	double screenSizeX;
	double screenSizeZ;

	double zoomRatio;
};

