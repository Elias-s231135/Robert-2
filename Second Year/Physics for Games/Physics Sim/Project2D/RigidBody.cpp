#include "RigidBody.h"
#include "PhysicsScene.h"
#include "glm/geometric.hpp"

const float RigidBody::MIN_LINEAR_THRESHOLD = 0.1f;
const float RigidBody::MIN_ANGULAR_THRESHOLD = 0.1f;

RigidBody::RigidBody(ShapeType shapeID, glm::vec2 position, glm::vec2 velocity, float orientation, float mass)
	: PhysicsObject(shapeID)
{
	shapeID;

	m_position = position;

	m_velocity = velocity;

	m_orientation = orientation;

	m_mass = mass;

	m_angularVelocity = 0;

	m_linearDrag = 1.0;
	m_angularDrag = 1.0f;

	m_moment = 0;
}

RigidBody::~RigidBody()
{
}

void RigidBody::FixedUpdate(glm::vec2 gravity, float timestep)
{
	
	m_velocity -= m_velocity * m_linearDrag * timestep;
	m_position += m_velocity * timestep;
	ApplyForce(gravity * m_mass * timestep, glm::vec2(0, 0));

	m_angularVelocity -= m_angularVelocity * m_angularDrag * timestep;

	if (length(m_velocity) < MIN_LINEAR_THRESHOLD)
	{
		m_velocity = glm::vec2(0, 0);
	}
	if (abs(m_angularVelocity) < MIN_ANGULAR_THRESHOLD)
	{
		m_angularVelocity = 0;
	}
}

void RigidBody::ApplyForce(glm::vec2 force, glm::vec2 pos)
{
	/*glm::vec2 acceleration = force / m_mass;
	this->SetVelocity(GetVelocity() + acceleration);*/

	m_velocity += force / GetMass();
	m_angularVelocity += (force.y * pos.x - force.x * pos.y) / GetMoment();
}

//void RigidBody::ApplyForceToActor(RigidBody* actor2, glm::vec2 force)
//{
//	actor2->ApplyForce(force);
//	this->ApplyForce(-force);
//}

void RigidBody::ResolveCollision(RigidBody* actor2, glm::vec2 contact, glm::vec2* collisionNormal, float pen)
{
	glm::vec2 normal = glm::normalize(collisionNormal ? *collisionNormal : 
		actor2->GetPosition() - m_position);

	glm::vec2 relativeVelocity = actor2->GetVelocity() - m_velocity;

	glm::vec2 perp(normal.y, -normal.x);

	if (glm::dot(normal, relativeVelocity) >= 0)
		return;

	float r1 = glm::dot(contact - m_position, -perp);
	float r2 = glm::dot(contact - actor2->m_position, perp);

	float v1 = glm::dot(m_velocity, normal) - r1 * m_angularVelocity;
	float v2 = glm::dot(actor2->m_velocity, normal) + r2 * actor2->m_angularVelocity;

	if (v1 > v2)
	{
		float mass1 = 1.0f / (1.0f / m_mass + (r1 * r1) / m_moment);
		float mass2 = 1.0f / (1.0f / m_mass + (r2 * r2) / actor2->m_moment);

		glm::vec2 force = (m_elasticity + actor2->GetElasticity()) * mass1 * mass2 / (mass1 + mass2) * (v1 - v2) * normal;

		ApplyForce(-force, contact - m_position);
		actor2->ApplyForce(force, contact - actor2->m_position);
	}

	if (pen > 0)
		PhysicsScene::ApplyContactForces(this, actor2, normal, pen);

	//float elasticity = (GetElasticity() + actor2->GetElasticity()) / 2.0f;
	//
	//float j = glm::dot(-(1 + elasticity) * relativeVelocity, normal) /
	//((1 / m_mass) + (1 / actor2->GetMass()));
	//
	//glm::vec2 force = normal * j;
	//
	//float kePre = GetKineticEnergy() + actor2->GetKineticEnergy();
	//
	//actor2->ApplyForce(force, contact);
	//
	//float kePost = GetKineticEnergy() + actor2->GetKineticEnergy();
	//
	//float deltaKE = kePost - kePre;
	//if (deltaKE > kePost * 0.01f)
	//{
	//	std::cout << "Kinetic Energy discrepancy greater than 1% detected!!" << std::endl;
	//}
}

float RigidBody::GetKineticEnergy()
{
	glm::vec2 mv = m_mass * m_velocity;
	glm::vec2 kEnergy = ((mv * mv) * 0.5f);

	return kEnergy.length();
}

float RigidBody::GetPotentialEnergy()
{
	return -GetMass() * glm::dot(PhysicsScene::GetGravity(), GetPosition());
}
