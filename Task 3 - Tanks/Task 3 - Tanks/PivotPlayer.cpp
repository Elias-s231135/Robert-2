#include "PivotPlayer.h"

void PivotPlayer::OnUpdate(float deltaTime)
{
	const float RSPEED = 4.0f;

	//
	// check for key input
	//

	float yRotate = 0.0f;

	// Q-E for LEFT-RIGHT rotation
	if (IsKeyDown(KeyboardKey::KEY_Q))
	{
		yRotate += RSPEED;
	}
	if (IsKeyDown(KeyboardKey::KEY_E))
	{
		yRotate -= RSPEED;
	}

	// total displacement for this frame

	float finalRotate = (yRotate * deltaTime);

	// apply the rotate to the turret's pivot point

	Rotate(finalRotate);
}

