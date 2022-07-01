#pragma once
#include "Figure.h"

class MyTriangle :public Figure
{
public:
	DECLARE_SERIAL(MyTriangle);
	MyTriangle();
	MyTriangle(const CPoint&, const CPoint&);
	void drawshape(CPaintDC& dc);
	void Serialize(CArchive&);
private:
	CPoint Third_Point;
};






