#pragma once
#include "RigidBody.h"
#include "glm/vec4.hpp"

class Box : public RigidBody
{
public:

	//Box();
	//~Box();

	Box(glm::vec2 position, glm::vec2 velocity, float mass, glm::vec2 extents, glm::vec4 colour);


	virtual void FixedUpdate(glm::vec2 gravity, float timestep);
	void Draw();

	bool CheckBoxCorners(Box& box, glm::vec2& contact, int& numContacts, float& pen, glm::vec2& edgeNormal);

	const glm::vec2 GetLocalX() { return m_localX; }
	const glm::vec2 GetLocalY() { return m_localY; }

	glm::vec2 GetExtents() { return m_extents; }

	float GetWidth() { return m_extents.x * 2; }
	float GetHeight() { return m_extents.y * 2; }

protected:

	glm::vec2 m_extents;
	glm::vec2 m_localX;
	glm::vec2 m_localY;
};

