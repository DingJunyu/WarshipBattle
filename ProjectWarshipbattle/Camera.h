#pragma once
class Camera
{
public:
	Camera();
	~Camera();

	//�J�������W�₢���킹
	double ReferCameraX;
	double ReferCameraZ;

	//�f�[�^�ݒu�֐�
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

