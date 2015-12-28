
// TicTacToeWin.h : main header file for the TicTacToeWin application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CTicTacToeWinApp:
// See TicTacToeWin.cpp for the implementation of this class
//

class CTicTacToeWinApp : public CWinAppEx
{
public:
	CTicTacToeWinApp();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation

public:
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;
	ULONG_PTR _gdiplus_token;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CTicTacToeWinApp theApp;
