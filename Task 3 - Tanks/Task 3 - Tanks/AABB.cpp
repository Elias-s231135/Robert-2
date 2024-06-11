#include "AABB.h"
#include "Plane.h"
#include "Sphere.h"

AABB::AABB() 
{

}

AABB::AABB(const Mine::Vector3& min, const Mine::Vector3& max) : min(min), max(max)
{

}

Mine::Vector3 AABB::Center() const
{
	return (min + max) * 0.5f;
}

Mine::Vector3 AABB::Extents() const
{
	return { abs(max.x - min.x) * 0.5f,
			abs(max.y - min.y) * 0.5f,
			0 };
}

std::vector<Mine::Vector3> AABB::Corners() const
{
	std::vector<Mine::Vector3> corners(4);
	corners[0] = min;
	corners[1] = { min.x, max.y, 0 };
	corners[2] = max;
	corners[3] = { max.x, min.y, 0 };
	return corners;
}

void AABB::Fit(const Mine::Vector3* points, unsigned int count)
{
	// invalidate the extents
	min = { FLT_MAX, FLT_MAX, 0 };
	max = { -FLT_MAX, -FLT_MAX, 0 };

	// find min and max of the points
	for (unsigned int i = 0; i < count; ++i, ++points)
	{
		min = Mine::Vector3::min(min, *points);
		max = Mine::Vector3::max(max, *points);
	}
}

bool AABB::Overlaps(const Mine::Vector3& p) const
{
	// test for not overlapped as it exits faster
	return !(p.x < min.x || p.y < min.y ||
		p.x > max.x || p.y > max.y);
}

bool AABB::Overlaps(const AABB& other) const
{
	// test for not overlapped as it exits faster
	return !(max.x < other.min.x || max.y < other.min.y ||
		min.x > other.max.x || min.y > other.max.y);
}

bool AABB::Overlaps(const Sphere& sphere) const
{
	return sphere.Overlaps(*this);
}

Mine::Vector3 AABB::ClosestPoint(const Mine::Vector3& p) const
{
	return Mine::Vector3::clamp(p, min, max);
}

bool AABB::isEmpty()
{
	//Checks to see if the AABB is logically void of points

	//min = { FLT_MAX, FLT_MAX, 0 };
	//max = { -FLT_MAX, -FLT_MAX, 0 };

	if (min == Mine::Vector3(FLT_MAX, FLT_MAX, 0) && max == Mine::Vector3(-FLT_MAX, -FLT_MAX, 0))
	{
		return true;
	}
	return false;
}

void AABB::SetToTransformedBox(const Mine::Matrix3& m)
{
	// If we're empty, then exit (an empty box defined as having the min/max
	// set to infinity)
	if (isEmpty())
	{
		return;
	}

	// Examine each of the nine matrix elements
	// and compute the new AABB
	// 1
	if (m.m1 > 0.0f)
	{
		min.x += m.m1 * min.x;
		max.x += m.m1 * max.x;
	}
	else
	{
		min.x += m.m1 * max.x;
		max.x += m.m1 * min.x;
	}
	// 4
	if (m.m4 > 0.0f)
	{
		min.x += m.m4 * min.x;
		max.x += m.m4 * max.x;
	}
	else
	{
		min.x += m.m4 * max.x;
		max.x += m.m4 * min.x;
	}
	// 7
	if (m.m7 > 0.0f)
	{
		min.x += m.m7 * min.x;
		max.x += m.m7 * max.x;
	}
	else
	{
		min.x += m.m7 * max.x;
		max.x += m.m7 * min.x;
	}
	// 2
	if (m.m2 > 0.0f)
	{
		min.x += m.m2 * min.x;
		max.x += m.m2 * max.x;
	}
	else
	{
		min.x += m.m2 * max.x;
		max.x += m.m2 * min.x;
	}
	// 5
	if (m.m5 > 0.0f)
	{
		min.x += m.m5 * min.x;
		max.x += m.m5 * max.x;
	}
	else
	{
		min.x += m.m5 * max.x;
		max.x += m.m5 * min.x;
	}
	// 8
	if (m.m8 > 0.0f)
	{
		min.x += m.m8 * min.x;
		max.x += m.m8 * max.x;
	}
	else
	{
		min.x += m.m8 * max.x;
		max.x += m.m8 * min.x;
	}
	// 3
	if (m.m3 > 0.0f)
	{
		min.x += m.m3 * min.x;
		max.x += m.m3 * max.x;
	}
	else
	{
		min.x += m.m3 * max.x;
		max.x += m.m3 * min.x;
	}
	// 6
	if (m.m6 > 0.0f)
	{
		min.x += m.m6 * min.x;
		max.x += m.m6 * max.x;
	}
	else
	{
		min.x += m.m6 * max.x;
		max.x += m.m6 * min.x;
	}
	// 9
	if (m.m9 > 0.0f)
	{
		min.x += m.m9 * min.x;
		max.x += m.m9 * max.x;
	}
	else
	{
		min.x += m.m9 * max.x;
		max.x += m.m9 * min.x;
	}
}

void AABB::CheckCollision(Collider* other)
{
	Sphere* sphere = dynamic_cast<Sphere*>(other);
	if (sphere == nullptr)
	{
		AABB* aabb = dynamic_cast<AABB*>(other);
		if (aabb == nullptr)
		{
			Plane* plane = dynamic_cast<Plane*>(other);
			if (plane != nullptr)
			{
				//Checking to see if this AABB 'collides" with a plane
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