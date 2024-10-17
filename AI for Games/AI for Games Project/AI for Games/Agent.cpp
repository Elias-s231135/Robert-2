#include "Agent.h"

void Agent::Update(float deltaTime)
{
	if (m_current)
	{
		m_current->Update(this, deltaTime);
	}
	m_pathAgent.Update(deltaTime);
}

void Agent::Draw()
{
	DrawCircle((int)GetPosition().x, (int)GetPosition().y, 8, {255, 255, 0, 255});
	DrawCircle((int)GetNode()->position.x, (int)GetNode()->position.y, 4, {0, 255, 0, 255});
}

void Agent::GoTo(glm::vec2 point)
{
	Node* end = m_nodeMap->GetClosestNode(point);
	m_pathAgent.GoToNode(end);
}

bool Agent::PathComplete()
{
	return m_pathAgent.GetPath().empty();
}

void GoToPointBehaviour::Update(Agent* agent, float deltaTime)
{
	if (IsMouseButtonPressed(0))
	{
		Vector2 mousePos = GetMousePosition();
		agent->GoTo(glm::vec2(mousePos.x, mousePos.y));
	}
}

void WanderBehaviour::Update(Agent* agent, float deltaTime)
{
	if (agent->PathComplete())
	{
		agent->GoTo(agent->GetRandomNode()->position);
	}
}
