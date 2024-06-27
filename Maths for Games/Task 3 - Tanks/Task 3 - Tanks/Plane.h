#pragma once

//#include "GameObject.h"
//#include <vector>
#include "Colliders.h"

struct AABB;
struct Sphere;

struct Plane : public Collider
{
public:

	enum ePlaneResult : int
	{
		FRONT = 1,
		BACK = -1,
		INTERSECTS = 0
	};

public:
	Plane();
	Plane(float x, float y, float d);
	Plane(const Mine::Vector3& n, float d);
	Plane(const Mine::Vector3& p1, const Mine::Vector3& p2);

	Mine::Vector3 N;
	float d;

	float DistanceTo(const Mine::Vector3& p) const;
	
	Mine::Vector3 ClosestPoint(const Mine::Vector3& p) const;

	ePlaneResult TestSide(const Mine::Vector3& p) const;
	ePlaneResult TestSide(const Sphere& sphere) const;
	ePlaneResult TestSide(const AABB& aabb) const;

	void CheckCollision(Collider* other) override;
};