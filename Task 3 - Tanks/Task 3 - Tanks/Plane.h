#pragma once

//#include "GameObject.h"
//#include <vector>
#include "Colliders.h"

struct Plane : public Collider
{
	Plane();
	Plane(float x, float y, float d) : N(x, y, 0), d(d);
	Plane(const Mine::Vector3& n, float d) : N(n), d(d);

	Mine::Vector3 N;
	float d;

	float DistanceTo(const Mine::Vector3& p) const;
	
	Mine::Vector3 ClosestPoint(const Mine::Vector3& p) const;

	enum ePlaneResult : int
	{
		FRONT = 1,
		BACK = -1,
		INTERSECTS = 0
	};

	ePlaneResult TestSide(const Mine::Vector3& p) const;
	ePlaneResult TestSide(const Sphere& sphere) const;
	ePlaneResult TestSide(const AABB& aabb) const;
};