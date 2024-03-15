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
	player = new Player();

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
	delete player;
}

void Game::Run()
{
	map[xPos][yPos].Description();

	cout << "What will you do? (go <direction> / use <item> / inspect <item> |or| <character> / cast <spell>)" << endl;

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
			if (uInput.Find("left") != -1 && uInput.Find("mince") != -1)
			{
				AttemptToUse('l');
			}
			else if (uInput.Find("pointy") != -1 && uInput.Find("mince") != -1)
			{
				AttemptToUse('p');
			}
			else if (uInput.Find("right") != -1 && uInput.Find("mince") != -1)
			{
				AttemptToUse('r');
			}
			else if (uInput.Find("sticky") != -1 && uInput.Find("mince") != -1)
			{
				AttemptToUse('c');
			}
			else if (uInput.Find("sturdy") != -1 && uInput.Find("mince") != -1)
			{
				AttemptToUse('u');
			}
			else
			{
				cout << "Couldn't find that." << endl;
			}
		}
		break;
	case 'i': //Player attempting to inspect
		if (uInput.Find("inspect") != -1)
		{
			if (uInput.Find("left") != -1 && uInput.Find("mince") != -1)
			{
				AttemptToInspect('l');
			}
			else if (uInput.Find("pointy") != -1 && uInput.Find("mince") != -1)
			{
				AttemptToInspect('p');
			}
			else if (uInput.Find("right") != -1 && uInput.Find("mince") != -1)
			{
				AttemptToInspect('r');
			}
			else if (uInput.Find("sticky") != -1 && uInput.Find("mince") != -1)
			{
				AttemptToInspect('c');
			}
			else if (uInput.Find("sturdy") != -1 && uInput.Find("mince") != -1)
			{
				AttemptToInspect('u');
			}
			else if (uInput.Find("crab") != -1)
			{
				AttemptToInspect('a');
			}
			else if (uInput.Find("left") != -1 && uInput.Find("shop") != -1)
			{
				AttemptToInspect('e');
			}
			else if (uInput.Find("minced") != -1 && uInput.Find("man") != -1)
			{
				AttemptToInspect('d');
			}
			else if (uInput.Find("mince") != -1 && uInput.Find("meister") != -1)
			{
				AttemptToInspect('m');
			}
			else if (uInput.Find("right") != -1 && uInput.Find("shop") != -1)
			{
				AttemptToInspect('g');
			}
			else
			{
				cout << "Couldn't find that." << endl;
			}
		}
		break;
	case 'c': //player attempting to cast a spell
		if (uInput.Find("cast") != -1)
		{
			if (uInput.Find("expensive petroleum") != -1)
			{
				AttemptToCast('e');
			}
			else if (uInput.Find("friarball") != -1)
			{
				AttemptToCast('f');
			}
			else if (uInput.Find("graham") != -1)
			{
				AttemptToCast('g');
			}
			else if (uInput.Find("match") != -1)
			{
				AttemptToCast('m');
			}
			else if (uInput.Find("pocket sand") != -1)
			{
				AttemptToCast('p');
			}
			else if (uInput.Find("rock") != -1)
			{
				AttemptToCast('r');
			}
			else
			{
				cout << "You don't know that spell." << endl;
			}
		}
		break;
	}
}

void Game::AttemptToGo(char a)
{
	switch (a)
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

void Game::AttemptToUse(char b)
{
	switch (b)
	{
	case 'l':
	{
		LeftHandedMince* leftMince = dynamic_cast<LeftHandedMince*>(map[xPos][yPos].item);
		if (leftMince != nullptr)
		{
			leftMince->Use();
		}
		else
		{
			cout << "Couldn't find that item." << endl;
		}
		break;
	}
	case 'p':
	{
		PointyMince* pMince = dynamic_cast<PointyMince*>(map[xPos][yPos].item);
		if (pMince != nullptr)
		{
			pMince->Use();
		}
		else
		{
			cout << "Couldn't find that item." << endl;
		}
		break;
	}
	case 'r':
	{
		RightHandedMince* rightMince = dynamic_cast<RightHandedMince*>(map[xPos][yPos].item);
		if (rightMince != nullptr)
		{
			rightMince->Use();
		}
		else
		{
			cout << "Couldn't find that item." << endl;
		}
		break;
	}
	case 'c':
	{
		StickyMince* stickMince = dynamic_cast<StickyMince*>(map[xPos][yPos].item);
		if (stickMince != nullptr)
		{
			stickMince->Use();
		}
		else
		{
			cout << "Couldn't find that item." << endl;
		}
		break;
	}
	case 'u':
	{
		SturdyMince* toughMince = dynamic_cast<SturdyMince*>(map[xPos][yPos].item);
		if (toughMince != nullptr)
		{
			toughMince->Use();
		}
		else
		{
			cout << "Couldn't find that item." << endl;
		}
		break;
	}
	break;
	}
}

void Game::AttemptToInspect(char c)
{
	switch (c)
	{
	case 'l':
	{
		LeftHandedMince* leftMince = dynamic_cast<LeftHandedMince*>(map[xPos][yPos].item);
		if (leftMince != nullptr)
		{
			leftMince->Description();
		}
		else
		{
			cout << "Couldn't find that." << endl;
		}
		break;
	}
	case 'p':
	{
		PointyMince* pMince = dynamic_cast<PointyMince*>(map[xPos][yPos].item);
		if (pMince != nullptr)
		{
			pMince->Description();
		}
		else
		{
			cout << "Couldn't find that." << endl;
		}
		break;
	}
	case 'r':
	{
		RightHandedMince* rightMince = dynamic_cast<RightHandedMince*>(map[xPos][yPos].item);
		if (rightMince != nullptr)
		{
			rightMince->Description();
		}
		else
		{
			cout << "Couldn't find that." << endl;
		}
		break;
	}
	case 'c':
	{
		StickyMince* stickMince = dynamic_cast<StickyMince*>(map[xPos][yPos].item);
		if (stickMince != nullptr)
		{
			stickMince->Description();
		}
		else
		{
			cout << "Couldn't find that." << endl;
		}
		break;
	}
	case 'u':
	{
		SturdyMince* toughMince = dynamic_cast<SturdyMince*>(map[xPos][yPos].item);
		if (toughMince != nullptr)
		{
			toughMince->Description();
		}
		else
		{
			cout << "Couldn't find that." << endl;
		}
		break;
	}
	case 'a':
	{
		CrabThatEatsMince* crab = dynamic_cast<CrabThatEatsMince*>(map[xPos][yPos].enemy);
		if (crab != nullptr)
		{
			crab->Description();
		}
		else
		{
			cout << "Couldn't find that." << endl;
		}
		break;
	}
	case 'e':
	{
		LeftHandedShopOwner* leftShop = dynamic_cast<LeftHandedShopOwner*>(map[xPos][yPos].enemy);
		if (leftShop != nullptr)
		{
			leftShop->Description();
		}
		else
		{
			cout << "Couldn't find that." << endl;
		}
		break;
	}
	case 'd':
	{
		MincedMan* minced = dynamic_cast<MincedMan*>(map[xPos][yPos].enemy);
		if (minced != nullptr)
		{
			minced->Description();
		}
		else
		{
			cout << "Couldn't find that." << endl;
		}
		break;
	}
	case 'm':
	{
		MinceMeister* meister = dynamic_cast<MinceMeister*>(map[xPos][yPos].enemy);
		if (meister != nullptr)
		{
			meister->Description();
		}
		else
		{
			cout << "Couldn't find that." << endl;
		}
		break;
	}
	case 'g':
	{
		RightHandedShopOwner* rightShop = dynamic_cast<RightHandedShopOwner*>(map[xPos][yPos].enemy);
		if (rightShop != nullptr)
		{
			rightShop->Description();
		}
		else
		{
			cout << "Couldn't find that." << endl;
		}
		break;
	}
	break;
	}
}

void Game::AttemptToCast(char d)
{
	switch (d)
	{
	case 'e':
	{
		//FindSpell("graham");
		if (player->FindSpell(player->epSpell))		
		{
			player->epSpell.Cast();
		}
		else
		{
			cout << "You don't know that spell." << endl;
		}
	}
	case 'f':
	{
		if (player->FindSpell(player->fSpell))
		{
			player->fSpell.Cast();
		}
		else
		{
			cout << "You don't know that spell." << endl;
		}
	}
	case 'g':
	{
		if (player->FindSpell(player->gSpell))
		{
			player->gSpell.Cast();
		}
		else
		{
			cout << "You don't know that spell." << endl;
		}
	}
	case 'm':
	{
		if (player->FindSpell(player->mSpell))
		{
			player->mSpell.Cast();
		}
		else
		{
			cout << "You don't know that spell." << endl;
		}
	}
	case 'p':
	{
		if (player->FindSpell(player->pSpell))
		{
			player->pSpell.Cast();
		}
		else
		{
			cout << "You don't know that spell." << endl;
		}
	}
	case 'r':
	{
		if (player->FindSpell(player->rSpell))
		{
			player->rSpell.Cast();
		}
		else
		{
			cout << "You don't know that spell." << endl;
		}
	}
	break;
	}
}
