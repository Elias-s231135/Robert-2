#pragma once

//#include "GameObject.h"
//#include <vector>
#include "Colliders.h"

struct AABB;
struct Plane;

struct Sphere : public Collider
{
public:
	
	Mine::Vector3 center;
	float radius;

	Sphere();

	Sphere(const Mine::Vector3& p, float r);

	void Fit(const Mine::Vector3* points, unsigned int count);
	void Fit(const std::vector<Mine::Vector3>& points);

	bool Overlaps(const Mine::Vector3& p) const;
	bool Overlaps(const AABB& aabb) const;
	bool Overlaps(const Sphere& sphere) const;

	Mine::Vector3 ClosestPoint(const Mine::Vector3& p) const;

	void CheckCollision(Collider* other) override;
};