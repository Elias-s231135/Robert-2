#pragma once

class Room;
class Player;
class String;

class Game
{
public:
	Game();
	~Game();

	void Run();
private:
	Room[3][3];
	Player*;
};