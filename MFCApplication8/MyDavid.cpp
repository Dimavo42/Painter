#include "pch.h"
#include "MyDavid.h"
IMPLEMENT_SERIAL(MyDavid, MyTriangle, 1);
MyDavid::MyDavid() :MyTriangle(CPoint(0, 0), CPoint(0, 0)) {}
MyDavid::MyDavid(const CPoint& Point_a, const CPoint& Point_b) : MyTriangle(Point_a, Point_b) {}

void MyDavid::drawshape(CPaintDC& dc)
	{
	CPoint center = Get_Start() + Get_End();
	center.x /= 2.0; center.y /= 2.0;
	double radius = abs(Get_Start().x - Get_End().x) < abs(Get_Start().y - Get_End().y) ? abs(Get_Start().x - Get_End().x) / 2.0 : abs(Get_Start().y - Get_End().y) / 2.0;
	CPoint vertices[12];
	double two_pi = atan(1) * 8;
	for (int i = 0; i < 12; i++)
	{
	if (i % 2 == 0)
	{
		vertices[i].x = center.x + radius / sqrt(3) * cos(two_pi / 12 * i);
		vertices[i].y = center.y + radius / sqrt(3) * sin(two_pi / 12 * i);
	}
	else
	{
		vertices[i].x = center.x + radius * cos(two_pi / 12 * i);
		vertices[i].y = center.y + radius * sin(two_pi / 12 * i);
	}
	}
	dc.Polygon(vertices, 12);
	}


void MyDavid::Serialize(CArchive& archive)
{
	Figure::Serialize(archive);
}