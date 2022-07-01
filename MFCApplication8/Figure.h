#pragma once
#include "framework.h"

class Figure:public CObject
{
public:
	DECLARE_SERIAL(Figure);
	Figure();
	Figure(const CPoint&, const CPoint&);
	virtual ~Figure();
		//setters
	void Set_Start(const int,const int);
	void Set_End(const int, const int);
	void Set_Background(COLORREF);
	void Set_Background(int);
	void Set_Border(COLORREF);
	void Set_Border_Size(const int);
	//getters
	CPoint Get_Start() const;
	CPoint Get_End() const;
	void draw(CPaintDC& dc);
	virtual void drawshape(CPaintDC& dc) {}
	virtual void Serialize(CArchive&);




private:
	int Border_Size=0;
	CPoint start;
	CPoint end;
	COLORREF Background_color = 0x00000000;
	COLORREF Border_color= 0x00000000;
	
};

//new Figure 

