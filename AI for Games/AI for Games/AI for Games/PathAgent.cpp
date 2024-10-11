#include "PathAgent.h"

void PathAgent::Update(float deltatime)
{
	if (m_path.empty())
	{
		return;
	}

	glm::vec2 vectorTwo = m_path[0]->position - m_currentNode->position;



	std::distance(m_currentNode, glm::normalize(m_path[0]->position))
}

void PathAgent::GoToNode(Node* node)
{
	m_path = NodeMap::DijkstrasSearch(m_currentNode, node);
	m_currentIndex = 0;
}

void PathAgent::Draw()
{
}
