#pragma once
#include "glm/vec2.hpp"
#include <vector>

class PhysicsObject;


class PhysicsScene
{
public:
	PhysicsScene();
	~PhysicsScene();

	void AddActor(PhysicsObject* actor) { m_actors.push_back(actor); }
	void RemoveActor(PhysicsObject* actor);
	void Update(float dt);
	void Draw();

	static void SetGravity(glm::vec2 gravity) { m_gravity = gravity; }
	static glm::vec2 GetGravity() { return m_gravity; }

	void SetTimestep(const float timestep) { m_timestep = timestep; }
	float GetTimestep() const { return m_timestep; }

	static bool plane2Plane(PhysicsObject* obj1, PhysicsObject* obj2);
	static bool plane2Sphere(PhysicsObject* obj1, PhysicsObject* obj2);
	static bool plane2Box(PhysicsObject* obj1, PhysicsObject* obj2);
	static bool sphere2Plane(PhysicsObject* obj1, PhysicsObject* obj2);
	static bool sphere2Sphere(PhysicsObject* obj1, PhysicsObject* obj2);
	static bool sphere2Box(PhysicsObject* obj1, PhysicsObject* obj2);
	static bool box2Plane(PhysicsObject* obj1, PhysicsObject* obj2);
	static bool box2Sphere(PhysicsObject* obj1, PhysicsObject* obj2);
	static bool box2Box(PhysicsObject* obj1, PhysicsObject* obj2);

	float GetTotalEnergy();

protected:
	static glm::vec2 m_gravity;
	float m_timestep;
	std::vector<PhysicsObject*> m_actors;
};

typedef bool(*fn)(PhysicsObject*, PhysicsObject*);

static fn collisionFunctionArray[] =
{
	PhysicsScene::plane2Plane, PhysicsScene::plane2Sphere, PhysicsScene::plane2Box,
	PhysicsScene::sphere2Plane, PhysicsScene::sphere2Sphere, PhysicsScene::sphere2Box,
	PhysicsScene::box2Plane, PhysicsScene::box2Sphere, PhysicsScene::box2Box

};