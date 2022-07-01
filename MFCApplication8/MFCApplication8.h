
// MFCApplication8.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CMFCApplication8App:
// See MFCApplication8.cpp for the implementation of this class
//

class CMFCApplication8App : public CWinApp
{
public:
	CMFCApplication8App();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CMFCApplication8App theApp;
