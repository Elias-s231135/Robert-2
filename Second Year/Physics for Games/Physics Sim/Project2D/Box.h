#pragma once
#include "RigidBody.h"
#include "glm/vec4.hpp"

class Box : public RigidBody
{
public:

	Box();
	~Box();

	void FixedUpdate(glm::vec2 gravity, float timestep);
	void Draw();

	glm::vec2 GetLocalX() { return m_localX; }
	glm::vec2 GetLocalY() { return m_localY; }

	glm::vec2 GetExtents() { return glm::vec2(m_localX, m_localY); }

	float GetWidth() { return m_extents.x * 2; }
	float GetHeight() { return m_extents.y * 2; }

protected:

	glm::vec2 m_extents;
	glm::vec4 m_colour;
	glm::vec2 m_localX;
	glm::vec2 m_localY;
};

