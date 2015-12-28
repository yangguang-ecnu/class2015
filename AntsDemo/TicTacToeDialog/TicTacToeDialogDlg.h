
// TicTacToeDialogDlg.h : header file
//

#pragma once
#include "afxwin.h"
#include "TicTacToeWindow.h"


// CTicTacToeDialogDlg dialog
class CTicTacToeDialogDlg : public CDialogEx
{
// Construction
public:
	CTicTacToeDialogDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_TICTACTOEDIALOG_DIALOG };

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
	int _player1;
	int _player2;
	afx_msg void OnBnClickedButtonNew();
	CStatic _place_holder;
	CTicTacToeWindow _tictactoe_win;
};
