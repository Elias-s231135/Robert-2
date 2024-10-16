#pragma once
#include "NodeMap.h"

using namespace AIForGames;

class PathAgent
{
private:
	glm::vec2 m_position;

	std::vector<Node*>m_path;
	int m_currentIndex = 0;
	Node* m_currentNode = nullptr;

	float m_speed = 0;

public:
	void SetNode(Node* node);
	void SetSpeed(float speed);

	std::vector<Node*> GetPath();

	void Update(float deltatime);
	void GoToNode(Node* node);
	void Draw();
};

