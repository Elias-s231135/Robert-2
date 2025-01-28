#pragma once

//#include "GameObject.h"
//#include <vector>
#include "Colliders.h"

struct Sphere;
struct Plane;

struct AABB : public Collider
{
public:
	
	Mine::Vector3 min, max;

public:

	AABB();
	AABB(const Mine::Vector3& min, const Mine::Vector3& max);
	
	Mine::Vector3 Center() const;

	Mine::Vector3 Extents() const;

	std::vector<Mine::Vector3> Corners() const;

	void Fit(const Mine::Vector3* points, unsigned int count);

	bool Overlaps(const Mine::Vector3& p) const;
	bool Overlaps(const AABB& other) const;
	bool Overlaps(const Sphere& sphere) const;

	Mine::Vector3 ClosestPoint(const Mine::Vector3& p) const;

	bool isEmpty();
	void SetToTransformedBox(const Mine::Matrix3& m);

	void CheckCollision(Collider* other) override;
};