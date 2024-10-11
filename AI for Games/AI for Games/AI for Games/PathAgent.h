#pragma once
#include "NodeMap.h"

using namespace AIForGames;

class PathAgent
{
private:
	glm::vec2 m_position;

	std::vector<Node*>m_path;
	int m_currentIndex;
	Node* m_currentNode;

	float m_speed;

public:
	void Update(float deltatime);
	void GoToNode(Node* node);
	void Draw();
};

