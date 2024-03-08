#include "Room.h"
#include "StringTester.h"
#include "Enemy.h"
#include "Item.h"
#include "LeftHandedMince.h"
#include "PointyMince.h"
#include "RightHandedMince.h"
#include "StickyMince.h"
#include "SturdyMince.h"
#include "CrabThatEatsMince.h"
#include "LeftHandedShopOwner.h"
#include "MincedMan.h"
#include "MinceMeister.h"
#include "RightHandedShopOwner.h"

Room::Room()
{
	item = nullptr;
	//describe = nullptr;
}


Room::~Room()
{
	delete item;
	delete enemy;
	//delete describe;
}

//void Room::SetUp(int typeOfEnemy, int typeOfItem, String desc)
//{
	/*
	{ 0, 1, 2},
	{10,11,12},
	{20,21,22},
	if (Room = 2)
	SetUp{int CrabThatEatsMince, int PointyMince, String "There is a crab try to eat mince, but it's too pointy"}
	else if (Room = 3)
	Setup{etc...}
	*/
	//if (Room = 0)
	//{
	//	this->enemy = None;
	//	this->item = ;
	//	this->describe = ;
	//}


	//if i == 0 && j == 0 (refernced to walktrhough project setup)
	//this->item = new PointyMince();
	//this->describe = new String("This room has a pointy mince)
	//this->Enemy = nullptr ,,,,, this->Enemy = new CrabThatEatsMince();
	//this->leavable = false;
	//this->roomConnections...(n/s/e/w/etc...)
//}

void Room::SetUp(int xPos, int yPos)
{
	// 00 01 02
	// 10 11 12
	// 20 21 22
	if (xPos == 0 && yPos == 0)
	{
		this->item = nullptr;
		this->enemy = nullptr;
		this->describe = "You are in the entrance of a cave. There is a faint odour, and you can hear squelching from deeper inside. \nYou can go south to go deeper, or east to leave.";
	}
	else if (xPos == 1 && yPos == 0)
	{
		this->item = nullptr;
		this->enemy = nullptr;
		this->describe = "You are at the shore. There's ocean to the north, but you can't go there without the mince raft. \nThere's a cave to the west, a rocky beach to the east, and woods to the south.";
	}
	else if (xPos == 2 && yPos == 0)
	{
		this->item = new PointyMince();
		this->enemy = new CrabThatEatsMince();
		this->describe = "You are at a rocky beack. There's a crab trying to eat mince, but it's too pointy. If you don't kill the crab, it may try to eat your raft. \nThere's a shop to the south, and the shore to the west.";
	}
	else if (xPos == 0 && yPos == 1)
	{
		this->item = nullptr;
		this->enemy = nullptr;
		this->describe = "You are deeper in the cave. The odour is identifiable as raw beef, and the squelching sound is louder. \nYou get the feeling you should have the rest of the raft prepared before going deeper. \nYou can go north to return to the entrance, or go south to go deeper.";
	}
	else if (xPos == 1 && yPos == 1)
	{
		this->item = nullptr;
		this->enemy = nullptr;
		this->describe = "You are in some woods. The trees could make a good boat, but you should stay focused. \nLittle light seeps through the canopy, and more is blocked by a towering fortress. You can also see a shop nearby. \nYou can go south to reach the fortress, east to reach the shop, or north to return to the shore.";
	}
	else if (xPos == 2 && yPos == 1)
	{
		this->item = new LeftHandedMince();
		this->enemy = new LeftHandedShopOwner();
		this->describe = "You are in a store. \n\"Hey! You can't be here, I just closed up! You must want to steal my Left-Handed Mince!\" \nThe Shopkeeper is angry at you, and won't let you leave.";
	}
	else if (xPos == 0 && yPos == 2)
	{
		this->item = new StickyMince();
		this->enemy = new MincedMan();
		this->describe = "You are at the deepest part of the cave. Your steps sound squishy, and the ground is spongey. The stench of raw beef is overpowering, but the squelching sound has stopped. \nAs you look around, you realise this deep part of the cave is all mince. \nAs you turn to leave, you find that your exit has been blocked. The Minced Man stands in your way.";
	}
	else if (xPos == 1 && yPos == 2)
	{
		this->item = new SturdyMince();
		this->enemy = new MinceMeister();
		this->describe = "You are in the fortress. It's made of a stone that looks shockingly similar to mince. \n \"Halt! You dare enter MY fortress? Clearly you expect a fight, and I shall deliver!\" \nThe Mince Meister blocks you from leaving.";
	}
	else if (xPos == 2 && yPos == 2)
	{
		this->item = new RightHandedMince();
		this->enemy = new RightHandedShopOwner();
		this->describe = "You are in another store. \n\"What?! You aren't allowed in my store yet, I haven't opened up for the day! You plot a theft of this Right-Handed Mince!\" \nThis Shop Owner is quite cross, and denies your attempts to exit.";
	}
	else
	{
		this->item = nullptr;
		this->enemy = nullptr;
		this->describe = "Graham's domain. You shouldn't be here.";
	}
}

const void Room::Description()
{
	describe.WriteToConsole();
	//return void();
}
