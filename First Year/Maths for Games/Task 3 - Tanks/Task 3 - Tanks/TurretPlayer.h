#pragma once

#include "SpriteObject.h"

class TurretPlayer : public SpriteObject
{
public:
	raylib::Texture2D* bulletTexture;
	std::vector<GameObject*> bullets;
	      
protected:
	void OnUpdate(float deltaTime) override;
	void OnDraw() override;
};