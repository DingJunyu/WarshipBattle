#include "EffectPoint.h"

EffectPoint::EffectPoint()
{
}

EffectPoint::~EffectPoint()
{
}

Effect EffectPoint::NewEffect(double r, double s, double x, double z) {
	double newX = relativeCoordX;
	double newZ = relativeCoordZ; 
	double realX;
	double realZ;
	realX = cos(r) * newX + sin(r) * newZ + x;
	realZ = cos(r) * newZ + sin(r) * newX + z;
	Effect E(movable,continueTime,r,r,0,s,realX,realZ,graphHandle,
		spread,zoomMutliple, zoomRate);
	return E;
}

void EffectPoint::InifCoordinate(double RCX, double RCZ, bool MA, int CT,
	int MACPF,bool Spread, double ZoomMutliple,double ZoomRate) {
	relativeCoordX = RCX;
	relativeCoordZ = RCZ;
	movable = MA;
	continueTime = CT;
	maxAmountCreatePerFrame = MACPF;
	spread = Spread;
	zoomMutliple = ZoomMutliple;
	zoomRate = ZoomRate;
}


void EffectPoint::Inif(int ET, int *Handle) {
	effectType = ET;
	graphHandle = Handle;
}