#include "PathAgent.h"

void PathAgent::SetNode(Node* node)
{
	m_currentNode = node;
	m_position = m_currentNode->position;
}

void PathAgent::SetSpeed(float speed)
{
	m_speed = speed;
}

std::vector<Node*> PathAgent::GetPath()
{
	return m_path;
}

void PathAgent::Update(float deltatime)
{
	if (m_path.empty())
	{
		return;
	}

	glm::vec2 vectorTo = m_path[m_currentIndex]->position - m_position;

	float distance = glm::length(vectorTo);

	glm::vec2 direction =  glm::normalize(vectorTo);

	float remainingDistance = distance - m_speed * deltatime;

	if (remainingDistance > 0)
	{
		m_position += (m_speed * deltatime * direction);
	}
	else
	{
		m_currentNode = m_path[m_currentIndex];
		m_currentIndex++;

		if (m_currentIndex < m_path.size())
		{
			//m_position + (m_speed * deltatime * direction);

			vectorTo = m_path[m_currentIndex]->position - m_path[m_currentIndex - 1]->position;

			direction = glm::normalize(vectorTo);

			m_position = m_path[m_currentIndex - 1]->position + (((m_speed * deltatime) - distance) * direction);


		}
		else 
		{
			m_position = m_path.back()->position;
			m_currentNode = m_path.back();
			m_path.clear();
		}
	}
}

void PathAgent::GoToNode(Node* node)
{
	m_path = NodeMap::AStarSearch(m_currentNode, node);
	m_currentIndex = 0;
}

void PathAgent::Draw()
{
	DrawCircle((int)m_position.x, (int)m_position.y, 8, { 255, 255, 0, 255 });
	DrawCircle((int)m_currentNode->position.x, (int)m_currentNode->position.y, 4, { 0, 255, 0, 255 });
}

Node* PathAgent::GetNode()
{
	return m_currentNode;
}

glm::vec2 PathAgent::GetPosition()
{
	return m_position;
}
