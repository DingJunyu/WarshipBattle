#include "Plane.h"

Plane::~Plane()
{
}

void Plane::CalSpeed() {
	switch (status) {
	case FLYING:
	case FIGHTING:
	case TAKINGOFF:
	case LANDING:
	case FALLING:
	}
}

void Plane::SetMSWeightPower(double Ms, double W, double P) {
	maxSpeed = Ms;
	weight = W;
	power = P;
	acceleratedSpeed = power / weight;
}

void Plane::TakeOff(double X, double Z, double R) {
	NewCoordX(X);
	NewCoordZ(Z);
	SetRadianOnZ(R);
	takedOff = true;
	status = TAKINGOFF;
}