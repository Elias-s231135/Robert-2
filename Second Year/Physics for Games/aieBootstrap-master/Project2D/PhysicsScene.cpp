#include "PhysicsScene.h"
#include "glm/glm.hpp"

PhysicsScene::PhysicsScene() : m_timestep(0.01f), m_gravity(glm::vec2(0, 0))
{
	SetTimestep(0.01f), SetGravity(glm::vec2(0, 0));
}

PhysicsScene::~PhysicsScene()
{
	for (auto pActor : m_actors)
	{
		delete pActor;
	}
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

typedef bool(*fn)(PhysicsObject*, PhysicsObject*);

static fn collisionFunctionArray[] =
{
	PhysicsScene::plane2Plane, PhysicsScene::plane2Sphere,
	PhysicsScene::sphere2SPlane, PhysicsScene::sphere2Sphere,
};

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
				int shapeId1 = object1->GetShapeType();
				int shapeId2 = object2->GetShapeType();

				int functionIdx = (shapeId1 * SHAPE_COUNT) + shapeId2;
				fn collisionFunctionPtr = collisionFunctionArray[functionIdx];
				if (collisionFunctionPtr != nullptr)
				{
					collisionFunctionPtr(object1, object2);
				}
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
		if (glm::distance(sphere1->GetPosition(), sphere2->GetPosition()) < (sphere1->GetRadius() + sphere2->GetRadius()))
		{
			sphere1->SetVelocity(glm::vec2(0, 0));
			sphere2->SetVelocity(glm::vec2(0, 0));

			return true;
		}
	}
}
