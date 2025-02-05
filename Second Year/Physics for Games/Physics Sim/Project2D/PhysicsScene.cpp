#include "PhysicsScene.h"
#include "glm/geometric.hpp"
#include "Plane.h"
#include "Box.h"
#include "Sphere.h"
#include "RigidBody.h"


glm::vec2 PhysicsScene::m_gravity;

PhysicsScene::PhysicsScene() : m_timestep(0.01f)
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



bool PhysicsScene::plane2Plane(PhysicsObject* obj1, PhysicsObject* obj2)
{
	return false;
}

bool PhysicsScene::plane2Sphere(PhysicsObject* obj1, PhysicsObject* obj2)
{
	return sphere2Plane(obj2, obj1);
}

bool PhysicsScene::plane2Box(PhysicsObject* obj1, PhysicsObject* obj2)
{
	Plane* plane = dynamic_cast<Plane*>(obj1);
	Box* box = dynamic_cast<Box*>(obj2);

	if (box != nullptr && plane != nullptr)
	{
		int numContacts = 0;
		glm::vec2 contact(0, 0);
		float contactV = 0;

		glm::vec2 planeOrigin = plane->GetNormal() * plane->GetDistance();

		for (float x = -box->GetExtents().x; x < box->GetWidth(); x += box->GetWidth())
		{
			for (float y = -box->GetExtents().y; y < box->GetHeight(); y += box->GetHeight())
			{
				glm::vec2 p = box->GetPosition() + x * box->GetLocalX() + y * box->GetLocalY();
				float distFromPlane = glm::dot(p - planeOrigin, plane->GetNormal());

				glm::vec2 displacement = x * box->GetLocalX() + y * box->GetLocalY();
				glm::vec2 pointVelocity = box->GetVelocity() + box->GetAngularVelocity() * glm::vec2(-displacement.y, displacement.x);
				float velocityIntoPlane = glm::dot(pointVelocity, plane->GetNormal());

				if (distFromPlane < 0 && velocityIntoPlane <= 0)
				{
					numContacts++;
					contact += p;
					contactV += velocityIntoPlane;
				}
			}
		}

		if (numContacts > 0)
		{
			plane->ResolveCollision(box, contact / (float)numContacts);
			return true;
		}
	}

	return false;
}

bool PhysicsScene::sphere2Plane(PhysicsObject* obj1, PhysicsObject* obj2)
{
	Sphere* sphere = dynamic_cast<Sphere*>(obj1);
	Plane* plane = dynamic_cast<Plane*>(obj2);

	if (sphere != nullptr && plane != nullptr)
	{
		glm::vec2 collisionNormal = plane->GetNormal();
		float sphereToPlane = glm::dot(sphere->GetPosition(), plane->GetNormal()) - plane->GetDistance();
		
		glm::vec2 contact = sphere->GetPosition() + (collisionNormal * -sphere->GetRadius());

		float intersection = sphere->GetRadius() - sphereToPlane;
		float velocityOutOfPlane = glm::dot(sphere->GetVelocity(), plane->GetNormal());
		if (intersection > 0 && velocityOutOfPlane < 0)
		{
			sphere->ApplyForce(-sphere->GetVelocity() * sphere->GetMass(), contact);
			return true;
		}
	}
	return false;
}

bool PhysicsScene::sphere2Sphere(PhysicsObject* obj1, PhysicsObject* obj2)
{
	Sphere* sphere1 = dynamic_cast<Sphere*>(obj1);
	Sphere* sphere2 = dynamic_cast<Sphere*>(obj2);

	if (sphere1 != nullptr && sphere2 != nullptr)
	{
		/*if (glm::distance(sphere1->GetPosition(), sphere2->GetPosition()) < (sphere1->GetRadius() + sphere2->GetRadius()))
		{
			sphere1->ResolveCollision(sphere2, 0.5f * (sphere1->GetPosition() + 
				sphere2->GetPosition()));

			return true;
		}*/
		float dist = glm::distance(sphere1->GetPosition(), sphere2->GetPosition());
		float penetration = sphere1->GetRadius() + sphere2->GetRadius() - dist;
		if (penetration > 0)
		{
			sphere1->ResolveCollision(sphere2, (sphere1->GetPosition() + sphere2->GetPosition()) * 0.5f, nullptr, penetration);
			return true;
		}
	}
	return false;
}

bool PhysicsScene::sphere2Box(PhysicsObject* obj1, PhysicsObject* obj2)
{
	return box2Sphere(obj2, obj1);
}

bool PhysicsScene::box2Plane(PhysicsObject* obj1, PhysicsObject* obj2)
{
	return plane2Box(obj2, obj1);
}

bool PhysicsScene::box2Sphere(PhysicsObject* obj1, PhysicsObject* obj2)
{
	Box* box = dynamic_cast<Box*>(obj1);
	Sphere* sphere = dynamic_cast<Sphere*>(obj2);

	if (box != nullptr && sphere != nullptr)
	{
		glm::vec2 circlePosWorld = sphere->GetPosition() - 
			box->GetPosition();
		glm::vec2 circlePosBox = glm::vec2(glm::dot(circlePosWorld, 
			box->GetLocalX()), glm::dot(circlePosWorld, box->GetLocalY()));

		glm::vec2 closestPointOnBoxBox = circlePosBox;
		glm::vec2 extents = box->GetExtents();
		if (closestPointOnBoxBox.x < -extents.x) 
			closestPointOnBoxBox.x = -extents.x;
		if (closestPointOnBoxBox.x > extents.x)
			closestPointOnBoxBox.x = extents.x;
		if (closestPointOnBoxBox.y < -extents.y)
			closestPointOnBoxBox.y = -extents.y;
		if (closestPointOnBoxBox.y > extents.y) 
			closestPointOnBoxBox.y = extents.y;

		glm::vec2 closestPointOnBoxWorld = box->GetPosition() + 
			closestPointOnBoxBox.x * box->GetLocalX() + 
			closestPointOnBoxBox.y * box->GetLocalY();
		
		glm::vec2 circleToBox = sphere->GetPosition() - 
			closestPointOnBoxWorld;
		float penetration = sphere->GetRadius() - glm::length(circleToBox);
		if (penetration > 0)
		{
			glm::vec2 direction = glm::normalize(circleToBox);
			glm::vec2 contact = closestPointOnBoxWorld;
			box->ResolveCollision(sphere, contact, &direction, penetration);
		}
	}
	return false;
}

bool PhysicsScene::box2Box(PhysicsObject* obj1, PhysicsObject* obj2)
{
	Box* box1 = dynamic_cast<Box*>(obj1);
	Box* box2 = dynamic_cast<Box*>(obj2);
	if (box1 != nullptr && box2 != nullptr)
	{
		glm::vec2 boxPos = box2->GetPosition() - box1->GetPosition();
		glm::vec2 norm(0, 0);
		glm::vec2 contact(0, 0);
		float pen = 0;
		int numContants = 0;
		box1->CheckBoxCorners(*box2, contact, numContants, pen, norm);
		if (box2->CheckBoxCorners(*box1, contact, numContants, pen, norm))
		{
			norm = -norm;
		}
		if (pen > 0)
		{
			box1->ResolveCollision(box2, contact / float(numContants), &norm, pen);
		}
		return true;
	}
	return false;
}

float PhysicsScene::GetTotalEnergy()
{
	float total = 0;
	for (auto it = m_actors.begin(); it != m_actors.end(); it++)
	{
		PhysicsObject* obj = *it;
		total += obj->GetEnergy();
	}

	return total;
}

void PhysicsScene::ApplyContactForces(RigidBody* body1, RigidBody* body2, glm::vec2 norm, float pen)
{
	float body2Mass = body2 ? body2->GetMass() : INT_MAX;

	float body1Factor = body2Mass / (body1->GetMass() + body2Mass);

	body1->SetPosition(body1->GetPosition() - body1Factor * norm * pen);
	if (body2)
		body2->SetPosition(body2->GetPosition() + (1 - body1Factor) * norm * pen);
}