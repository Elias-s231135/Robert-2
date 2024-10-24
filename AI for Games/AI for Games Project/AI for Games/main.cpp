#include "Pathfinding.h"
#include "NodeMap.h"
#include "PathAgent.h"
#include <string>
#include "raylib.h"
#include "Agent.h"

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
	Node* start = nodeMap.GetNode(1, 1);
	Node* end = nodeMap.GetNode(10, 2);
	std::vector<Node*> nodeMapPath = nodeMap.AStarSearch(start, end);
	Color lineColor = { 74, 65, 42, 255 };

	PathAgent pagent;
	pagent.SetNode(start);
	pagent.SetSpeed(128);

	Agent agent(&nodeMap, new GoToPointBehaviour());
	agent.SetNode(start);
	agent.SetSpeed(128);
	agent.SetColor({ 255, 255, 0, 255 });

	Agent agent2(&nodeMap, new WanderBehaviour());
	agent2.SetNode(nodeMap.GetRandomNode());
	agent2.SetSpeed(128);
	agent2.SetColor({ 255, 0, 0, 255 });

	DistanceCondition* closerThan3 = new DistanceCondition(3.0f * nodeMap.GetCellSize(), true);
	DistanceCondition* furtherThan7 = new DistanceCondition(7.0f * nodeMap.GetCellSize(), false);

	/*State* wanderState = new State(new WanderBehaviour());
	State* followState = new State(new FollowBehaviour());
	wanderState->AddTransition(closerThan5, followState);
	followState->AddTransition(furtherThan7, wanderState);*/

	//FiniteStateMachine* fsm = new FiniteStateMachine(wanderState);
	//fsm->AddState(wanderState);
	//fsm->AddState(followState);
	
	Action* wanderAction = new Action(new WanderBehaviour());
	Action* followAction = new Action(new FollowBehaviour());

	ABDecision* wanderFollow = new ABDecision(closerThan3, wanderAction, followAction);

	Agent agent3(&nodeMap, new DecisionBehaviour(wanderFollow));
	agent3.SetNode(nodeMap.GetRandomNode());
	agent3.SetTarget(&agent);
	agent3.SetSpeed(64);
	//agent3.SetColor({ 0, 0, 255, 255 });

	SetTargetFPS(60);
	//------------------
	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		float deltaTime = GetFrameTime();
		

		if (IsMouseButtonPressed(0))
		{
			Vector2 mousePos = GetMousePosition();
			end = nodeMap.GetClosestNode(glm::vec2(mousePos.x, mousePos.y));
			nodeMapPath = nodeMap.AStarSearch(start, end);
			agent.GoToNode(end);

			
		}

		//if (IsMouseButtonPressed(1))
		//{
		//	Vector2 mousePos = GetMousePosition();
		//	end = nodeMap.GetClosestNode(glm::vec2(mousePos.x, mousePos.y));
		//	nodeMapPath = nodeMap.DijkstrasSearch(start, end);
		//}

		// Update
		//----------------------------------------------------------------------------------
		// TODO: Update your variables here
		//----------------------------------------------------------------------------------
		//Drawing goes here
		BeginDrawing();

		ClearBackground(BLACK);

		nodeMap.Draw();
		nodeMap.DrawPath(agent.GetPath(), lineColor);

		agent.Update(deltaTime);
		agent.Draw();

		agent2.Update(deltaTime);
		agent2.Draw();

		agent3.Update(deltaTime);
		agent3.Draw();

		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------   
	CloseWindow();        // Close window and OpenGL context
	//--------------------------------------------------------------------------------------

	return 0;

	
}