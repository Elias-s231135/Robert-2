#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include <vector>
#include <glm/vec4.hpp>

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

	//void ObjectTest();
	//void OnBall2Check(PhysicsObject* other);

protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;
	PhysicsScene* m_physicsScene;

	std::vector<Sphere*> flyBalls;
	std::vector<Sphere*> waspBalls;

	float waspMass = 3.0f;

	Box* p1Brick;
	Box* p2Brick; //= Box(glm::vec2(90, 50), glm::vec2(0), 32.0f, glm::vec2(5, 10), glm::vec4(r, 0, 0, 1));
	std::vector<Box*> testBoxes;

	bool m_gameOver = false;
	bool m_secondPlayerAlive = false;

	// activates debug mode at 8
	int debugCounter = 0;
	bool debugMode = false;

	// increases every 50 flies defeated
	int waveCounter = 0;

	// pause
	bool pause = false;


	//// colour switch, with support for other colours. 0 = concise, 1 = themed.
	//int colourMode = 0;

	//// concise colours
	//glm::vec4    coinColour = glm::vec4(1, 1, 0, 1);
	//glm::vec4   enemyColour = glm::vec4(1, 0, 0, 1);
	//glm::vec4      p1Colour = glm::vec4(0, 1, 0, 1);
	//glm::vec4      p2Colour = glm::vec4(0, r, 0, 1);

	//// themed colours
	//glm::vec4     flyColour = glm::vec4(0.29, 0.25, 0.16, 1);
	//glm::vec4    waspColour = glm::vec4(0.95, 0.72, 0.12, 1);
	//glm::vec4 p1BrickColour = glm::vec4(0.95, 0.72, 0.12, 1);
	//glm::vec4 p2BrickColour = glm::vec4(r, 0, 0, 1);

};