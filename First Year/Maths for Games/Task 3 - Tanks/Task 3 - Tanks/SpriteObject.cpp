#include "SpriteObject.h"	// for SpriteObject, class to be implemented
#include "Utils.h"

SpriteObject::SpriteObject()
{
	Sprite = nullptr;
	Origin = Mine::Vector3(0.5f, 0.5f, 0.5f);
	Tint = Mine::Colour(255, 255, 255, 255);
}

void SpriteObject::OnDraw()
{
	// extract transform data position
	Mine::Vector3 pos = GetWorldPosition();
	float rot = (GetWorldRotation() / PI) * 180;
	Mine::Vector3 scl = GetWorldScale();

	// draw sprite using raylib
	Sprite->Draw(
		raylib::Rectangle(0, 0, (float)Sprite->width, (float)Sprite->height),
		raylib::Rectangle(pos.x, pos.y, Sprite->width * scl.x, Sprite->height * scl.y),
		raylib::Vector2(Sprite->width * Origin.x * scl.x, Sprite->height * Origin.y * scl.y),
		rot,
		raylib::Color(Tint.colour));
}