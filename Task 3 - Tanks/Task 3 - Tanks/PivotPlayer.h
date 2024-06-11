#pragma once

#include "SpriteObject.h"

class PivotPlayer : public GameObject
{
protected:
	void OnUpdate(float deltaTime) override;
};

