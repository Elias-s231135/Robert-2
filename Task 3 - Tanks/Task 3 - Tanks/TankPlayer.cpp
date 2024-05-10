#include "TankPlayer.h"

void TankPlayer::OnUpdate(float deltaTime)
{
	const float MOVESPEED = 150.0f;

	//
	// check for key input
	//
	float yMove = 0.0f;

	// W-S for UP-DOWN movement
	if (IsKeyDown(KeyboardKey::KEY_W))
	{
		yMove += MOVESPEED;
	}
	if (IsKeyDown(KeyboardKey::KEY_S))
	{
		yMove -= MOVESPEED;
	}

	// total displacement for this frame
	Mine::Vector3 finalMove = GetForward() * (yMove * deltaTime);
	
	// apply the move to the tank
	Translate(finalMove);
}