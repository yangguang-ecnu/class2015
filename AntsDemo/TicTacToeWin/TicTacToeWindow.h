
// ChildView.h : interface of the CChildView class
//


#pragma once
#include "Interface.h"


// CChildView window

class CTicTacToeWindow : public CWnd
{
// Construction
public:
	CTicTacToeWindow();

// Attributes
public:

// Operations
public:
	void NewGame();

// Overrides
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// Implementation
public:
	virtual ~CTicTacToeWindow();

	// Generated message map functions
protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()

	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);

	CGame _game;
	bool _black_to_go;
	bool _in_game;
};

