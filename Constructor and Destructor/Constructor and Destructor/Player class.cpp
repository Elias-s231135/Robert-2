#pragma once

class Player
{
public:
	Player();
	Player(const char* name);
	Player(int a_max_ammo, int a_max_health);
	Player(float x, float y);
	Player(Player& a_player);

	float X, Y;
	int ammo;
	int max_ammo;
	int health;
	int max_health;
	char name[64];
};