#pragma once

class Circle
{
public:
	void SetRadius(float f);
	float GetRadius();
	float GetArea();
	float GetCircumference();

private:
	float m_radius;
};