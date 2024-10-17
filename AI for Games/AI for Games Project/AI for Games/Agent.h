#pragma once
#include "PathAgent.h"

class Behaviour;

class Agent
{
public:
	Agent() {}
	Agent(NodeMap* _nodeMap, Behaviour* _behaviour) : m_current(_behaviour), m_nodeMap(_nodeMap), m_color({ 255, 255, 0, 255 }) {}

	void Update(float deltaTime);
	void Draw();

	void GoTo(glm::vec2 point);

	void SetNode(Node* node) { m_pathAgent.SetNode(node); }
	Node* GetNode() { return m_pathAgent.GetNode(); }

	void SetSpeed(float _speed) { m_pathAgent.SetSpeed(_speed); }

	glm::vec2 GetPosition() { return m_pathAgent.GetPosition(); }

	/*void SetTarget(Agent* agent) { m_targetAgent = agent; }
	Agent* GetTarget() { return m_targetAgent; }*/

	void GoToNode(Node* node) { m_pathAgent.GoToNode(node); }

	std::vector<Node*> GetPath() { return m_pathAgent.GetPath(); }

	bool PathComplete();

	Node* GetRandomNode() { return m_nodeMap->GetRandomNode(); }

private:
	PathAgent m_pathAgent;
	Behaviour* m_current = nullptr;
	NodeMap* m_nodeMap = nullptr;
	Color m_color;
};

class Behaviour
{
public:
	virtual void Update(Agent* agent, float deltaTime) = 0;
};

class GoToPointBehaviour : public Behaviour
{
public:
	virtual void Update(Agent* agent, float deltaTime);
};

class WanderBehaviour : public Behaviour
{
public:
	virtual void Update(Agent* agent, float deltaTime);
};