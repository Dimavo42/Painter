#pragma once
#include "Figure.h"

	class MyEllipse :public Figure
{
public:
	MyEllipse();
	DECLARE_SERIAL(MyEllipse);
	MyEllipse(const CPoint&, const CPoint&);
	void drawshape(CPaintDC& dc);
	void Serialize(CArchive&);
};


