#pragma once
class AllMovableObjects
{
public:
	AllMovableObjects();
	~AllMovableObjects();


	double ReferCoordX() { return coordX; }
	double ReferCoordY() { return coordY; }
	bool ReferAlive() { return alive; }
	void NewCoordX(double X) { coordX = X; }
	void NewCoordY(double Y) { coordY = Y; }
	void Killed() { alive = false; }

private:
	double coordX;
	double coordY;

	bool alive;
};

