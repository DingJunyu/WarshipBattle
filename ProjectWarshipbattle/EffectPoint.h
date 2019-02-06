#pragma once
class EffectPoint
{
public:
	EffectPoint();
	~EffectPoint();

private:
	double relativeCoordX;
	double relativeCoordZ;
	
	int effectType;
	int maxAmountCreatePerFrame;
};

