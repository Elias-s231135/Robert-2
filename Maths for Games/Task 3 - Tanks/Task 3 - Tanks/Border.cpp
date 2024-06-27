#include "Border.h"
#include "Plane.h"




Border::Border(Mine::Vector3 start, Mine::Vector3 end)
{
	/*BorderTop::BorderTop();
	BorderRight::BorderRight();
	BorderBottom::BorderBottom();
	BorderLeft::BorderLeft();*/

	m_collider = new Plane(start, end);
	m_collider->m_owner = this;

	startSmall = raylib::Vector2(start.x, start.y);
	endSmall = raylib::Vector2(end.x, end.y);
}

void Border::OnDraw()
{
	DrawLineEx(startSmall, endSmall, 10, RED);
}

//void Border::BorderT()
//{
//	m_collider = new Plane(cornerTopLeft, cornerTopRight);
//	m_collider->m_owner = this;
//}
//
//void Border::BorderR()
//{
//	m_collider = new Plane(cornerTopRight, cornerBottomRight);
//	m_collider->m_owner = this;
//}
//
//void Border::BorderB()
//{
//	m_collider = new Plane(cornerBottomLeft, cornerBottomRight);
//	m_collider->m_owner = this;
//}
//
//void Border::BorderL()
//{
//	m_collider = new Plane(cornerTopLeft, cornerBottomRight);
//	m_collider->m_owner = this;
//}
