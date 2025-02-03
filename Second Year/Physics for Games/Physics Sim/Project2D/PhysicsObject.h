#pragma once
#include <glm/vec2.hpp>

enum ShapeType {
	PLANE = 0,
	SPHERE,
	BOX,
	SHAPE_COUNT
};

class PhysicsObject
{
public:

	~PhysicsObject();

	PhysicsObject(ShapeType a_shapeID) : m_shapeID(a_shapeID) {}

	ShapeType GetShapeType() { return m_shapeID; }

	virtual float GetEnergy() { return 0; }

public:

	virtual void FixedUpdate(glm::vec2 gravity, float timestep) = 0;
	virtual void Draw() = 0;
	virtual void ResetPosition() {};

protected:
	ShapeType m_shapeID;
};

