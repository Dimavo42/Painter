#include "pch.h"
#include "Line.h"


IMPLEMENT_SERIAL(Line, Figure, 1);
Line::Line() :Figure(CPoint(0, 0), CPoint(0, 0)){}
Line::Line(const CPoint& Point_a, const CPoint& Point_b):Figure(Point_a, Point_b){}

void Line::drawshape(CPaintDC& dc)
{
	dc.MoveTo(Get_Start());
	dc.LineTo(Get_End());
}

void Line::Serialize(CArchive& archive)
{
	Figure::Serialize(archive);
}
