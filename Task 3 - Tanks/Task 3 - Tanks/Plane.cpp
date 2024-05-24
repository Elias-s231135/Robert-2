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

Plane::ePlaneResult Plane::TestSide(const Mine::Vector3& p) const
{
	float t = p.Dot(N) + d;

	if (t < 0)
		return Plane::ePlaneResult::BACK;
	else if (t > 0)
		return Plane::ePlaneResult::FRONT;

	return Plane::ePlaneResult::INTERSECTS;
}

Plane::ePlaneResult Plane::TestSide(const Sphere& sphere) const
{
	float t = DistanceTo(sphere.center);

	if (t > sphere.radius)
		return Plane::ePlaneResult::FRONT;
	else if (t < -sphere.radius)
		return Plane::ePlaneResult::BACK;

	return Plane::ePlaneResult::INTERSECTS;
}

Plane::ePlaneResult Plane::TestSide(const AABB& aabb) const
{
	// tag if we find a corner on each side
	bool side[2] = { false, false };

	// compare each corner
	for (auto c : aabb.Corners())
	{
		auto result = Plane::TestSide(c);
		if (result == Plane::ePlaneResult::FRONT)
			side[0] = true;
		else if (result == Plane::ePlaneResult::BACK)
			side[1] = true;
	}

	// if front but not back
	if (side[0] && !side[1])
		return Plane::ePlaneResult::FRONT;
	// if back but not front
	else if (!side[0] && !side[1])
		return Plane::ePlaneResult::BACK;
	// else overlapping
	return Plane::ePlaneResult::INTERSECTS;
}

void Plane::CheckCollision(Collider* other)
{
	Sphere* sphere = static_cast<Sphere*>(other);
	nullptr;
	if (sphere == nullptr)
	{
		AABB* aabb = static_cast<AABB*>(other);
		if (other == aabb)
		{
			//Checking to see if this plane 'collides" with an aabb
			if (TestSide(*aabb) == Plane::ePlaneResult::INTERSECTS)
			{
				m_owner->OnCollision();
			}
		}
	}
	else if (other == sphere)
	{
		//Checking to see if this plane 'collides" with a sphere
		if (TestSide(*sphere) == Plane::ePlaneResult::INTERSECTS)
		{
			m_owner->OnCollision();
		}
	}
}