#pragma once
class Morale
{
public:
	Morale();
	~Morale();

	void CountMainPartDamage() { mainPartDamageCount++; }

private:
	int morale;
	bool movable;
	int mainPartDamageCount;
	int subPartDamageCount;
};

