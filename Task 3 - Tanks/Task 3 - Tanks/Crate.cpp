#include "Crate.h"
#include "AABB.h"

void Crate::OnUpdate(float deltaTime)
{
	DrawRectangleLines(GetWorldPosition().x - (Sprite->width / 2), GetWorldPosition().y - (Sprite->height / 2), Sprite->width, Sprite->height,  PURPLE);
}

Crate::Crate()
{
	m_collider = new AABB(GetWorldPosition() - Mine::Vector3(5, 5, 0), GetWorldPosition() + Mine::Vector3(5, 5, 0));
}

//OnCollision()
//{
// 
//}