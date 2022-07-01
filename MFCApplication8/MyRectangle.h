#pragma once
#include "Figure.h"
class MyRectangle :public Figure
{
public:
	MyRectangle();
	DECLARE_SERIAL(MyRectangle);
	MyRectangle(const CPoint&, const CPoint&);
	void drawshape(CPaintDC& dc);
	void Serialize(CArchive&);
};



