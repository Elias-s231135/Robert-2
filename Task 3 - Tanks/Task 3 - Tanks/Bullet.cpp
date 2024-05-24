#include "Bullet.h"
#include "Sphere.h"
#include "AABB.h"
#include "Plane.h"

//struct Plane;

void Bullet::OnUpdate(float deltaTime)
{
	const float SHOOTSPEED = 500.0f;
		
	Mine::Vector3 finalShoot = GetForward() * (SHOOTSPEED * deltaTime);

	Translate(finalShoot);

	Sphere* sphere = static_cast<Sphere*>(m_collider);
	sphere->center = GetWorldPosition();
	DrawCircleLines(sphere->center.x, sphere->center.y, sphere->radius, GREEN);

	
	/*if (CheckCollision(Plane) == INTERSECTS)	
	{
		Destroy();
	}*/
}



Bullet::Bullet()
{
	m_collider = new Sphere(GetWorldPosition(), 20);
}
