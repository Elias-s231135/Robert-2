#pragma once

//class Player
//{
//public:
//	Player();
//	Player(const char* name);
//	Player(int a_max_ammo, int a_max_health);
//	Player(float x, float y);
//	Player(Player& a_player);
//
//	float X, Y;
//	int ammo;
//	int max_ammo;
//	int health;
//	int max_health;
//	char name[64];
//};

class Player
{
public:
	struct Bullet { float x, y; };

	Player(int max_ammo)
	{
		bullets = new Bullet[max_ammo];
		ammo = 0;
		health = 0;
		max_health = 100;
	}

	~Player(); // implement this

	int health;
	int max_health;
	int ammo;
	int max_ammo;
	Bullet* bullets;
};