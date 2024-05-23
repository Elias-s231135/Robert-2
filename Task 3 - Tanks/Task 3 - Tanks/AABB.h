#pragma once

//#include "GameObject.h"
//#include <vector>
#include "Colliders.h"

struct AABB : public Collider
{
	AABB();
	AABB(const Mine::Vector3& min, const Mine::Vector3& max) : min(min), max(max);
	
	Mine::Vector3 min, max;

	Mine::Vector3 Center() const;

	Mine::Vector3 Extents() const;

	std::vector<Mine::Vector3> Corners() const;

	void Fit(const Mine::Vector3* points, unsigned int count);

	bool Overlaps(const Mine::Vector3& p) const;
	bool Overlaps(const AABB& other) const;

	Mine::Vector3 ClosestPoint(const Mine::Vector3& p) const;

	bool isEmpty();
	void SetToTransformedBox(const Mine::Matrix3& m);
};