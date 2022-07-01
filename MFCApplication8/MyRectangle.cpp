#include "pch.h"
#include "MyRectangle.h"


IMPLEMENT_SERIAL(MyRectangle, Figure, 1);
MyRectangle::MyRectangle(const CPoint& Point_a, const CPoint& Point_b) :Figure(Point_a, Point_b) {}
MyRectangle::MyRectangle(): Figure(CPoint(0, 0), CPoint(0, 0)) {}

void MyRectangle::drawshape(CPaintDC& dc) 
{
	dc.Rectangle(Get_Start().x, Get_Start().y, Get_End().x, Get_End().y);
}

void MyRectangle::Serialize(CArchive& archive)
{
	Figure::Serialize(archive);
}
