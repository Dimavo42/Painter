#pragma once
#include "Figure.h"
class Line:public Figure
{
	DECLARE_SERIAL(Line);
public:
	Line();
	Line(const CPoint&, const CPoint&);
	void drawshape(CPaintDC& dc);
	void Serialize(CArchive&);

};

