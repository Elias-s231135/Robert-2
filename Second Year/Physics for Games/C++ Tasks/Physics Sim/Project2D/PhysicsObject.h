#pragma once
#include <glm/vec2.hpp>
#include <glm/vec4.hpp>

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

	PhysicsObject(ShapeType a_shapeID) : m_shapeID(a_shapeID) { m_elasticity = 1; }

	ShapeType GetShapeType() { return m_shapeID; }

	virtual float GetEnergy() { return 0; }

	float GetElasticity() { return m_elasticity; }

	glm::vec4 GetColour() { return m_colour; }

	void SetColour(glm::vec4(colour)) { m_colour = colour; }

public:

	virtual void FixedUpdate(glm::vec2 gravity, float timestep) = 0;
	virtual void Draw() = 0;
	virtual void ResetPosition() {};

protected:
	ShapeType m_shapeID;
	
	float m_elasticity;

	glm::vec4 m_colour;
};

