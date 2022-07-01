
// MFCApplication8Dlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "MFCApplication8.h"
#include "MFCApplication8Dlg.h"
#include "afxdialogex.h"




#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCApplication8Dlg dialog



CMFCApplication8Dlg::CMFCApplication8Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION8_DIALOG, pParent)
{
	pButton = NULL;
	Border_Size = 0;
	Background_color = 0x00000000;
	Border_color = 0x00000000;
	If_Clicked = false;
	Chosen_Radio = 1;  // Line Default choose.
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication8Dlg::DoDataExchange(CDataExchange* pDX)
{
	pButton = (CButton*)GetDlgItem(IDC_RADIO1);
	pButton->SetCheck(true);  //selecting the first radio of Line As default
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, Border_Size);
}

BEGIN_MESSAGE_MAP(CMFCApplication8Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_RADIO4, &CMFCApplication8Dlg::OnBnClickedRadio4)
	ON_BN_CLICKED(IDC_RADIO1, &CMFCApplication8Dlg::OnBnClickedRadio1)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_BN_CLICKED(IDC_RADIO2, &CMFCApplication8Dlg::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_RADIO3, &CMFCApplication8Dlg::OnBnClickedRadio3)
	ON_BN_CLICKED(IDC_RADIO5, &CMFCApplication8Dlg::OnBnClickedRadio5)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCApplication8Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCApplication8Dlg::OnBnClickedButton2)
	ON_EN_CHANGE(IDC_EDIT1, &CMFCApplication8Dlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON9, &CMFCApplication8Dlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON8, &CMFCApplication8Dlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication8Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON6, &CMFCApplication8Dlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CMFCApplication8Dlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_RADIO6, &CMFCApplication8Dlg::OnBnClickedRadio6)
	ON_BN_CLICKED(IDC_BUTTON4, &CMFCApplication8Dlg::OnBnClickedButton4)
END_MESSAGE_MAP()


// CMFCApplication8Dlg message handlers

BOOL CMFCApplication8Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	CString   A = _T("Da vinci Paint- As da vinci said :The world is our canvas 🎨");
	SetWindowText(A);
	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMFCApplication8Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMFCApplication8Dlg::OnPaint()
{

	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);

	}
	else
	{
		CPaintDC dc(this);
		for (int i = 0; i < Current_Figures.GetSize(); i++)
			Current_Figures[i]->draw(dc);
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMFCApplication8Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



// line radio
void CMFCApplication8Dlg::OnBnClickedRadio1()
{
	Chosen_Radio = 1;
	
}

//  Rectangle radio
void CMFCApplication8Dlg::OnBnClickedRadio2()
{
	Chosen_Radio = 2;
}

//  Square radio
void CMFCApplication8Dlg::OnBnClickedRadio3()
{
	Chosen_Radio = 3;
}

//  Triangle radio
void CMFCApplication8Dlg::OnBnClickedRadio4()
{
	Chosen_Radio = 4;
}

//  Elipse radio
void CMFCApplication8Dlg::OnBnClickedRadio5()
{
	Chosen_Radio = 5;

}

// Magen of David Ty nodelman!
void CMFCApplication8Dlg::OnBnClickedRadio6()
{
	Chosen_Radio = 6;
}


// Color  button choose of border
void CMFCApplication8Dlg::OnBnClickedButton3()
{
	CColorDialog dlg;
	if (dlg.DoModal() == IDOK) {
		Border_color = dlg.GetColor();
	}
}

// color button choose of background color
void CMFCApplication8Dlg::OnBnClickedButton2()
{
	CColorDialog dlg;
	if (dlg.DoModal() == IDOK) {
		Background_color = dlg.GetColor();
	}
}



void CMFCApplication8Dlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	//pointer to the future object created;
	Figure* shape=nullptr;
	//clicked boolean becomes true;
	If_Clicked = TRUE;


	//swtich to create the object and adding to the array;
	switch (Chosen_Radio)
	{
	case 1:
	{
		shape = new Line(point, point);
		Current_Figures.Add(shape);
		break;
	}
	case 2:
	{
		shape = new MyRectangle(point, point);
		Current_Figures.Add(shape);
		break;
	}
	case 3:
	{
		shape = new MySquare(point, point);
		Current_Figures.Add(shape);
		break;
	}
	case 4:
	{
		shape = new MyTriangle(point, point);
		Current_Figures.Add(shape);
		break;
	}
	case 5:
	{
		shape = new MyEllipse(point, point);
		Current_Figures.Add(shape);
		break;
	}
	case 6:
	{
		shape = new MyDavid(point, point);
		Current_Figures.Add(shape);
		break;
	}
	default:
		break;
	}

	// Set the shape settings for draw;
	shape->Set_Start(point.x, point.y);
	shape->Set_Background(Background_color);
	shape->Set_Border(Border_color);
	shape->Set_Border_Size(Border_Size);

	//mfc code deafult
	CDialogEx::OnLButtonDown(nFlags, point);
}


void CMFCApplication8Dlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	//when realease change to false
	If_Clicked = false;

	CDialogEx::OnLButtonUp(nFlags, point);
}


void CMFCApplication8Dlg::OnMouseMove(UINT nFlags, CPoint point)
{
	
	if (If_Clicked)
	{	
		//setting the end point
		Current_Figures[Current_Figures.GetSize() - 1]->Set_End(point.x, point.y);
		//refresh the screaen.
		Invalidate(); 
	}
	CDialogEx::OnMouseMove(nFlags, point);
}



 //Disco Time
void CMFCApplication8Dlg::OnBnClickedButton4()
{
	srand(time(0));
	int Ammount = Current_Figures.GetSize() -1;
	while (Ammount != -1) { // Figures starts from zero to n 
		Current_Figures[Ammount]->Set_Background(rand()%7+1);
		Ammount--;
		Invalidate();
	}
	
}


void CMFCApplication8Dlg::OnEnChangeEdit1()
{
	//Edittext keep updating the number;
	UpdateData(TRUE);
}

//Undo button
void CMFCApplication8Dlg::OnBnClickedButton9()
{
	if (Current_Figures.GetSize() != 0) // If Figs is not empty
	{
		Stack_Figures.Add(Current_Figures[Current_Figures.GetSize() - 1]);//Take the last figure from the array
		Current_Figures.RemoveAt(Current_Figures.GetSize() - 1);//Delete the last figure
		Invalidate(); // Refresh the window
	}
}

//Redo button  - Same function as up just oppsite;
void CMFCApplication8Dlg::OnBnClickedButton8()
{
	if (Stack_Figures.GetSize() != 0)
	{
		Current_Figures.Add(Stack_Figures[Stack_Figures.GetSize() - 1]);
		Stack_Figures.RemoveAt(Stack_Figures.GetSize() - 1);
		Invalidate(); // refresh
	}
}

// Clear All the Items; all array;
void CMFCApplication8Dlg::OnBnClickedButton1()
{
	Current_Figures.RemoveAll();
	Invalidate(); // refresh
}


void CMFCApplication8Dlg::OnBnClickedButton6()
{

	const TCHAR czFilter[] = _T("Figures (*.figs)|*.figs|All Files (*.*)|*.*||");
	CFileDialog fDialog(FALSE, _T(".Figures"), NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, czFilter, this);
	CString filename;
	if (fDialog.DoModal() == IDOK)
	{
		TRACE(fDialog.GetPathName());
		filename = fDialog.GetPathName(); // return full path and filename
		CFile file(filename, CFile::modeCreate | CFile::modeWrite);
		CArchive ar(&file, CArchive::store);
		Current_Figures.Serialize(ar);
		ar.Close();
		file.Close();
	}
}


void CMFCApplication8Dlg::OnBnClickedButton7()
{
	
	// TODO: Add your command handler code here
	CFileDialog dlg(TRUE, _T(".figs"), NULL, 0, _T("Figures (*.figs)|*.figs|All Files (*.*)|*.*||"));
	CString filename;
	if (dlg.DoModal() == IDOK)
	{
		filename = dlg.GetPathName(); // return full path and filename
		CFile file(filename, CFile::modeRead);
		CArchive ar(&file, CArchive::load);
		Current_Figures.Serialize(ar);
		ar.Close();
		file.Close();
		Invalidate();
	}
}



