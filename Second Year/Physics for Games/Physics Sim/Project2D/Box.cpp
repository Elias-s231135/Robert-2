#include "Box.h"
#include <cmath>
#include "glm/glm.hpp"
#include "Gizmos.h"

Box::Box(glm::vec2 extents, glm::vec4 colour, glm::vec2 localX, glm::vec2 localY) : RigidBody(BOX, position, velocity, 0, mass)
{
	m_extents = glm::vec2(0, 0);
	m_colour = glm::vec4(1, 1, 1, 1);
	m_localX = glm::vec2(0, 0);
	m_localY = glm::vec2(0, 0);
}

void Box::FixedUpdate(glm::vec2 gravity, float timestep)
{
	RigidBody::FixedUpdate(gravity, timestep);

	float cs = cosf(m_orientation);
	float sn = sinf(m_orientation);
	m_localX = glm::normalize(glm::vec2(cs, sn));
	m_localY = glm::normalize(glm::vec2(-sn, cs));
}

void Box::Draw()
{
	glm::vec2 p1 = m_position - m_localX * m_extents.x - m_localY * m_extents.y;
	glm::vec2 p2 = m_position + m_localX * m_extents.x - m_localY * m_extents.y;
	glm::vec2 p3 = m_position - m_localX * m_extents.x + m_localY * m_extents.y;
	glm::vec2 p4 = m_position + m_localX * m_extents.x + m_localY * m_extents.y;
	aie::Gizmos::add2DTri(p1, p2, p4, m_colour);
	aie::Gizmos::add2DTri(p1, p4, p3, m_colour);
}
