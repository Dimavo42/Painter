#include "pch.h"
#include "MyEllipse.h"

MyEllipse::MyEllipse(const CPoint& Point_a, const CPoint& Point_b) :Figure(Point_a, Point_b) {}
MyEllipse::MyEllipse() : Figure(CPoint(0, 0), CPoint(0, 0)) {}
IMPLEMENT_SERIAL(MyEllipse, Figure, 1);
void MyEllipse::drawshape(CPaintDC& dc) 
{
	dc.Ellipse(Get_Start().x, Get_Start().y, Get_End().x, Get_End().y);
}

void MyEllipse::Serialize(CArchive& archive)
{
	Figure::Serialize(archive);
}
