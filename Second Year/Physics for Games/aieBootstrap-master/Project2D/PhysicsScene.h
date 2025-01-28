#pragma once
#include "glm/vec2.hpp"
#include <vector>
#include "PhysicsObject.h"

class PhysicsScene
{
public:
	PhysicsScene();
	~PhysicsScene();

	void AddActor(PhysicsObject* actor) { m_actors.push_back(actor); }
	void RemoveActor(PhysicsObject* actor);
	void Update(float dt);
	void Draw();

	void SetGravity(const glm::vec2 gravity) { m_gravity = gravity; }
	glm::vec2 GetGravity() const { return m_gravity; }

	void SetTimestep(const float timestep) { m_timestep = timestep; }
	float GetTimestep() const { return m_timestep; }

protected:
	glm::vec2 m_gravity;
	float m_timestep;
	std::vector<PhysicsObject*> m_actors;
};

