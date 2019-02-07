#pragma once
#include"Effect.h"

class EffectPoint
{
public:
	EffectPoint();
	~EffectPoint();
	
	Effect NewEffect(double r,double s,double x, double z);

	void Inif(double RCX,double RCZ,int ET,int MACPF,bool MA,int CT,
		int *Handle);

private:
	double relativeCoordX;
	double relativeCoordZ;
	
	int *graphHandle;

	int effectType;
	int maxAmountCreatePerFrame;

	bool movable;
	int continueTime;
	
};

