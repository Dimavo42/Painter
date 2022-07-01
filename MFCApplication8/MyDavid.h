#pragma once
#include "MyTriangle.h"
class MyDavid :public MyTriangle
{
public:
	MyDavid();
	DECLARE_SERIAL(MyDavid);
	MyDavid(const CPoint&, const CPoint&);
	void drawshape(CPaintDC& dc);
	void Serialize(CArchive&);
};

