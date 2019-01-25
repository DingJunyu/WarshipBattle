#pragma once
class TeamDeathMatchControl
{
public:
	TeamDeathMatchControl();
	~TeamDeathMatchControl();

	bool GameOver();
	void DrawBoard();

private:
	int TeamACount;
	int TeamARemained;
	int TeamBCount;
	int TeamBRemained;


};

