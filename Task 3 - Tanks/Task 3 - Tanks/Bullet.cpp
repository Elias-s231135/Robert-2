#include "Bullet.h"

void Bullet::OnUpdate(float deltaTime)
{
	const float SHOOTSPEED = 500.0f;
		
	Mine::Vector3 finalShoot = GetForward() * (SHOOTSPEED * deltaTime);

	Translate(finalShoot);
}
