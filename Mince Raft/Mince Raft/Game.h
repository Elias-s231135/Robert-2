#pragma once
#include "Room.h"

class Player;

class Game
{
public:
	Game();
	~Game();

	void Run();
private:

	/*int test[3][3] = {
		{1,2,3},
		{4,5,6},
		{7,8,9}
	};*/

	Room map[3][3];/* = {
		{'E', 1, 2},
		{10, 11, 12},
		{20, 21, 22}
};*/
	int xPos = 1;
	int yPos = 0;
	Player* player;

	void AttemptToGo(char c);
	void AttemptToUse(char c);
	void AttemptToInspect(char c);
	void AttemptToCast(char c);
};