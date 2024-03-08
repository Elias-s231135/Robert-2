#pragma once
#include "StringTester.h"

class Item;
class Enemy;

class Room
{
public:
	Room();
	~Room();
	//void SetUp(int typeOfEnemy, int typeOfItem, String describe);
	void SetUp(int xPos, int yPos);
	const void Description();
public:
	Item* item;
	Enemy* enemy;
private:
	String describe;
};