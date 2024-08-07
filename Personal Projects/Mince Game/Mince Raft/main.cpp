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
#include "raylib.h"

int main()
{
	//InitWindow(800, 600, "Mince Game");
	int screenWidth = 800;
	int screenHeight = 450;
	raylib::Color textColor = raylib::Color::LightGray();
	raylib::Window window(screenWidth, screenHeight, "Tank");

	SetTargetFPS(60);

	/*
	Texture2D list
	*/

	/*
	root(?)
	*/

	/*
	Specific Game Objects
	*/

	while (!WindowShouldClose())
	{
		float deltaTime = window.GetFramTime();
		//Update(deltaTime);

		BeginDrawing();
		{
			ClearBackground(BLACK);
		}
		EndDrawing();
	}
	CloseWindow();
	return 0;
}