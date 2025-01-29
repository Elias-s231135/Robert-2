#include "Plane.h"
#include "Gizmos.h"

Plane::Plane() : PhysicsObject(ShapeType::PLANE) 
{
	m_distanceToOrigin = 0;
	m_normal = glm::vec2(0, 1);
}

Plane::Plane(glm::vec2 normal, float distance)
{
	m_normal = normal;
	m_distanceToOrigin = distance;
}

Plane::~Plane()
{
}

void Plane::fixedUpdate(glm::vec2 gravity, float timestep)
{
}

void Plane::Draw()
{
	float lineSegmentLength = 300;
	glm::vec2 centrepoint = m_normal * m_distanceToOrigin;
	glm::vec2 parallel(m_normal.y, -m_normal.x);
	glm::vec4 colourFade = m_colour;
	colourFade.a = 0;
	glm::vec2 start = centrepoint + (parallel * lineSegmentLength);
	glm::vec2 end = centrepoint - (parallel * lineSegmentLength);
	aie::Gizmos::add2DTri(start, end, start - m_normal * 10.0f, m_colour, m_colour, colourFade);
	aie::Gizmos::add2DTri(end, end - m_normal * 10.0f, start - m_normal * 10.0f, m_colour, colourFade, colourFade);
}

void Plane::ResetPosition()
{
}
