#include "Border.h"
#include "Sphere.h"
#include "AABB.h"
#include "Plane.h"

Border::Border()
{
	BorderT();
	BorderR();
	BorderB();
	BorderL();
}

void Border::BorderT()
{
	m_collider = new Plane(cornerTopLeft, cornerTopRight);
	m_collider->m_owner = this;
}

void Border::BorderR()
{
	m_collider = new Plane(cornerTopRight, cornerBottomRight);
	m_collider->m_owner = this;
}

void Border::BorderB()
{
	m_collider = new Plane(cornerBottomLeft, cornerBottomRight);
	m_collider->m_owner = this;
}

void Border::BorderL()
{
	m_collider = new Plane(cornerTopLeft, cornerBottomRight);
	m_collider->m_owner = this;
}

void Border::OnDraw()
{

}