#include <iostream>
#include "Game.h"
#include "StringTester.h"
#include "Enemy.h"
#include "Item.h"
#include "Player.h"
#include "Room.h"
#include "Spells.h"
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

using namespace std;

Game::Game()
{
	for (int x = 0; x < 3; x++)
	{
		for (int y = 0; y < 3; y++)
		{
			map[x][y].SetUp(x, y);
		}
	}
}

Game::~Game()
{

}

void Game::Run()
{
	map[xPos][yPos].Description();

	cout << "What will you do? (go <direction> / use <item> / inspect <item> |or| <enemy> / cast <spell> <enemy>)" << endl;

	String uInput;

	uInput.ReadFromConsole();

	uInput.ToLower();

	switch (uInput.CharacterAt(0))
	{
	case'g': // player attempting to go somewhere
		if (uInput.Find("go") != -1)
		{
			if (uInput.Find("north") != -1)
			{
				AttemptToGo('n');
			}
			else if (uInput.Find("east") != -1)
			{
				AttemptToGo('e');
			}
			else if (uInput.Find("south") != -1)
			{
				AttemptToGo('s');
			}
			else if (uInput.Find("west") != -1)
			{
				AttemptToGo('w');
			}
			else
			{
				cout << "Couldn't go there." << endl;
			}
		}
		break;
	case 'u': //Player attempting to use
		if (uInput.Find("use") != -1)
		{
			if (uInput.Find("use") != -1)
			{
				AttemptToUse(l);
			}
		}
	}
}

void Game::AttemptToGo(char c)
{
	switch (c)
	{
	case 'n':
		if (yPos >= 1)
		{
			yPos--;
			cout << "You went north." << endl;

		}
		else
		{
			cout << "You can't go there." << endl;
		}
		break;
	case 'e':
		if (xPos <= 1)
		{
			xPos++;
			cout << "You went east." << endl;
		}
		else
		{
			cout << "You can't go there." << endl;
		}
		break;
	case 's':
		if (yPos <= 1)
		{
			yPos++;
			cout << "You went south." << endl;
		}
		else
		{
			cout << "You can't go there." << endl;
		}
		break;
	case 'w':
		if (xPos >= 1)
		{
			xPos--;
			cout << "You went west." << endl;
		}
		else
		{
			cout << "You can't go there.";
		}
		break;
	}
}

void Game::AttemptToUse(char c)
{
	switch (c)
	{
	case 'l':
	{

	}
	}
}

void Game::AttemptToInspect(char c)
{
}

void Game::AttemptToCast(char c)
{
}
