#include "PhysicsApp.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "Gizmos.h"
#include "glm/ext.hpp"
#include "glm/vec2.hpp"
#include "glm/vec4.hpp"


#include "Plane.h"
#include "PhysicsScene.h"
#include "Sphere.h"
#include "Box.h"

#include "iostream"

int score = 0;
int p2Score = 0;

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
	
	for (int i = 0; i < 50; i++)
	{
		Sphere* flyBall = new Sphere(glm::vec2(0), glm::vec2(0), 1.0f, 1.75, glm::vec4(0.29, 0.25, 0.16, 1));
		flyBalls.push_back(flyBall);
		m_physicsScene->AddActor(flyBall);
	}

	Sphere* waspBall = new Sphere(glm::vec2(-90, -50), glm::vec2(0), 2.0f, 5, glm::vec4(0.95, 0.72, 0.12, 1));
	waspBalls.push_back(waspBall);
	m_physicsScene->AddActor(waspBall);

	brick = new Box(glm::vec2(90, 50), glm::vec2(0), 32.0f, glm::vec2(5, 10), glm::vec4(0.66, 0.29, 0.26, 1));
	m_physicsScene->AddActor(brick);

	Plane* plane1 = new Plane(glm::vec2(0, 1), -50, glm::vec4(0.5, 0.5, 1, 1));		//bottom
	Plane* plane2 = new Plane(glm::vec2(1, 0), -90, glm::vec4(0.5, 0.5, 1, 1));		//left
	Plane* plane3 = new Plane(glm::vec2(0, -1), -50, glm::vec4(0.5, 0.5, 1, 1));	//top
	Plane* plane4 = new Plane(glm::vec2(-1, 0), -90, glm::vec4(0.5, 0.5, 1, 1));	//right

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
	aie::Input* input = aie::Input::getInstance();

	aie::Gizmos::clear();

	m_physicsScene->Update(deltaTime);
	m_physicsScene->Draw();

	//flyball and waspball movement
	//float fmr = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / 25 - -25));
	//float wmr = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / 50 - -50));

	for (auto flyBall : flyBalls) 
	{
		flyBall->ApplyForce(glm::vec2(rand() % 25 - 12.5, rand() % 25 - 12.5), glm::vec2(0, 0));
	}
	for (auto waspBall : waspBalls)
	{
		waspBall->ApplyForce(glm::vec2(rand() % 50 - 25, rand() % 50 - 25), glm::vec2(0, 0));
	}

	//flyball speed boost
	if (input->isKeyDown(aie::INPUT_KEY_END))
	{
		for (auto flyBall : flyBalls) {
			flyBall->ApplyForce(glm::vec2(rand() % 1000 - 500, rand() % 1000 - 500), glm::vec2(rand() % 1000 - 500, rand() % 1000 - 500));
		}
	}

	//brick movement
	if (input->wasKeyPressed(aie::INPUT_KEY_A))
	{
		brick->ApplyForce(glm::vec2(-1000, 0), glm::vec2(0, 0));
	}
	if (input->wasKeyPressed(aie::INPUT_KEY_S))
	{
		brick->ApplyForce(glm::vec2(0, -1000), glm::vec2(0, 0));
	}
	if (input->wasKeyPressed(aie::INPUT_KEY_D))
	{
		brick->ApplyForce(glm::vec2(1000, 0), glm::vec2(0, 0));
	}
	if (input->wasKeyPressed(aie::INPUT_KEY_W))
	{
		brick->ApplyForce(glm::vec2(0, 1000), glm::vec2(0, 0));
	}

	//random float
	float r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);

	//make testBox. testBox cannot be destroyed by waspballs, allowing unimpeded testing of gameplay 
	if (input->wasKeyPressed(aie::INPUT_KEY_T))
	{
		for (int i = 0; i < 1; i++)
		{
			Box* testBox = new Box(glm::vec2(90, 50), glm::vec2(0), 32.0f, glm::vec2(5, 10), glm::vec4(0, r, r, 1));
			testBoxes.push_back(testBox);
			m_physicsScene->AddActor(testBox);
		}
	}

	//testbox movement
	for (auto testBox : testBoxes)
	{
		if (input->wasKeyPressed(aie::INPUT_KEY_G))
		{
			testBox->ApplyForce(glm::vec2(-1000, 0), glm::vec2(0, 0));
		}
		if (input->wasKeyPressed(aie::INPUT_KEY_H))
		{
			testBox->ApplyForce(glm::vec2(0, -1000), glm::vec2(0, 0));
		}
		if (input->wasKeyPressed(aie::INPUT_KEY_J))
		{
			testBox->ApplyForce(glm::vec2(1000, 0), glm::vec2(0, 0));
		}
		if (input->wasKeyPressed(aie::INPUT_KEY_Y))
		{
			testBox->ApplyForce(glm::vec2(0, 1000), glm::vec2(0, 0));
		}
	}

	// second player
	if (input->wasKeyPressed(aie::INPUT_KEY_ENTER))
	{
		p2Score = 0;
		p2Brick = new Box(glm::vec2(90, 50), glm::vec2(0), 32.0f, glm::vec2(5, 10), glm::vec4(r, 0, 0, 1));
		m_physicsScene->AddActor(p2Brick);
		m_secondPlayerAlive = true;
	}

	// second player movement
	
	if (input->wasKeyPressed(aie::INPUT_KEY_LEFT))
	{
		p2Brick->ApplyForce(glm::vec2(-1000, 0), glm::vec2(0, 0));
	}
	if (input->wasKeyPressed(aie::INPUT_KEY_DOWN))
	{
		p2Brick->ApplyForce(glm::vec2(0, -1000), glm::vec2(0, 0));
	}
	if (input->wasKeyPressed(aie::INPUT_KEY_RIGHT))
	{
		p2Brick->ApplyForce(glm::vec2(1000, 0), glm::vec2(0, 0));
	}
	if (input->wasKeyPressed(aie::INPUT_KEY_UP))
	{
		p2Brick->ApplyForce(glm::vec2(0, 1000), glm::vec2(0, 0));
	}

	//make more flyballs (obsolete)
	/*if (input->isKeyDown(aie::INPUT_KEY_N))
	{
	
		Sphere* flyBall = new Sphere(glm::vec2(rand() % 30 - 30, rand() % 30 - 30), glm::vec2(0), 1.0f, 1.75, glm::vec4(0.29, 0.25, 0.16, 1));
		flyBalls.push_back(flyBall);
		m_physicsScene->AddActor(flyBall);
	
	}*/

	//brick destroys flyballs
	for (auto flyball : flyBalls)
	{
		flyball->collisionCallback = [=](PhysicsObject* other)
			{

				if (other->GetShapeType() == BOX)
				{
					// add to score
					if (other == brick)
					{
						score += 10;
					}
					else if (other == p2Brick)
					{
						p2Score += 10;
					}

					for (auto it = flyBalls.begin(); it != flyBalls.end(); it++)
					{
						if (*it == flyball)
						{
							flyBalls.erase(it);
							break;
						}
					}
					m_physicsScene->RemoveActor(flyball);
				}
				//if there are no flyballs, make more and add another waspball. makes gameplay "infinite" while also increasing difficulty
				if (flyBalls.empty())
				{
					for (int i = 0; i < 50; i++)
					{
						Sphere* flyBall = new Sphere(glm::vec2(0), glm::vec2(0), 1.0f, 1.75, glm::vec4(0.29, 0.25, 0.16, 1));
						flyBalls.push_back(flyBall);
						m_physicsScene->AddActor(flyBall);
					}
					Sphere* waspBall = new Sphere(glm::vec2(-90, -50), glm::vec2(0), 2.0f, 5, glm::vec4(0.95, 0.72, 0.12, 1));
					waspBalls.push_back(waspBall);
					m_physicsScene->AddActor(waspBall);
				}
			};
	}

	for (auto waspBall : waspBalls)
	{
		waspBall->collisionCallback = [=](PhysicsObject* other)
			{
				if (other == brick)
				{
					// game over sequence
					m_physicsScene->RemoveActor(brick);

					m_gameOver = true;
				}
				if (m_secondPlayerAlive)
				{
					if (other == p2Brick)
					{
						//player 2 death
						m_physicsScene->RemoveActor(p2Brick);

						m_secondPlayerAlive = false;
					}
				}
			};
	}

	//if (input->isKeyDown(aie::INPUT_KEY_P))
	//{
	//	waspBall = new Sphere(glm::vec2(-90, -50), glm::vec2(0), 2.0f, 5, glm::vec4(0.95, 0.72, 0.12, 1));
	//	m_physicsScene->AddActor(waspBall);
	//}

	// restart game
	if (input->wasKeyPressed(aie::INPUT_KEY_R))
	{
		//reset app
		score = 0;

		shutdown();
		startup();

		m_gameOver = false;
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
	m_2dRenderer->drawText(m_font, "Press ESC to quit!", 5, 5);

	// display score
	std::string sScore = std::to_string(score);
	char const* charScore = sScore.c_str();
	m_2dRenderer->drawText(m_font, charScore, 0, 656);

	// display game over
	if (m_gameOver)
	{
		m_2dRenderer->drawText(m_font, "Game Over", 800, 450);
		m_2dRenderer->drawText(m_font, "Press R to restart", 800, 350);
	}

	// player 2 score
	std::string sP2Score = std::to_string(p2Score);
	char const* charP2Score = sP2Score.c_str();

	if (m_secondPlayerAlive)
	{
		m_2dRenderer->drawText(m_font, charP2Score, 0, 626);
	}

	// display P1 x coords
	std::string sCoordsX = std::to_string(brick->GetPosition().x);
	char const* cCoordsX = sCoordsX.c_str();
	m_2dRenderer->drawText(m_font, cCoordsX, 0, 530);

	// display P1 y coords
	std::string sCoordsY = std::to_string(brick->GetPosition().y);
	char const* cCoordsY = sCoordsY.c_str();
	m_2dRenderer->drawText(m_font, cCoordsY, 0, 500);

	// display waspBall coords
	/*std::string sWaspX = std::to_string(waspBalls->begin()->GetPosition().x);
	char const* cWaspX = sWaspX.c_str();
	m_2dRenderer->drawText(m_font, cCoordsX, 0, 440);

	std::string sWaspY = std::to_string(waspBalls->begin()->GetPosition().y);
	char const* cWaspY = sCoordsY.c_str();
	m_2dRenderer->drawText(m_font, cCoordsY, 0, 410);*/

	// done drawing sprites
	m_2dRenderer->end();
}

void PhysicsApp::ObjectTest()
{
	m_physicsScene->SetGravity(glm::vec2(0, -9.82f));

	Sphere* ball1 = new Sphere(glm::vec2(-20, 0), glm::vec2(0), 4.0f, 4, glm::vec4(1, 0, 0, 1));
	Sphere* ball2 = new Sphere(glm::vec2(10, -20), glm::vec2(0), 4.0f, 4, glm::vec4(0, 1, 0, 1));

	m_physicsScene->AddActor(ball1);
	m_physicsScene->AddActor(ball2);
	m_physicsScene->AddActor(new Plane(glm::vec2(0, 1), -30, glm::vec4(1, 1, 1, 1)));
	m_physicsScene->AddActor(new Plane(glm::vec2(1, 0), -50, glm::vec4(1, 1, 1, 1)));
	m_physicsScene->AddActor(new Plane(glm::vec2(-1, 0), -50, glm::vec4(1, 1, 1, 1)));
	m_physicsScene->AddActor(new Box(glm::vec2(20, 10), glm::vec2(3, 0), 0.5f, glm::vec2(4, 8), glm::vec4(1, 1, 1, 1)));
	m_physicsScene->AddActor(new Box(glm::vec2(-40, 10), glm::vec2(3, 0), 0.5f, glm::vec2(4, 8), glm::vec4(1, 1, 1, 1)));

	ball2->triggerEnter = [=](PhysicsObject* other) {std::cout << "Enter:" << other << std::endl; };
	ball2->triggerExit = [=](PhysicsObject* other) {std::cout << "Exit:" << other << std::endl; };

	ball1->collisionCallback = [=](PhysicsObject* other)
		{
			if (other == ball2)
			{
				std::cout << "No way? No way!" << std::endl;
			}
			return;
		};

	ball2->collisionCallback = std::bind(&PhysicsApp::OnBall2Check, this, 
		std::placeholders::_1);
}

void PhysicsApp::OnBall2Check(PhysicsObject* other)
{
	Plane* plane = dynamic_cast<Plane*>(other);
	if (plane != nullptr)
		std::cout << "Blue Spheres!" << std::endl;
}
