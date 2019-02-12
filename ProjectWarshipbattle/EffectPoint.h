#pragma once
#include"Effect.h"
#include"DxLib.h"

class EffectPoint
{
public:
	EffectPoint();
	~EffectPoint();
	
	Effect NewEffect(double r,double s,double x, double z);

	void InifCoordinate(double RCX,double RCZ, bool MA, int CT,int MACPF,
		bool Spread,double ZoomMutliple,double ZoomRate);

	void Inif(int ET, int *Handle);
	void TestDraw(double r, double s, double x, double CX, double CZ);

private:
	double relativeCoordX;
	double relativeCoordZ;
	
	int *graphHandle;

	int effectType;
	int maxAmountCreatePerFrame;

	bool movable;
	int continueTime;

	bool spread;
	double zoomMutliple;
	double zoomRate;
};

