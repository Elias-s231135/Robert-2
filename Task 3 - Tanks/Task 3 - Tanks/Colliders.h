#pragma once

#include "GameObject.h"
#include <vector>

struct Collider {
public:
	virtual void CheckCollision(Collider* other);
	GameObject* m_owner;
};



	

	