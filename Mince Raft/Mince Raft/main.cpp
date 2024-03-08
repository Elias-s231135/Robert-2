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

int main()
{
	Game* minceRaft = new Game();

	while (true)
	{
		minceRaft->Run();
	}
}