#include "EffectPoint.h"

EffectPoint::EffectPoint()
{
}

EffectPoint::~EffectPoint()
{
}

Effect EffectPoint::NewEffect(double r, double s, double x, double z) {
	double newX = relativeCoordX + x;
	double newZ = relativeCoordZ + z; 
	double realX;
	double realZ;
	realX = cos(r) * newX + sin(r) * newZ;
	realZ = cos(r) * newZ + sin(r) * newX;
	Effect E(movable,continueTime,r,r,0,s,realX,realZ,graphHandle);
	return E;
}

void EffectPoint::Inif(double RCX, double RCZ, int ET,
	int MACPF, bool MA, int CT,int *Handle) {
	relativeCoordX = RCX;
	relativeCoordZ = RCZ;
	effectType = ET;
	maxAmountCreatePerFrame = MACPF;
	movable = MA;
	continueTime = CT;
	
}