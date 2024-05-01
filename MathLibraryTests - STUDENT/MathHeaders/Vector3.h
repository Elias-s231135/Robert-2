#pragma once

namespace MathClasses
{
    struct Vector3
    {
        // Add the struct data fields and methods, as per the tutorials and exercises, here...
        // ...

        union
        {
            struct { float x, y, z; };
            struct { float r, g, b; };
            float data[3];
        };

        Vector3() : x{ 0 }, y{ 0 }, z{ 0 }
        {

        };

        Vector3(float xx, float yy, float zz)
        {
            x = xx;
            y = yy;
            z = zz;
        };

        float& operator [](int dim)
        {
            return data[dim];
            // allows us to access a chosen axis or dimension
        }

        const float& operator [](int dim) const
        {
            return data[dim];
        }

        operator float* () 
        { 
            return data; 
        }

        operator const float* () const 
        { 
            return data; 
        }

        Vector3 operator +(const Vector3& rhs) const
        {
            Vector3 sum;

            sum.x = x + rhs.x;
            sum.y = y + rhs.y;
            sum.z = z + rhs.z;
        }

        Vector3 operator -(const Vector3& rhs) const
        {
            Vector3 sum;

            sum.x = x - rhs.x;
            sum.y = y - rhs.y;
            sum.z = z - rhs.z;
        }

        Vector3 operator *(const Vector3& rhs) const
        {
            Vector3 sum;

            sum.x = x * rhs.x;
            sum.y = y * rhs.y;
            sum.z = z * rhs.z;
        }

        // ...
	};
}