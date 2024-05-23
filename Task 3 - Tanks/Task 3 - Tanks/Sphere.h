#pragma once

//#include "GameObject.h"
//#include <vector>
#include "Colliders.h"

struct Sphere : public Collider
{
	Sphere();

	Sphere(const Mine::Vector3& p, float r);


	Mine::Vector3 center;
	float radius;

	void Fit(const Mine::Vector3* points, unsigned int count);
	void Fit(const std::vector<Mine::Vector3>& points);

	bool Overlaps(const Mine::Vector3& p) const;
	bool Overlaps(const AABB& aabb) const;
	bool Overlaps(const Sphere& sphere) const;

	Mine::Vector3 ClosestPoint(const Mine::Vector3& p) const;

	void CheckCollision(Collider* other) override;
};