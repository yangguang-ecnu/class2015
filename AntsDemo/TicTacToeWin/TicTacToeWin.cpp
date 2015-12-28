
// TicTacToeWin.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "afxwinappex.h"
#include "afxdialogex.h"
#include "TicTacToeWin.h"
#include "MainFrm.h"

#include <gdiplus.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTicTacToeWinApp

BEGIN_MESSAGE_MAP(CTicTacToeWinApp, CWinAppEx)
	ON_COMMAND(ID_APP_ABOUT, &CTicTacToeWinApp::OnAppAbout)
END_MESSAGE_MAP()


// CTicTacToeWinApp construction

CTicTacToeWinApp::CTicTacToeWinApp()
{
	m_bHiColorIcons = TRUE;

	// TODO: replace application ID string below with unique ID string; recommended
	// format for string is CompanyName.ProductName.SubProduct.VersionInformation
	SetAppID(_T("TicTacToeWin.AppID.NoVersion"));

	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

// The one and only CTicTacToeWinApp object

CTicTacToeWinApp theApp;


// CTicTacToeWinApp initialization

BOOL CTicTacToeWinApp::InitInstance()
{
	CWinAppEx::InitInstance();


	EnableTaskbarInteraction(FALSE);

	// AfxInitRichEdit2() is required to use RichEdit control	
	// AfxInitRichEdit2();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	// of your final executable, you should remove from the following
	// the specific initialization routines you do not need
	// Change the registry key under which our settings are stored
	// TODO: You should modify this string to be something appropriate
	// such as the name of your company or organization
	SetRegistryKey(_T("Local AppWizard-Generated Applications"));


	InitContextMenuManager();

	InitKeyboardManager();

	InitTooltipManager();
	CMFCToolTipInfo ttParams;
	ttParams.m_bVislManagerTheme = TRUE;
	theApp.GetTooltipManager()->SetTooltipParams(AFX_TOOLTIP_TYPE_ALL,
		RUNTIME_CLASS(CMFCToolTipCtrl), &ttParams);

	// To create the main window, this code creates a new frame window
	// object and then sets it as the application's main window object
	CMainFrame* pFrame = new CMainFrame;
	if (!pFrame)
		return FALSE;
	m_pMainWnd = pFrame;
	// create and load the frame with its resources
	pFrame->LoadFrame(IDR_MAINFRAME,
		WS_OVERLAPPEDWINDOW | FWS_ADDTOTITLE, NULL,
		NULL);

	// The one and only window has been initialized, so show and update it
	pFrame->ShowWindow(SW_SHOW);
	pFrame->UpdateWindow();

	Gdiplus::GdiplusStartupInput gdiplusStartupInput;
	GdiplusStartup(&_gdiplus_token, &gdiplusStartupInput, NULL);

	return TRUE;
}

int CTicTacToeWinApp::ExitInstance()
{
	Gdiplus::GdiplusShutdown(_gdiplus_token);
	//TODO: handle additional resources you may have added
	return CWinAppEx::ExitInstance();
}

// CTicTacToeWinApp message handlers


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()

// App command to run the dialog
void CTicTacToeWinApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

// CTicTacToeWinApp customization load/save methods

void CTicTacToeWinApp::PreLoadState()
{
	BOOL bNameValid;
	CString strName;
	bNameValid = strName.LoadString(IDS_EDIT_MENU);
	ASSERT(bNameValid);
	GetContextMenuManager()->AddMenu(strName, IDR_POPUP_EDIT);
}

void CTicTacToeWinApp::LoadCustomState()
{
}

void CTicTacToeWinApp::SaveCustomState()
{
}

// CTicTacToeWinApp message handlers



