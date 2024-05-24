#pragma once
#include "raylib-cpp.hpp"   // for raylib API
#include "SpriteObject.h"

class Crate : public SpriteObject
{
protected:

	void OnUpdate(float deltaTime) override;

public:

	Crate();

public:
//	raylib::Texture2D crateReference("res/crateWood.png");
};

