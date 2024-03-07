#include "Room.h"
#include "StringTester.h"

Room::Room()
{
	item = nullptr;
	describe = nullptr;
}


Room::~Room()
{
	delete item;
	delete describe;
}

void Room::SetUp(int typeOfEnemy, int typeOfItem, String desc)
{
	/*
	{ 0, 1, 2},
	{10,11,12},
	{20,21,22},
	if (Room = 2)
	SetUp{int CrabThatEatsMince, int PointyMince, String "There is a crab try to eat mince, but it's too pointy"}
	else if (Room = 3)
	Setup{etc...}
	*/
	if (Room = 0)
	{
		this->enemy = None;
		this->item = ;
		this->describe = 
	}


	//if i == 0 && j == 0 (refernced to walktrhough project setup)
	//this->item = new PointyMince();
	//this->describe = new String("This room has a pointy mince)
	//this->Enemy = nullptr ,,,,, this->Enemy = new CrabThatEatsMince();
	//this->leavable = false;
	//this->roomConnections...(n/s/e/w/etc...)
}

const void Room::Description()
{
	return void();
}
