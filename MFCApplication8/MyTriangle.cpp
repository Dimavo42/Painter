#include "pch.h"
#include "MyTriangle.h"


IMPLEMENT_SERIAL(MyTriangle, Figure, 1);

MyTriangle::MyTriangle() :Figure(CPoint(0, 0), CPoint(0, 0)) {}
MyTriangle::MyTriangle(const CPoint& Point_a, const CPoint&Point_b) :Figure(Point_a,Point_b){}

void MyTriangle::drawshape(CPaintDC& dc) 
{
	Third_Point.y = (Get_End().y);
	Third_Point.x = (Get_Start().x - (Get_End().x - Get_Start().x));
	CPoint p_arr[3] = { Get_Start(),Third_Point,Get_End() };
	dc.Polygon(p_arr, 3);
}

void MyTriangle::Serialize(CArchive& archive)
{
	Figure::Serialize(archive);
}





