#pragma once

#include "SpriteObject.h"

class TurretPlayer : public SpriteObject
{
protected:
	void OnUpdate(float deltaTime) override;
};