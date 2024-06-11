#pragma once

#include "raylib-cpp.hpp"	// for raylib::Texture2D

#include "Colour.h"			// for Colour
#include "GameObject.h"		// for GameObject

class SpriteObject : public GameObject
{
public:
	raylib::Texture2D* Sprite;
	Mine::Vector3 Origin;

	Mine::Colour Tint;

	SpriteObject();
protected:
	void OnDraw() override;
};