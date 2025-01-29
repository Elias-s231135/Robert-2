#pragma once
#include "PhysicsObject.h"
#include "glm/vec4.hpp"

class Plane : public PhysicsObject
{
public:

	Plane();
	Plane(glm::vec2 normal, float distance);
	~Plane();

	virtual void FixedUpdate(glm::vec2 gravity, float timestep);
	virtual void Draw();
	virtual void ResetPosition();

	glm::vec2 GetNormal() { return m_normal; }
	float GetDistance() { return m_distanceToOrigin; }

protected:

	glm::vec2 m_normal;
	float m_distanceToOrigin;
	glm::vec4 m_colour;
};

