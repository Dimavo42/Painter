#include "pch.h"
#include "Figure.h"

IMPLEMENT_SERIAL(Figure, CObject, 1);
Figure::Figure():start(CPoint(0,0)),end(CPoint(0,0)){}


Figure::Figure(const CPoint& Point_A, const CPoint& Point_B) : start(Point_A), end(Point_B) {}

Figure::~Figure() {}

void Figure::Set_Start(const int num1, const int num2)
{
	this->start=CPoint(num1, num2);
}

void Figure::Set_End(const int num1, const int num2)
{
	this->end = CPoint(num1, num2);
}

void Figure::Set_Background(COLORREF color)
{
	this->Background_color = color;
}

void Figure::Set_Background(int Random) {
	this->Border_Size = 10;
	switch (Random)
	{
	case 1:
	{
		this->Background_color = 0x00FFFFFF;
		this->Border_color = 0x400100FF;
	
		break;
	}
	case 2:
	{
		this->Background_color = 0x400100FF;
		this->Border_color = 0x03055001F;
		break;
	}
	case 3:
	{
		this->Background_color = 0x030200FF;
		this->Border_color = 0x000000FF;
		break;
	}
	case 4:
	{
		this->Background_color = 0x03055001F;
		this->Border_color = 0x030200FF;
		break;
	}
	case 5:
	{
		this->Background_color = 0x010F0011;
		this->Border_color = 0x010F0044;
		break;
	}
	case 6:
	{
		this->Background_color = 0x01013011;
		this->Border_color = 0x030200FF;
		break;
	}

	case 7:
	{
		this->Background_color = 0x010F0044;
		this->Border_color = 0x01013011;
		break;
	}

	default:
		break;
	}
}

void Figure::Set_Border(COLORREF color)
{
	this->Border_color = color;
}

void Figure::Set_Border_Size(const int num)
{
	this->Border_Size = num;
}

CPoint Figure::Get_Start() const
{
	return start;
}

CPoint Figure::Get_End() const
{
	return end;
}

void Figure::draw(CPaintDC& dc) {

	// fix 2 instael border size
	CPen pen(PS_SOLID,Border_Size, Border_color);
	CBrush brush(Background_color);
	CPen* oldPen = dc.SelectObject(&pen);
	CBrush* oldBrush = dc.SelectObject(&brush);
	drawshape(dc);
	dc.SelectObject(oldPen);
	dc.SelectObject(oldBrush);

	
}

void Figure::Serialize(CArchive& ar)
{
	CObject::Serialize(ar);
	if (ar.IsStoring())
	{
		ar << start;
		ar << end;
		ar << Background_color; // save
		ar << Border_color; // save
		ar << Border_Size; // save
	}
	else // Loading, not storing
	{
		ar >> start;
		ar >> end;
		ar >> Background_color; // loading
		ar >> Border_color; // loading
		ar >> Border_Size; // loading
	}
}
