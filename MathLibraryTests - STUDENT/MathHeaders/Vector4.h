#pragma once
#include <string>

namespace MathClasses
{
    struct Vector4
    {
        // Add the struct data fields and methods, as per the tutorials and exercises, here...
        // ...

        union
        {
            struct { float x, y, z, w; };
            struct { float r, g, b, a; };
            float data[4];
        };

        Vector4() : x{ 0 }, y{ 0 }, z{ 0 }, w{ 0 }
        {

        };

        Vector4(float xx, float yy, float zz, float ww)
        {
            x = xx;
            y = yy;
            z = zz;
            w = ww;
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

        Vector4 operator +(const Vector4& rhs) const
        {
            Vector4 sum;

            sum.x = x + rhs.x;
            sum.y = y + rhs.y;
            sum.z = z + rhs.z;
            sum.w = w + rhs.w;

            return sum;
        }

        Vector4 operator -(const Vector4& rhs) const
        {
            Vector4 sum;

            sum.x = x - rhs.x;
            sum.y = y - rhs.y;
            sum.z = z - rhs.z;
            sum.w = w - rhs.w;

            return sum;
        }

        Vector4 operator *(float rhs) const
        {
            Vector4 sum;

            sum.x = x * rhs;
            sum.y = y * rhs;
            sum.z = z * rhs;
            sum.w = w * rhs;

            return sum;
        }

        static friend Vector4 operator *(const float lhs, const Vector4& rhs)
        {
            Vector4 sum;

            sum.x = lhs * rhs.x;
            sum.y = lhs * rhs.y;
            sum.z = lhs * rhs.z;
            sum.w = lhs * rhs.w;

            return sum;
        }

        Vector4 operator /(float rhs) const
        {
            Vector4 sum;

            if (rhs == 0)
            {
                sum.x = 0;
                sum.y = 0;
                sum.z = 0;
                sum.w = 0;

                return sum;
            }

            sum.x = x / rhs;
            sum.y = y / rhs;
            sum.z = z / rhs;
            sum.w = w / rhs;

            return sum;
        }

        void operator =(const Vector4& rhs)
        {
            x = rhs.x;
            y = rhs.y;
            z = rhs.z;
            w = rhs.w;
        }

        void operator +=(const Vector4& rhs)
        {
            x += rhs.x;
            y += rhs.y;
            z += rhs.z;
            w += rhs.w;
        }

        void operator -=(const Vector4& rhs)
        {
            x -= rhs.x;
            y -= rhs.y;
            z -= rhs.z;
            w -= rhs.w;
        }

        void operator *=(const Vector4& rhs)
        {
            x *= rhs.x;
            y *= rhs.y;
            z *= rhs.z;
            w *= rhs.w;
        }

        void operator /=(const Vector4 rhs)
        {
            if (x == 0 || y == 0 || z == 0 || w == 0)
            {
                x = 0;
                y = 0;
                z = 0;
                w = 0;

                return;
            }

            x /= rhs.x;
            y /= rhs.y;
            z /= rhs.z;
            w /= rhs.w;
        }

        bool operator ==(const Vector4 rhs)
        {
            if (x == rhs.x && y == rhs.y && z == rhs.z && w == rhs.w)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        bool operator !=(const Vector4 rhs)
        {
            if (x != rhs.x && y != rhs.y && z != rhs.z && w != rhs.w)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        bool operator ==(const Vector4& rhs) const
        {
            float xDist = fabsf(x - rhs.x);
            float yDist = fabsf(y - rhs.y);
            float zDist = fabsf(z - rhs.z);
            float wDist = fabsf(w - rhs.w);

            const float THRESHOLD = 0.00001f;

            return xDist < THRESHOLD && yDist < THRESHOLD && zDist < THRESHOLD;
        }

        bool operator !=(const Vector4& rhs) const
        {
            return !(*this == rhs);
        }

        std::string ToString() const
        {
            return std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z) + ", " + std::to_string(w);
        }

        float Magnitude() const
        {
            return sqrtf(x * x + y * y + z * z + w * w);
        }

        float MagnitudeSqr() const
        {
            return x * x + y * y + z * z + w * w;
        }

        float Distance(const Vector4& other) const
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
            w /= m;
        }

        Vector4 Normalised() const
        {
            Vector4 copy = *this;
            copy.Normalise();

            return copy;
        }

        float Dot(const Vector4& other)
        {
            return x * other.x + y * other.y + z * other.z + w * other.w;
        }

        Vector4 Cross(const Vector4& other)
        {
            return Vector4(y * other.z - z * other.y,
                           z * other.x - x * other.z,
                           x * other.y - y * other.x,
                           0);
        }

        float AngleBetween(const Vector4& other) const
        {
            Vector4 a = Normalised();
            Vector4 b = other.Normalised();

            float d = a.Dot(other);

            return acosf(d);
        }


    };
}