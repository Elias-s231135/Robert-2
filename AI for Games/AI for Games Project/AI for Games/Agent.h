#pragma once
#include "PathAgent.h"

class Behaviour;

class FiniteStateMachine;

class Agent
{
public:
	Agent() {}
	Agent(NodeMap* _nodeMap, Behaviour* _behaviour); /*: m_current(_behaviour), m_nodeMap(_nodeMap), m_color() {}*/
	
	//Agent(NodeMap* nodeMap, FiniteStateMachine* stateMachine);

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

	void SetTarget(Agent* agent) { m_targetAgent = agent; }

	Agent* GetTarget() { return m_targetAgent; }

	NodeMap* GetNodeMap() { return m_nodeMap; }

	float GetCellSize() { return m_nodeMap->GetCellSize(); }

	void SetColor(Color color) { m_color = color; }

	void Reset() { m_pathAgent.GetPath().clear(); }

private:
	PathAgent m_pathAgent;
	Behaviour* m_current = nullptr;
	NodeMap* m_nodeMap = nullptr;
	Color m_color;
	Agent* m_targetAgent = nullptr;
};

class Behaviour
{
public:
	virtual void Enter(Agent* agent) {}
	virtual void Update(Agent* agent, float deltaTime) = 0;
	virtual void Exit(Agent* agent) {}
};

class GoToPointBehaviour : public Behaviour
{
public:
	virtual void Update(Agent* agent, float deltaTime);
};

class WanderBehaviour : public Behaviour
{
public:
	virtual void Enter(Agent* agent);
	virtual void Update(Agent* agent, float deltaTime);
};

class FollowBehaviour : public Behaviour
{
public:
	virtual void Enter(Agent* agent);
	virtual void Update(Agent* agent, float deltaTime);

	Agent* GetTarget() { return target; }

private:
	Agent* target;
	glm::vec2 lastTargetPosition;
};

class SelectorBehaviour : public Behaviour
{
private:
	Behaviour* m_b1;
	Behaviour* m_b2;
	Behaviour* m_selected;

public:
	SelectorBehaviour(Behaviour* b1, Behaviour* b2) : m_b1(b1), m_b2(b2) {}
	virtual void Update(Agent* agent, float deltaTime);

	void SetBehaviour(Behaviour* b, Agent* agent);
};

class Condition
{
public:
	virtual bool IsTrue(Agent* agent) = 0;
};

class State
{
public:
	struct Transition
	{
		Condition* condition;
		State* targetState;
	};

private:
	std::vector<Behaviour*> m_behaviours;
	std::vector<Transition> m_transitions;

public:
	State();
	State(Behaviour* behaviour) { m_behaviours.push_back(behaviour); }
	~State();

	std::vector<Transition> GetTransitions() { return m_transitions; }

	virtual void Enter(Agent* agent);
	virtual void Update(Agent* agent, float deltaTime);
	virtual void Exit(Agent* agent);

	void AddTransition(Condition* condition, State* state);
};


class FiniteStateMachine : public Behaviour
{
private:
	std::vector<State*> m_states;

	State* m_currentState;
	State* m_newState;

public:
	FiniteStateMachine(State* s) : m_currentState(s), m_newState(nullptr) { }
	virtual ~FiniteStateMachine();

	virtual void Enter(Agent* agent)
	{
		m_currentState->Enter(agent);
	}

	void Update(Agent* agent, float deltaTime);

	void AddState(State* state);

	FiniteStateMachine() = default;
};

class DistanceCondition : public Condition
{
private:
	float m_distance;
	bool m_lessThan;

public:
	DistanceCondition(float d, bool lt) : m_distance(d), m_lessThan(lt) {}
	virtual bool IsTrue(Agent* agent);
};