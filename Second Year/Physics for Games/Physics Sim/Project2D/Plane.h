#pragma once
#include "PhysicsObject.h"
#include "glm/vec4.hpp"

class RigidBody;

class Plane : public PhysicsObject
{
public:

	Plane();
	Plane(glm::vec2 normal, float distance, glm::vec4 colour);
	~Plane();

	virtual void FixedUpdate(glm::vec2 gravity, float timestep);
	virtual void Draw();
	virtual void ResetPosition();

	glm::vec2 GetNormal() { return m_normal; }
	float GetDistance() { return m_distanceToOrigin; }

	void ResolveCollision(RigidBody* actor2, glm::vec2 contact);

protected:

	glm::vec2 m_normal;
	float m_distanceToOrigin;
	glm::vec4 m_colour;
};

