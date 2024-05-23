#include "Plane.h"
#include "Sphere.h"
#include "AABB.h"

Plane::Plane()
{

}
Plane::Plane(float x, float y, float d) : N(x, y, 0), d(d)
{

}
Plane::Plane(const Mine::Vector3& n, float d) : N(n), d(d)
{

}


Plane::Plane(const Mine::Vector3& p1, const Mine::Vector3& p2)
{
	// calculate normalised vector from p0 to p1
	auto v = p2 - p1;
	v.Normalise();

	// set normal perpendicular to the vector
	N.x = -v.y;
	N.y = v.x;

	// calculate d
	d = -p1.Dot(N);
}

float Plane::DistanceTo(const Mine::Vector3& p) const
{
	return p.Dot(N) + d;
}

Mine::Vector3 Plane::ClosestPoint(const Mine::Vector3& p) const
{
	return p - N * DistanceTo(p);
}

enum ePlaneResult : int
{
	FRONT = 1,
	BACK = -1,
	INTERSECTS = 0
};

ePlaneResult TestSide(const Mine::Vector3& p) const
{
	float t = p.Dot(N) + d;

	if (t < 0)
		return ePlaneResult::BACK;
	else if (t > 0)
		return ePlaneResult::FRONT;

	return ePlaneResult::INTERSECTS;
}

ePlaneResult TestSide(const Sphere& sphere) const
{
	float t = DistanceTo(sphere.center);

	if (t > sphere.radius)
		return ePlaneResult::FRONT;
	else if (t < -sphere.radius)
		return ePlaneResult::BACK;

	return ePlaneResult::INTERSECTS;
}

ePlaneResult TestSide(const AABB& aabb) const
{
	// tag if we find a corner on each side
	bool side[2] = { false, false };

	// compare each corner
	for (auto c : aabb.Corners())
	{
		auto result = TestSide(c);
		if (result == ePlaneResult::FRONT)
			side[0] = true;
		else if (result == ePlaneResult::BACK)
			side[1] = true;
	}

	// if front but not back
	if (side[0] && !side[1])
		return ePlaneResult::FRONT;
	// if back but not front
	else if (!side[0] && !side[1])
		return ePlaneResult::BACK;
	// else overlapping
	return ePlaneResult::INTERSECTS;
}