#include "Bullet.h"

void Bullet::OnUpdate(float deltaTime)
{
	const float SHOOTSPEED = 500.0f;
		
	Mine::Vector3 finalShoot = GetForward() * (SHOOTSPEED * deltaTime);

	Translate(finalShoot);

	Sphere* sphere = static_cast<Sphere*>(m_collider);
	sphere->center = GetWorldPosition();
	DrawCircleLines(sphere->center.x, sphere->center.y, sphere->radius, GREEN);
}

Bullet::Bullet()
{
	m_collider = new Sphere(GetWorldPosition(), 20);
}
