#pragma once

#include "GameObject.h"
#include <vector>

struct Collider {

};

struct AABB : public Collider
	{
		AABB() {}
		AABB(const Mine::Vector3& min, const Mine::Vector3& max) : min(min), max(max) {}

		Mine::Vector3 min, max;
	
		Mine::Vector3 Center() const
		{
			return (min + max) * 0.5f;
		}

		Mine::Vector3 Extents() const
		{
			return { abs(max.x - min.x) * 0.5f,
					abs(max.y - min.y) * 0.5f,
					0 };
		}

		std::vector<Mine::Vector3> Corners() const
		{
			std::vector<Mine::Vector3> corners(4);
			corners[0] = min;
			corners[1] = { min.x, max.y, 0};
			corners[2] = max;
			corners[3] = { max.x, min.y, 0};
			return corners;
		}

		void Fit(const Mine::Vector3* points, unsigned int count)
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

		bool Overlaps(const Mine::Vector3& p) const
		{
					// test for not overlapped as it exits faster
			return !(p.x < min.x || p.y < min.y ||
					 p.x > max.x || p.y > max.y);
		}

		bool Overlaps(const AABB& other) const
		{
					// test for not overlapped as it exits faster
			return !(max.x < other.min.x || max.y < other.min.y ||
					 min.x > other.max.x || min.y > other.max.y);
		}

		Mine::Vector3 ClosestPoint(const Mine::Vector3& p) const
		{
			return Mine::Vector3::clamp(p, min, max);
		}

		bool isEmpty()
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

		void SetToTransformedBox(const Mine::Matrix3& m)
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
	};

	struct Sphere
	{
		Sphere()
		{}
		Sphere(const Mine::Vector3& p, float r) : center(p), radius(r)
		{}

		Mine::Vector3 center;
		float radius;

		void Fit(const Mine::Vector3* points, unsigned int count)
		{
			// invalidate extents
			Mine::Vector3 min = { FLT_MAX, FLT_MAX, 0};
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

		void Fit(const std::vector<Mine::Vector3>& points)
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

		bool Overlaps(const Mine::Vector3& p) const
		{
			Mine::Vector3 toPoint = p - center;
			return toPoint.MagnitudeSqr() <= (radius * radius);
		}

		Mine::Vector3 ClosestPoint(const Mine::Vector3& p) const
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
	};

	struct Plane
	{
		Plane() 
		{

		}
		Plane(float x, float y, float d) : N(x, y, 0), d(d)
		{

		}
		Plane(const Mine::Vector3& n, float d) : N(n), d(d)
		{

		}

		Mine::Vector3 N;
		float d;

		Plane(const Mine::Vector3& p1, const Mine::Vector3& p2)
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

		float DistanceTo(const Mine::Vector3& p) const
		{
			return p.Dot(N) + d;
		}

		Mine::Vector3 ClosestPoint(const Mine::Vector3& p) const
		{
			return p - N * DistanceTo(p);
		}

		enum ePlaneResult : int {
			FRONT = 1,
			BACK = -1,
			INTERSECTS = 0
		};

		ePlaneResult testSide(const Mine::Vector3& p) const
		{
			float t = p.Dot(N) + d;

			if (t < 0)
				return ePlaneResult::BACK;
			else if (t > 0)
				return ePlaneResult::FRONT;

			return ePlaneResult::INTERSECTS;
		}

		ePlaneResult testSide(const Sphere& sphere) const
		{
			float t = DistanceTo(sphere.center);

			if (t > sphere.radius)
				return ePlaneResult::FRONT;
			else if (t < -sphere.radius)
				return ePlaneResult::BACK;

			return ePlaneResult::INTERSECTS;
		}

		ePlaneResult testSide(const AABB& aabb) const
		{
			// tag if we find a corner on each side
			bool side[2] = { false, false };

			// compare each corner
			for (auto c : aabb.Corners())
			{
				auto result = testSide(c);
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
	};