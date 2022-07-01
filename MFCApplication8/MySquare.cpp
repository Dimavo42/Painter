#include "pch.h"
#include "MySquare.h"


IMPLEMENT_SERIAL(MySquare, MyRectangle, 1);
MySquare::MySquare():MyRectangle(CPoint(0, 0), CPoint(0, 0)) {}
MySquare::MySquare(const CPoint& Point_a, const CPoint& Point_b):MyRectangle(Point_a, Point_b){}


void MySquare::drawshape(CPaintDC& dc) 
{
	int xBegin = Get_Start().x - Get_End().x;
	int yBegin = Get_Start().y - Get_End().y;
	if (xBegin * xBegin > yBegin * yBegin)
		dc.Rectangle(Get_Start().x, Get_Start().y, Get_Start().x - xBegin, Get_Start().y - yBegin);
	else
		dc.Rectangle(Get_Start().x, Get_Start().y, Get_Start().x - yBegin, Get_Start().y - yBegin);
}

void MySquare::Serialize(CArchive& archive)
{
	Figure::Serialize(archive);
}
