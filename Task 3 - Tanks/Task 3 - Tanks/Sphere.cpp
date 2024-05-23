//#include "GameObject.h"
//#include <vector>
//#include "Colliders.h"
#include "Sphere.h"
#include "AABB.h"
#include"Plane.h"

Sphere::Sphere()
{

}

Sphere::Sphere(const Mine::Vector3& p, float r) : center(p), radius(r)
{

}

void Sphere::Fit(const Mine::Vector3* points, unsigned int count)
{
	// invalidate extents
	Mine::Vector3 min = { FLT_MAX, FLT_MAX, 0 };
	Mine::Vector3 max = { -FLT_MAX, -FLT_MAX, 0 };

	// find min and max of the points
	for (unsigned int i = 0; i < count; ++i, ++points)
	{
		min = Mine::Vector3::min(min, *points);
		max = Mine::Vector3::max(max, *points);
	}

	// put a circle around the min/max box
	center = (min + max) * 0.5f;
	radius = center.Distance(max);
}

void Sphere::Fit(const std::vector<Mine::Vector3>& points)
{
	// invalidate extents
	Mine::Vector3 min = { FLT_MAX, FLT_MAX, 0 };
	Mine::Vector3 max = { -FLT_MAX, -FLT_MAX, 0 };

	// find min and max of the points
	for (auto& p : points)
	{
		min = Mine::Vector3::min(min, p);
		max = Mine::Vector3::max(max, p);
	}

	// put a circle around the min/max box
	center = (min + max) * 0.5f;
	radius = center.Distance(max);
}

bool Sphere::Overlaps(const Mine::Vector3& p) const
{
	Mine::Vector3 toPoint = p - center;
	return toPoint.MagnitudeSqr() <= (radius * radius);
}

bool Sphere::Overlaps(const AABB& aabb) const
{
	auto diff = aabb.ClosestPoint(center) - center;
	return diff.Dot(diff) <= (radius * radius);
}

bool Sphere::Overlaps(const Sphere& sphere) const
{
	auto diff = sphere.ClosestPoint(center) - center;
	return diff.Dot(diff) <= (radius * radius);
}

Mine::Vector3 Sphere::ClosestPoint(const Mine::Vector3& p) const
{
	// distance from center
	Mine::Vector3 toPoint = p - center;

	// if outside of radius bring it back to the radius
	if (toPoint.MagnitudeSqr() > radius * radius)
	{
		toPoint = toPoint.Normalised() * radius;
	}

	return center + toPoint;
}

void Sphere::CheckCollision(Collider* other)
{
	Sphere* sphere = static_cast<Sphere*>(other);
	nullptr;
	if (sphere == nullptr)
	{
		AABB* aabb = static_cast<AABB*>(other);
		if (aabb == nullptr)
		{
			Plane* plane = static_cast<Plane*>(other);
			if (plane != nullptr)
			{
				//Checking to see if this sphere 'collides" with a plane
				if (plane->TestSide(*this) == Plane::ePlaneResult::INTERSECTS)
				{
					m_owner->OnCollision();
				}
			}
		}
		else if (other == aabb)
		{
			//check to see if we collide with an aabb
			if (this->Overlaps(*aabb) == true)
			{
				m_owner->OnCollision();
			}
		}
	}
	else if (other == sphere)
	{
		//check to see if we collide with another sphere
		if (this->Overlaps(*sphere))
		{
			m_owner->OnCollision();
		}
	}
}