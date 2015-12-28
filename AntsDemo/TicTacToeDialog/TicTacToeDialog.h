
// TicTacToeDialog.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CTicTacToeDialogApp:
// See TicTacToeDialog.cpp for the implementation of this class
//

class CTicTacToeDialogApp : public CWinApp
{
public:
	CTicTacToeDialogApp();

// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	ULONG_PTR _gdiplus_token;

	DECLARE_MESSAGE_MAP()
};

extern CTicTacToeDialogApp theApp;