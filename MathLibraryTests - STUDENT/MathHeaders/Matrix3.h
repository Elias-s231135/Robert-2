#pragma once
#include <string>

namespace MathClasses
{
    struct Matrix3
    {
     
        union 
        {
            struct
            {
                float m1, m2, m3, m4, m5, m6, m7, m8, m9;
            };
            float v[9];
            float mm[3][3];
            Vector3 axis[3];
        };

        Matrix3()
        {
            m1 = m2 = m3 = m4 = m5 = m6 = m7 = m8 = m9 = 0.0f;
        }

        Matrix3(float mm1, float mm2, float mm3, float mm4, float mm5, float mm6, float mm7, float mm8, float mm9)
        {
            m1 = mm1;
            m2 = mm2;
            m3 = mm3;

            m4 = mm4;
            m5 = mm5;
            m6 = mm6;

            m7 = mm7;
            m8 = mm8;
            m9 = mm9;
        }

        Matrix3(float inputs[])
        {
            m1 = inputs[0];
            m2 = inputs[1];
            m3 = inputs[2];

            m4 = inputs[3];
            m5 = inputs[4];
            m6 = inputs[5];

            m7 = inputs[6];
            m8 = inputs[7];
            m9 = inputs[8];
        }

        static Matrix3 MakeIdentity()
        {
            Matrix3 identity;
            identity.m1 = 1;
            identity.m2 = 0;
            identity.m3 = 0;

            identity.m4 = 0;
            identity.m5 = 1;
            identity.m6 = 0;

            identity.m7 = 0;
            identity.m8 = 0;
            identity.m9 = 1;

            return identity;
        }

        float& operator [](int dim)
        {
            return v[dim];
        }

        const float& operator [](int dim) const
        {
            return v[dim];
        }

        operator float* ()
        {
            return v;
        }

        operator const float* () const
        {
            return v;
        }

        Matrix3 operator *(Matrix3 rhs) const
        {
            Matrix3 result;

            for (size_t i = 0; i < 3; ++i)
            {
                Vector3 row(mm[0][i], mm[1][i], mm[2][i]);

                for (size_t j = 0; j < 3; ++j)
                {
                    result.mm[j][i] = row.Dot(rhs.axis[j]);
                }
            }
            return result;
        }

        Vector3 operator *(Vector3 rhs) const
        {
            return Vector3(
                Vector3(m1, m4, m7).Dot(rhs),
                Vector3(m2, m5, m8).Dot(rhs),
                Vector3(m3, m6, m9).Dot(rhs)
            );
        }
        
        Matrix3 operator *=(Matrix3 rhs)
        {
            for (size_t i = 0; i < 3; ++i)
            {
                Vector3 row(mm[0][i], mm[1][i], mm[2][i]);

                for (size_t j = 0; j < 3; ++j)
                {
                    //mm[9];
                    //rhs column = rhs.axis[0]
                    //new mm1 = row dot product rhs axis[0]
                    // mm4 = calculated row dot product rhs axis[1]
                    mm[j][i] = row.Dot(rhs.axis[j]);
                }
            }
        }

        Matrix3& operator =(const Matrix3& rhs)
        {
            for (int i = 0; i < 9; i++)
            {
                this->v[i] = rhs.v[i];
            }

            return *this;
        }

        bool operator ==(Matrix3 rhs) const
        {
            float m1Dist = fabsf(m1 - rhs.m1);
            float m2Dist = fabsf(m2 - rhs.m2);
            float m3Dist = fabsf(m3 - rhs.m3);
            float m4Dist = fabsf(m4 - rhs.m4);
            float m5Dist = fabsf(m5 - rhs.m5);
            float m6Dist = fabsf(m6 - rhs.m6);
            float m7Dist = fabsf(m7 - rhs.m7);
            float m8Dist = fabsf(m8 - rhs.m8);
            float m9Dist = fabsf(m9 - rhs.m9);

            const float THRESHOLD = 0.00001f;

            return m1Dist < THRESHOLD && m2Dist < THRESHOLD && m3Dist < THRESHOLD && m4Dist < THRESHOLD && m5Dist < THRESHOLD && m6Dist < THRESHOLD && m7Dist < THRESHOLD && m8Dist < THRESHOLD && m9Dist < THRESHOLD;
        }

        bool operator!=(Matrix3 rhs) const
        {
            return !(*this == rhs);
        }

        Matrix3 Transposed() const
        {
            return Matrix3(m1, m4, m7, m2, m5, m8, m3, m6, m9);
        }

        std::string ToString() const
        {
            std::string str = std::to_string(v[0]);
            for (size_t i = 1; i < 9; ++i)
            {
                str += ", " + std::to_string(v[i]);
            }
            return str;
        }

        static Matrix3 MakeRotateX(float a)
        {
            return Matrix3(1, 0, 0,
                           0, cosf(a), -sinf(a),
                           0, sinf(a), cosf(a));
        }

        static Matrix3 MakeRotateY(float a)
        {
            return Matrix3(cosf(a), 0, sinf(a),
                           0, 1, 0,
                           -sinf(a), 0, cosf(a));
        }

        static Matrix3 MakeRotateZ(float a)
        {
            return Matrix3(cosf(a), sinf(a), 0,
                           -sinf(a), cosf(a), 0,
                           0, 0, 1);
        }

        static Matrix3 MakeEuler(float pitch, float yaw, float roll)
        {
            Matrix3 x = MakeRotateX(pitch);
            Matrix3 y = MakeRotateY(yaw);
            Matrix3 z = MakeRotateZ(roll);

            return (z * y * x);
        }

        static Matrix3 MakeEuler(Vector3 victor)
        {
            return MakeEuler(victor.x, victor.y, victor.z);
        }

        static Matrix3 MakeScale(float xScale, float yScale)
        {
            return Matrix3(xScale, 0.0f, 0.0f,
                0.0f, yScale, 0.0f,
                0.0f, 0.0f, 1.0f);
        }

        static Matrix3 MakeScale(float xScale, float yScale, float zScale)
        {
            return Matrix3(xScale, 0.0f, 0.0f,
                           0.0f, yScale, 0.0f,
                           0.0f, 0.0f, zScale);
        }

        static Matrix3 MakeScale(Vector3 scale)
        {
            return MakeScale(scale.x, scale.y, scale.z);
        }


  	};
}