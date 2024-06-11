#pragma once
#include <string>
#include "Vector4.h"

namespace MathClasses
{
    struct Matrix4
    {

        union
        {
            struct
            {
                float m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15, m16;
            };
            float v[16];
            float mm[4][4];
            Vector4 axis[4];
        };

        Matrix4()
        {
            m1 = m2 = m3 = m4 = m5 = m6 = m7 = m8 = m9 = m10 = m11 = m12 = m13 = m14 = m15 = m16 = 0.0f;
        }

        Matrix4(float mm1, float mm2, float mm3, float mm4, float mm5, float mm6, float mm7, float mm8, float mm9, float mm10, float mm11, float mm12, float mm13, float mm14, float mm15, float mm16)
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
            m10 = mm10;
            m11 = mm11;
            m12 = mm12;

            m13 = mm13;
            m14 = mm14;
            m15 = mm15;
            m16 = mm16;
        }

        Matrix4(float inputs[])
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
            m10 = inputs[9];
            m11 = inputs[10];
            m12 = inputs[11];

            m13 = inputs[12];
            m14 = inputs[13];
            m15 = inputs[14];
            m16 = inputs[15];
        }

        static Matrix4 MakeIdentity()
        {
            Matrix4 identity;
            identity.m1 = 1;
            identity.m2 = 0;
            identity.m3 = 0;
            identity.m4 = 0;

            identity.m5 = 0;
            identity.m6 = 1;
            identity.m7 = 0;
            identity.m8 = 0;

            identity.m9 = 0;
            identity.m10 = 0;
            identity.m11 = 1;
            identity.m12 = 0;

            identity.m13 = 0;
            identity.m14 = 0;
            identity.m15 = 0;
            identity.m16 = 1;

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

        Matrix4 operator *(Matrix4 rhs) const
        {
            Matrix4 result;

            for (size_t i = 0; i < 4; ++i)
            {
                Vector4 row(mm[0][i], mm[1][i], mm[2][i], mm[3][i]);

                for (size_t j = 0; j < 4; ++j)
                {
                    result.mm[j][i] = row.Dot(rhs.axis[j]);
                }
            }
            return result;
        }

        Vector4 operator *(Vector4 rhs) const
        {
            return Vector4(
                Vector4(m1, m5, m9, m13).Dot(rhs),
                Vector4(m2, m6, m10, m14).Dot(rhs),
                Vector4(m3, m7, m11, m15).Dot(rhs),
                Vector4(m4, m8, m12, m16).Dot(rhs)
            );
        }

        Matrix4 operator *=(Matrix4 rhs)
        {
            for (size_t i = 0; i < 4; ++i)
            {
                Vector4 row(mm[0][i], mm[1][i], mm[2][i], mm[3][i]);

                for (size_t j = 0; j < 4; ++j)
                {
                    //mm[9];
                    //rhs column = rhs.axis[0]
                    //new mm1 = row dot product rhs axis[0]
                    // mm4 = calculated row dot product rhs axis[1]
                    mm[j][i] = row.Dot(rhs.axis[j]);
                }
            }
        }

        Matrix4& operator =(const Matrix4& rhs)
        {
            for (int i = 0; i < 16; i++)
            {
                this->v[i] = rhs.v[i];
            }

            return *this;
        }

        bool operator ==(Matrix4 rhs) const
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
            float m10Dist = fabsf(m10 - rhs.m10);
            float m11Dist = fabsf(m11 - rhs.m11);
            float m12Dist = fabsf(m12 - rhs.m12);
            float m13Dist = fabsf(m13 - rhs.m13);
            float m14Dist = fabsf(m14 - rhs.m14);
            float m15Dist = fabsf(m15 - rhs.m15);
            float m16Dist = fabsf(m16 - rhs.m16);

            const float THRESHOLD = 0.00001f;

            return m1Dist < THRESHOLD && m2Dist < THRESHOLD && m3Dist < THRESHOLD && m4Dist < THRESHOLD && m5Dist < THRESHOLD && m6Dist < THRESHOLD && m7Dist < THRESHOLD && m8Dist < THRESHOLD && m9Dist < THRESHOLD && m10Dist < THRESHOLD && m11Dist < THRESHOLD && m12Dist < THRESHOLD && m13Dist < THRESHOLD && m14Dist < THRESHOLD && m15Dist < THRESHOLD && m16Dist < THRESHOLD;
        }

        bool operator!=(Matrix4 rhs) const
        {
            return !(*this == rhs);
        }

        Matrix4 Transposed() const
        {
            return Matrix4(m1, m5, m9, m13, m2, m6, m10, m14, m3, m7, m11, m15, m4, m8, m12, m16);
        }

        std::string ToString() const
        {
            std::string str = std::to_string(v[0]);
            for (size_t i = 1; i < 16; ++i)
            {
                str += ", " + std::to_string(v[i]);
            }
            return str;
        }

        static Matrix4 MakeRotateX(float a)
        {
            return Matrix4(1, 0, 0, 0,
                           0, cosf(a), -sinf(a), 0,
                           0, sinf(a), cosf(a), 0,
                           0, 0, 0, 1);
        }

        static Matrix4 MakeRotateY(float a)
        {
            return Matrix4(cosf(a), 0, sinf(a), 0, 
                           0, 1, 0, 0, 
                           -sinf(a), 0, cosf(a), 0,
                           0, 0, 0, 1);
        }

        static Matrix4 MakeRotateZ(float a)
        {
            return Matrix4(cosf(a), sinf(a), 0, 0,
                           -sinf(a), cosf(a), 0, 0,
                           0, 0, 1, 0,
                           0, 0, 0, 1);
        }

        static Matrix4 MakeEuler(float pitch, float yaw, float roll)
        {
            Matrix4 x = MakeRotateX(pitch);
            Matrix4 y = MakeRotateY(yaw);
            Matrix4 z = MakeRotateZ(roll);

            return (z * y * x);
        }

        static Matrix4 MakeEuler(Vector3 victor)
        {
            return MakeEuler(victor.x, victor.y, victor.z);
        }

        static Matrix4 MakeScale(float xScale, float yScale)
        {
            return Matrix4(xScale, 0.0f, 0.0f, 0.0f,
                0.0f, yScale, 0.0f, 0.0f,
                0.0f, 0.0f, 1.0f, 0.0f,
                0.0f, 0.0f, 0.0f, 1.0f);
        }

        static Matrix4 MakeScale(float xScale, float yScale, float zScale)
        {
            return Matrix4(xScale, 0.0f, 0.0f, 0.0f,
                0.0f, yScale, 0.0f, 0.0f,
                0.0f, 0.0f, zScale, 0.0f,
                0.0f, 0.0f, 0.0f, 1.0f);
        }

        static Matrix4 MakeScale(Vector3 scale)
        {
            return MakeScale(scale.x, scale.y, scale.z);
        }

        static Matrix4 MakeTranslation(float tx, float ty, float tz)
        {
            return Matrix4(1.0f, 0.0f, 0.0f, 0.0f,
                           0.0f, 1.0f, 0.0f, 0.0f,
                           0.0f, 0.0f, 1.0f, 0.0f,
                           tx, ty, tz, 1.0f);
        }

        static Matrix4 MakeTranslation(Vector3 t)
        {
            return MakeTranslation(t.x, t.y, t.z);
        }
    };
}