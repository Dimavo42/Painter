#pragma once
#include "MyRectangle.h"

class MySquare :public MyRectangle
{
public:
	MySquare();
	DECLARE_SERIAL(MySquare);
	MySquare(const CPoint&, const CPoint&);
	void drawshape(CPaintDC& dc);
	void Serialize(CArchive&);
};









