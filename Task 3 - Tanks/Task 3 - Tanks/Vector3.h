#pragma once
#include <string>

namespace Mine
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

            return sum;
        }

        Vector3 operator -(const Vector3& rhs) const
        {
            Vector3 sum;

            sum.x = x - rhs.x;
            sum.y = y - rhs.y;
            sum.z = z - rhs.z;

            return sum;
        }

        Vector3 operator *(float rhs) const
        {
            Vector3 sum;

            sum.x = x * rhs;
            sum.y = y * rhs;
            sum.z = z * rhs;

            return sum;
        }

        static friend Vector3 operator *(const float lhs, const Vector3& rhs)
        {
            Vector3 sum;

            sum.x = lhs * rhs.x;
            sum.y = lhs * rhs.y;
            sum.z = lhs * rhs.z;

            return sum;
        }

        Vector3 operator /(float rhs) const
        {
            Vector3 sum;

            if (rhs == 0)
            {
                sum.x = 0;
                sum.y = 0;
                sum.z = 0;
     
                return sum;
            }

            sum.x = x / rhs;
            sum.y = y / rhs;
            sum.z = z / rhs;

            return sum;
        }

        void operator =(const Vector3& rhs)
        {
            x = rhs.x;
            y = rhs.y;
            z = rhs.z;
        }

        void operator +=(const Vector3& rhs)
        {
            x += rhs.x;
            y += rhs.y;
            z += rhs.z;
        }

        void operator -=(const Vector3& rhs)
        {
            x -= rhs.x;
            y -= rhs.y;
            z -= rhs.z;
        }

        void operator *=(const Vector3& rhs)
        {
            x *= rhs.x;
            y *= rhs.y;
            z *= rhs.z;
        }

        void operator /=(const Vector3 rhs)
        {
            if (x == 0 || y == 0 || z == 0)
            {
                x = 0;
                y = 0;
                z = 0;
                
                return;
            }
            
            x /= rhs.x;
            y /= rhs.y;
            z /= rhs.z;
        }

        bool operator ==(const Vector3 rhs)
        {
            if (x == rhs.x && y == rhs.y && z == rhs.z)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        bool operator !=(const Vector3 rhs)
        {
            if (x != rhs.x && y != rhs.y && z != rhs.z)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        bool operator ==(const Vector3& rhs) const
        {
            float xDist = fabsf(x - rhs.x);
            float yDist = fabsf(y - rhs.y);
            float zDist = fabsf(z - rhs.z);

            const float THRESHOLD = 0.00001f;

            return xDist < THRESHOLD && yDist < THRESHOLD && zDist < THRESHOLD;
        }

        bool operator !=(const Vector3& rhs) const
        {
            return !(*this == rhs);
        }

        std::string ToString() const
        {
            return std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z);
        }

        float Magnitude() const
        {
            return sqrtf(x * x + y * y + z * z);
        }

        float MagnitudeSqr() const
        {
            return x * x + y * y + z * z;
        }

        float Distance(const Vector3& other) const
        {
            return (*this - other).Magnitude();
        }

        void Normalise()
        {
            float m = Magnitude();

            if (m == 0)
            {
                m = 0;

                return;
            }

            x /= m;
            y /= m;
            z /= m;

        }

        Vector3 Normalised() const
        {
            Vector3 copy = *this;
            copy.Normalise();

            return copy;
        }

        float Dot(const Vector3& other) const
        {
            return x * other.x + y * other.y + z * other.z;
        }

        Vector3 Cross(const Vector3& other)
        {
            return Vector3(y * other.z - z * other.y,
                z * other.x - x * other.z,
                x * other.y - y * other.x);
        }

        float AngleBetween(const Vector3& other) const
        {
            Vector3 a = Normalised();
            Vector3 b = other.Normalised();

            float d = a.Dot(other);

            return acosf(d);
        }

        static constexpr float min(float a, float b)
        {
            return a < b ? a : b;
        }

        static constexpr float max(float a, float b)
        {
            return a > b ? a : b;
        }

        static Vector3 min(const Vector3& a, const Vector3& b)
        {
            return { min(a.x, b.x), min(a.y, b.y), min(a.z, b.z)};
        }

        static Vector3 max(const Vector3& a, const Vector3& b)
        {
            return { max(a.x, b.x), max(a.y, b.y), max(a.z, b.z) };
        }

        static constexpr float clamp(float t, float a, float b)
        {
            return max(a, min(b, t));
        }

       static Vector3 clamp(const Vector3& t, const Vector3& a, const Vector3& b)
        {
            return max(a, min(b, t));
        }
    };
}