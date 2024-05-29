#pragma once
#include "raylib-cpp.hpp"   // for raylib API
#include "SpriteObject.h"

class Crate : public SpriteObject
{
protected:

	void OnUpdate(float deltaTime) override;

public:

	/*Mine::Vector3 locatedLocation;

	void SetLocation(Mine::Vector3 location);
	
	Mine::Vector3 GetLocation() const;*/

	Crate();

	Crate(Mine::Vector3 pos);

	void OnCollision() override;

public:
//	raylib::Texture2D crateReference("res/crateWood.png");
};

