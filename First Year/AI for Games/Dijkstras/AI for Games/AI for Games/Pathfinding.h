#pragma once
#include <glm/glm.hpp>
#include <vector>

namespace AIForGames
{
	struct Node;

	struct Edge
	{
		Node* target;
		float cost;

		Edge()
		{
			target = nullptr;
			cost = 0;
		}

		Edge(Node* _target, float _cost) : target(_target), cost(_cost) {}
	};

	struct Node
	{
		glm::vec2 position;
		std::vector<Edge> connections;

		float gScore = 0;
		Node* previous = nullptr;

		Node(float x, float y) 
		{
			position = glm::vec2(x, y); 
		}

		void ConnectTo(Node* other, float cost)
		{
			connections.push_back(Edge(other, cost));
		}


	};

}

class Pathfinding
{
};

