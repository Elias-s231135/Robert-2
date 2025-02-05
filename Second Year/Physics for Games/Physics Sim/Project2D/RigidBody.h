#pragma once
#include "PhysicsObject.h"

class RigidBody : public PhysicsObject
{
public:
	RigidBody(ShapeType shapeID, glm::vec2 position, glm::vec2 velocity, float orientation, float mass);
	~RigidBody();

	virtual void FixedUpdate(glm::vec2 gravity, float timestep);
	void ApplyForce(glm::vec2 force, glm::vec2 pos);
	/*void ApplyForceToActor(RigidBody* actor2, glm::vec2 force);*/

	glm::vec2 GetPosition() { return m_position; }
	float GetOrientation() { return m_orientation; }
	glm::vec2 GetVelocity() { return m_velocity; }
	float GetMass() { return m_mass; }

	void SetVelocity(glm::vec2 velocity) { m_velocity = velocity; }

	void ResolveCollision(RigidBody* actor2, glm::vec2 contact, glm::vec2* collisionNormal = nullptr, float pen = 0);

	float GetKineticEnergy();
	float GetPotentialEnergy();
	float GetEnergy() { return GetKineticEnergy() + GetPotentialEnergy(); }
	float GetAngularVelocity() { return m_angularVelocity; }
	float GetMoment() { return m_moment; }

	void SetPosition(glm::vec2 pos) { m_position = pos; }

protected:

	glm::vec2 m_position;
	glm::vec2 m_velocity;
	float m_mass;
	float m_orientation;
	float m_angularVelocity;
	float m_moment;

	float m_linearDrag;
	float m_angularDrag;

	const static float MIN_LINEAR_THRESHOLD;
	const static float MIN_ANGULAR_THRESHOLD;
};

