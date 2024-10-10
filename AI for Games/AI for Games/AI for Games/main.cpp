#include "Pathfinding.h"
#include "NodeMap.h"
#include <string>
#include "raylib.h"



using namespace AIForGames;

int main()
{

	std::vector<std::string> asciiMap;
	asciiMap.push_back("000000000000");
	asciiMap.push_back("010111011100");
	asciiMap.push_back("010101110110");
	asciiMap.push_back("010100000000");
	asciiMap.push_back("010111111110");
	asciiMap.push_back("010000001000");
	asciiMap.push_back("011111111110");
	asciiMap.push_back("000000000000");

	int screenWidth = 0;// 00;
	int screenHeight = 0;//450;
	int cellSize = 48;
	screenWidth = asciiMap[0].length() * cellSize;
	screenHeight = asciiMap.size() * cellSize;


	InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

	NodeMap nodeMap;

	nodeMap.Initialise(asciiMap, 48);

	SetTargetFPS(60);
	//------------------
	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		// Update
		//----------------------------------------------------------------------------------
		// TODO: Update your variables here
		//----------------------------------------------------------------------------------
		//Drawing goes here
		nodeMap.Draw();
		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------   
	CloseWindow();        // Close window and OpenGL context
	//--------------------------------------------------------------------------------------

	return 0;

	
}