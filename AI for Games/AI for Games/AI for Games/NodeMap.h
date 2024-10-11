#pragma once
#include <vector>
#include <string>
#include <iostream>
#include "Pathfinding.h"
#include "raylib.h"


using namespace AIForGames;

class NodeMap
{
	int m_width, m_height;
	float m_cellSize;

	Node** m_nodes;

public:
	//bool operator==(Node one, Node two) override;

	void Initialise(std::vector<std::string> asciiMap, int cellSize);
	
	Node* GetNode(int x, int y) { return m_nodes[x + m_width * y]; }

	void Draw();

	void DrawPath(std::vector<Node*> path, Color lineColor);

	static std::vector<Node*> DijkstrasSearch(Node* startNode, Node* endNode);
	
	Node* GetClosestNode(glm::vec2 worldPos);
};

