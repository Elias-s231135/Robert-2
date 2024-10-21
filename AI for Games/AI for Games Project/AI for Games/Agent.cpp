#include "Agent.h"

//using namespace AIForGames;

Agent::Agent(NodeMap* nodeMap, FiniteStateMachine stateMachine)
{
	Agent agent;

	agent.m_nodeMap = nodeMap;
}

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
	DrawCircle((int)GetPosition().x, (int)GetPosition().y, 8, m_color);
	//DrawCircle((int)GetNode()->position.x, (int)GetNode()->position.y, 4, {0, 255, 0, 255});
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

void FollowBehaviour::Update(Agent* agent, float deltaTime)
{
	// null check on targetAgent potentially?
	if (target = nullptr)
	{
		return;
	}

	target = agent->GetTarget();

	float dist = glm::distance(target->GetPosition(), lastTargetPosition);
	if (dist > agent->GetNodeMap()->GetCellSize())
	{
		lastTargetPosition = target->GetPosition();
		agent->GoTo(lastTargetPosition);
	}
}

void SelectorBehaviour::Update(Agent* agent, float deltaTime)
{
	if (glm::distance(agent->GetPosition(), agent->GetTarget()->GetPosition()) < agent->GetNodeMap()->GetCellSize() * 5)
	{
		SetBehaviour(m_b1, agent);
		agent->SetColor({ 255, 127, 127, 255 }); // salmon
	}
	else
	{
		SetBehaviour(m_b2, agent);
		agent->SetColor({ 127, 255, 255, 255 }); // light blue
	}
	m_selected->Update(agent, deltaTime);
}

void SelectorBehaviour::SetBehaviour(Behaviour* b, Agent* agent)
{
	if (m_selected != b)
	{
		m_selected = b;
		agent->Reset();
	}
}

State::~State()
{
	for (Behaviour* b : m_behaviours)
	{
		delete b;
	}

	for (Transition t : m_transitions)
	{
		delete t.condition;
	}
}

void State::Enter(Agent* agent)
{
}

void State::Update(Agent* agent, float deltaTime)
{
	for (Behaviour* b : m_behaviours)
	{
		b->Update(agent, deltaTime);
	}
}

void State::Exit(Agent* agent)
{
}

void State::AddTransition(Condition* m_condition, State* m_state)
{
	Transition transition;
	transition.condition = m_condition;
	transition.targetState = m_state;
}

FiniteStateMachine::~FiniteStateMachine()
{
	for (State* s : m_states)
	{
		delete s;
	}

}

void FiniteStateMachine::Update(Agent* agent, float deltaTime)
{
	State* newState = nullptr;

	for (State::Transition t : m_currentState->GetTransitions())
	{
		if (t.condition->IsTrue(agent))
		{
			newState = t.targetState;
		}
	}

	if (newState != nullptr && newState != m_currentState)
	{
		m_currentState->Exit(agent);
		m_currentState = newState;
		m_currentState->Enter(agent);
	}

	m_currentState->Update(agent, deltaTime);
}

void FiniteStateMachine::AddState(State* state)
{
	FiniteStateMachine stateMachine;

	stateMachine.m_currentState = state;
}

bool DistanceCondition::IsTrue(Agent* agent)
{
	return (glm::distance(agent->GetPosition(), agent->GetTarget()->GetPosition()) < m_distance) == m_lessThan;
}
