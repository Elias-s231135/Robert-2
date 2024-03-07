#pragma once
#include "Room.h"

class Player;
class String;

class Game
{
public:
	Game();
	~Game();

	void Run();
private:
	Room map[3][3];
	Player* player;
};