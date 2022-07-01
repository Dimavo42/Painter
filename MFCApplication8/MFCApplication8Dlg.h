
// MFCApplication8Dlg.h : header file
//

#pragma once
#include "Figure.h"
#include "Line.h"
#include "MyRectangle.h"
#include "MySquare.h"
#include "MyTriangle.h"
#include "MyEllipse.h"
#include "MyDavid.h"

// CMFCApplication8Dlg dialog
class CMFCApplication8Dlg : public CDialogEx
{
// Construction
	BOOL If_Clicked = false;
	
	
public:
	/*CPoint start, end;*/
	int Chosen_Radio=0;
	CTypedPtrArray< CObArray, Figure*> Current_Figures;
	CTypedPtrArray< CObArray, Figure*> Stack_Figures;
	CMFCApplication8Dlg(CWnd* pParent = nullptr);	// standard constructor
	COLORREF Background_color ;
	COLORREF Border_color ;
	CButton* pButton;
	


// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION8_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:


	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedRadio3();
	afx_msg void OnBnClickedRadio4();
	afx_msg void OnBnClickedRadio5();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);

	
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton2();
	int Border_Size;
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedRadio6();
	afx_msg void OnBnClickedButton4();
};
