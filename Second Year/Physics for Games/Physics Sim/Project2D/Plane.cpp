#include "Plane.h"
#include "Gizmos.h"
#include "Sphere.h"
#include "glm/geometric.hpp"
#include "iostream"
#include "RigidBody.h"

Plane::Plane() : PhysicsObject(PLANE) 
{
	m_distanceToOrigin = 0;
	m_normal = glm::vec2(0, 1);
}

Plane::Plane(glm::vec2 normal, float distance) : PhysicsObject(PLANE)
{
	m_normal = normal;
	m_distanceToOrigin = distance;
	m_colour = glm::vec4(1,1,1,1);
}

Plane::~Plane()
{
}

void Plane::FixedUpdate(glm::vec2 gravity, float timestep)
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

void Plane::ResolveCollision(RigidBody* actor2, glm::vec2 contact)
{
	//glm::vec2 normal = m_normal;
	//glm::vec2 relativeVelocity = actor2->GetVelocity();

	glm::vec2 localContact = contact - actor2->GetPosition();

	glm::vec2 vRel = actor2->GetVelocity() + actor2->GetAngularVelocity() * glm::vec2(-localContact.y, localContact.x);
	float velocityIntoPlane = glm::dot(vRel, m_normal);

	float e = 1;

	float r = glm::dot(localContact, glm::vec2(m_normal.y, -m_normal.x));

	float mass0 = 1.0f / (1.0f / actor2->GetMass() + (r * r) / actor2->GetMoment());

	float j = -(1 + e) * velocityIntoPlane * mass0;

	//if (glm::dot(normal, relativeVelocity) >= 0)
	//	return;

	//float elasticity = 2;
	//float j = glm::dot(-(1 + elasticity) * relativeVelocity, normal);
//		(1 / actor2->GetMass());

	glm::vec2 force = m_normal * j;

	float kePre = actor2->GetKineticEnergy();

	actor2->ApplyForce(force, contact - actor2->GetPosition());

	float kePost = actor2->GetKineticEnergy();

	float deltaKE = kePost - kePre;
	if (deltaKE > kePost * 0.01f)
	{
		std::cout << "Kinetic Energy discrepancy greater than 1% detected!!" << std::endl;
	}
}
