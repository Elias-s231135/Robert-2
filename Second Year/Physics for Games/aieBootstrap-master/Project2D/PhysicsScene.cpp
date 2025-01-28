#include "PhysicsScene.h"
#include "glm/glm.hpp"

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

		int actorCount = m_actors.size();

		for (int outer = 0; outer < actorCount - 1; outer++)
		{
			for (int inner = outer + 1; inner < actorCount; inner++)
			{
				PhysicsObject* object1 = m_actors[outer];
				PhysicsObject* object2 = m_actors[inner];

				sphere2Sphere(object1, object2);
			}
		}
	}
}

void PhysicsScene::Draw()
{
	for (auto pActor : m_actors)
	{
		pActor->Draw();
	}
}

bool PhysicsScene::sphere2Sphere(PhysicsObject* obj1, PhysicsObject* obj2)
{
	Sphere* sphere1 = dynamic_cast<Sphere*>(obj1);
	Sphere* sphere2 = dynamic_cast<Sphere*>(obj2);

	if (sphere1 != nullptr && sphere2 != nullptr)
	{
		glm::distance(sphere1->GetPosition(), sphere2->GetPosition()) ;
	}
}
