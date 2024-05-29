#include "TankPlayer.h"
#include "Colliders.h"
#include "Sphere.h"
#include "AABB.h"
#include "Plane.h"

void TankPlayer::OnUpdate(float deltaTime)
{
	const float MOVESPEED = 150.0f;
	const float RSPEED = 2.0f;
	//
	// check for key input
	//
	float yMove = 0.0f;

	float yRotate = 0.0f;
	// W-S for UP-DOWN movement
	if (IsKeyDown(KeyboardKey::KEY_W))
	{
		yMove += MOVESPEED;
	}
	if (IsKeyDown(KeyboardKey::KEY_S))
	{
		yMove -= MOVESPEED;
	}

	// A-D for LEFT-RIGHT rotation
	if (IsKeyDown(KeyboardKey::KEY_A))
	{
		yRotate += RSPEED;
	}
	if (IsKeyDown(KeyboardKey::KEY_D))
	{
		yRotate -= RSPEED;
	}

	// total displacement for this frame
	Mine::Vector3 finalMove = GetForward() * (yMove * deltaTime);
	
	float finalRotate = (yRotate * deltaTime);

	// apply the move to the tank
	Translate(finalMove);
	// apply the rotate to the tank
	Rotate(finalRotate);


	//update collider
	/*Sphere* sphere = static_cast<Sphere*>(m_collider);
	sphere->center = GetWorldPosition();
	DrawCircleLines(sphere->center.x, sphere->center.y, sphere->radius, YELLOW);*/

	//PUT THIS IN ONDRAW OVERIDE
	//DrawCircleLines(collider center x, collider center y, collider radius, YELLOW)
}

TankPlayer::TankPlayer()
{
	//m_collider = new Sphere(GetWorldPosition(), 80);
	////set the owner of m_collider to this gameobject
	//m_collider->m_owner = this;
}
