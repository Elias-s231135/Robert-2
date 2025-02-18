#pragma once
#include "RigidBody.h"
#include "glm/vec4.hpp"

class Sphere : public RigidBody
{
public:
	Sphere(glm::vec2 position, glm::vec2 velocity, float mass, float radius, glm::vec4 colour);
	~Sphere();

	virtual void Draw();

	float GetRadius() { return m_radius; }

protected:
	float m_radius;
};

