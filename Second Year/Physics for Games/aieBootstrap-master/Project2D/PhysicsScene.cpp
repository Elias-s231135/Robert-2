#include "PhysicsScene.h"

PhysicsScene::PhysicsScene() : m_timestep(0.01f), m_gravity(glm::vec2(0, 0))
{
	SetTimestep(0.01f), SetGravity(glm::vec2(0, 0));
}

PhysicsScene::~PhysicsScene()
{
}

void PhysicsScene::RemoveActor(PhysicsObject* actor)
{
	for (auto it = m_actors.begin(); it != m_actors.end(); it++)
	{
		if (*it == actor)
		{
			m_actors.erase(it);
			break;
		}
	}
}

void PhysicsScene::Update(float dt)
{
	static float accumulatedTime = 0.0f;
	accumulatedTime += dt;

	while (accumulatedTime >= m_timestep)
	{
		for (auto pActor : m_actors)
		{
			pActor->FixedUpdate(m_gravity, m_timestep);
		}

		accumulatedTime -= m_timestep;
	}
}

void PhysicsScene::Draw()
{
	for (auto pActor : m_actors)
	{
		pActor->Draw();
	}
}