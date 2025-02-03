#include "PhysicsApp.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "Gizmos.h"
#include <glm\ext.hpp>
#include "glm/vec2.hpp"
#include "glm/vec4.hpp"


#include "Plane.h"

#include "Sphere.h"


PhysicsApp::PhysicsApp() {

}

PhysicsApp::~PhysicsApp() {

}

bool PhysicsApp::startup() {
	
	aie::Gizmos::create(255U, 255U, 65535U, 65535U);

	m_2dRenderer = new aie::Renderer2D();

	m_font = new aie::Font("./font/consolas.ttf", 32);
	
	m_physicsScene = new PhysicsScene();
	PhysicsScene::SetGravity(glm::vec2(0, 0));
	m_physicsScene->SetTimestep(0.01f);
	
	for (int i = 0; i < 200; i++)
	{
		Sphere* flyBall = new Sphere(glm::vec2(rand() % 30 - 30, rand() % 30 - 30), glm::vec2(0), 2.0f, 2.5, glm::vec4(0.29, 0.25, 0.16, 1));
		flyBalls.push_back(flyBall);
		m_physicsScene->AddActor(flyBall);
	}

	waspBall = new Sphere(glm::vec2(rand() % 30 - 30, rand() % 30 - 30), glm::vec2(0), 8.0f, 4, glm::vec4(0.95, 0.72, 0.12, 1));
	m_physicsScene->AddActor(waspBall);

	/*bestBall = new Sphere(glm::vec2(rand() % 30 - 30, rand() % 30 - 30), glm::vec2(0), 4.0f, 4, glm::vec4(0.29, 0.25, 0.16, 1));
	m_physicsScene->AddActor(bestBall);*/

	/*Sphere* negativeBall;
	negativeBall = new Sphere(glm::vec2(10, 0), glm::vec2(0), 4.0f, 4, glm::vec4(0, 1, 0, 1));
	m_physicsScene->AddActor(negativeBall);*/

	//ball->ApplyForce(glm::vec2(30, 0));
	//negativeBall->ApplyForce(glm::vec2(-15, 0));
	
	Plane* plane1 = new Plane(glm::vec2(0, 1), -50);	//bottom
	Plane* plane2 = new Plane(glm::vec2(1, 0), -90);	//left
	Plane* plane3 = new Plane(glm::vec2(0, -1), -50);	//top
	Plane* plane4 = new Plane(glm::vec2(-1, 0), -90);	//right

	m_physicsScene->AddActor(plane1);
	m_physicsScene->AddActor(plane2);
	m_physicsScene->AddActor(plane3);
	m_physicsScene->AddActor(plane4);

	return true;
}

void PhysicsApp::shutdown() {
	
	delete m_font;
	delete m_2dRenderer;
}

void PhysicsApp::update(float deltaTime) 
{
	// input example
	aie::Input* input = aie::Input::getInstance();

	aie::Gizmos::clear();

	m_physicsScene->Update(deltaTime);
	m_physicsScene->Draw();

	if (input->isKeyDown(aie::INPUT_KEY_M))
	{
		for (auto flyBall : flyBalls) {
			flyBall->ApplyForce(glm::vec2(rand() % 50 - 25, rand() % 50 - 25), glm::vec2(rand() % 50 - 25, rand() % 50 - 25));
		}
		waspBall->ApplyForce(glm::vec2(rand() % 100 - 50, rand() % 100 - 50), glm::vec2(rand() % 100 - 50, rand() % 100 - 50));
		//bestBall->ApplyForce(glm::vec2(rand() % 50 - 25, rand() % 50 - 25), glm::vec2(rand() % 50 - 25, rand() % 50 - 25));
	}

	if (input->wasKeyPressed(aie::INPUT_KEY_END))
	{
		for (auto flyBall : flyBalls) {
			flyBall->ApplyForce(glm::vec2(rand() % 1000 - 500, rand() % 1000 - 500), glm::vec2(rand() % 1000 - 500, rand() % 1000 - 500));
		}
		//waspBall->ApplyForce(glm::vec2(rand() % 1000 - 500, rand() % 1000 - 500), glm::vec2(rand() % 1000 - 500, rand() % 1000 - 500));
		//bestBall->ApplyForce(glm::vec2(rand() % 50 - 25, rand() % 50 - 25), glm::vec2(rand() % 50 - 25, rand() % 50 - 25));
	}

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void PhysicsApp::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	static float aspectRatio = 16 / 9.f;
	aie::Gizmos::draw2D(glm::ortho<float>(-100, 100, -100 / aspectRatio, 100 / aspectRatio, -1.0f, 1.0f));

	// output some text, uses the last used colour
	m_2dRenderer->drawText(m_font, "Press ESC to quit!", 0, 720 - 64);

	// done drawing sprites
	m_2dRenderer->end();
}