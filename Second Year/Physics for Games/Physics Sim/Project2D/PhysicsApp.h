#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include <vector>

class PhysicsObject;
class PhysicsScene;
class Sphere;
class Box;

class PhysicsApp : public aie::Application {
public:

	PhysicsApp();
	virtual ~PhysicsApp();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

	void ObjectTest();
	void OnBall2Check(PhysicsObject* other);

protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;
	PhysicsScene* m_physicsScene;

	std::vector<Sphere*> flyBalls;
	Sphere* waspBall;
	//Sphere* bestBall;

	Box* brick;
	Box* testBox;

	float m_timer;
};