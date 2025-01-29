#include "RigidBody.h"

RigidBody::RigidBody(ShapeType shapeID, glm::vec2 position, glm::vec2 velocity, float orientation, float mass)
	: PhysicsObject(shapeID)
{
	shapeID;

	m_position = position;

	m_velocity = velocity;

	m_orientation = orientation;

	m_mass = mass;
}

RigidBody::~RigidBody()
{
}

void RigidBody::FixedUpdate(glm::vec2 gravity, float timestep)
{
	m_position += m_velocity * timestep;
	ApplyForce(gravity * m_mass * timestep);
}

void RigidBody::ApplyForce(glm::vec2 force)
{
	glm::vec2 acceleration = force / m_mass;
	this->SetVelocity(GetVelocity() + acceleration);
}

void RigidBody::ApplyForceToActor(RigidBody* actor2, glm::vec2 force)
{
	actor2->ApplyForce(force);
	this->ApplyForce(-force);
}
