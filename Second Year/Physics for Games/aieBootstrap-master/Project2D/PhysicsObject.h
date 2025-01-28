#pragma once
#include <glm/vec2.hpp>

class PhysicsObject
{
protected:

	PhysicsObject();
	~PhysicsObject();

public:

	virtual void FixedUpdate(glm::vec2 gravity, float timestep) = 0;
	virtual void Draw() = 0;
	virtual void ResetPosition() {};
};

