#include "Player.h"
#include <iostream>


Player::Player()
{
}

Player::Player(const char* name)
{
}

Player::Player(int a_max_ammo, int a_max_health)
{
}

Player::Player(float x, float y)
{
}

Player::Player(Player& a_player)
{
}

int main()
{
	Player p1(100, 100); //a
	Player p2(25.f, 16.f); //b
	Player p3(p1); //c
	Player p4("Jerry"); //d
	Player p5; //e
}
