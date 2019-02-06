#pragma once
#include"Effect.h"

class EffectPoint
{
public:
	EffectPoint();
	~EffectPoint();
	
	Effect NewEffect(double r,double s,double x, double z);

private:
	double relativeCoordX;
	double relativeCoordZ;
	
	int effectType;
	int maxAmountCreatePerFrame;

	bool movable;
	int continueTime;
	
};

