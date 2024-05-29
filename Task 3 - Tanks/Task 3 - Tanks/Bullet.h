#pragma once

#include "SpriteObject.h"

class Bullet : public SpriteObject
{
protected:
	
	void OnUpdate(float deltaTime) override;

public:

	Bullet();
	void OnCollision() override;
};