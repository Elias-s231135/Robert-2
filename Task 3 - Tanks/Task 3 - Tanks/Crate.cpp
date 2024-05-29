#include "Crate.h"
#include "AABB.h"

void Crate::OnUpdate(float deltaTime)
{
	DrawRectangleLines(GetWorldPosition().x - (Sprite->width / 2), GetWorldPosition().y - (Sprite->height / 2), Sprite->width, Sprite->height,  PURPLE);
}

//void Crate::SetLocation(Mine::Vector3 location)
//{
//	locatedLocation = location;
//}
//
//Mine::Vector3 Crate::GetLocation() const
//{
//	return Mine::Vector3();
//}

Crate::Crate(Mine::Vector3 pos)
{
	SetLocalPosition(pos);
	m_collider = new AABB(GetLocalPosition() - Mine::Vector3(20, 20, 0), GetLocalPosition() + Mine::Vector3(20, 20, 0));
	m_collider->m_owner = this;
}

Crate::Crate()
{
	/*m_collider = new AABB(GetLocalPosition() - Mine::Vector3(5, 5, 0), GetLocalPosition() + Mine::Vector3(5, 5, 0));
	m_collider->m_owner = this;*/
}

void Crate::OnCollision()
{
	// Sprite = "res/explosion2.png";
	this->Destroy();
}