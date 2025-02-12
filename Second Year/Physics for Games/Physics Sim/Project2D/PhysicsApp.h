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
	std::vector<Sphere*> waspBalls;

	Box* brick;
	Box* p2Brick; //= Box(glm::vec2(90, 50), glm::vec2(0), 32.0f, glm::vec2(5, 10), glm::vec4(r, 0, 0, 1));
	std::vector<Box*> testBoxes;

	float m_timer;

	bool m_gameOver = false;
	bool m_secondPlayerAlive = false;
};