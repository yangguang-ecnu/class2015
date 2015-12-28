
// ChildView.cpp : implementation of the CChildView class
//

#include "stdafx.h"
#include "TicTacToeWindow.h"
#include "Rule.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using namespace Gdiplus;
using namespace std;

// CChildView

CTicTacToeWindow::CTicTacToeWindow() :
_black_to_go(true),
_in_game(true)
{
}

CTicTacToeWindow::~CTicTacToeWindow()
{
}


BEGIN_MESSAGE_MAP(CTicTacToeWindow, CWnd)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
//	ON_COMMAND(ID_NEW_GAME, &CChildView::OnNewGame)
END_MESSAGE_MAP()



// CChildView message handlers

BOOL CTicTacToeWindow::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(NULL, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), NULL);

	return TRUE;
}

const int BorderSize = 6;

void CTicTacToeWindow::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	Graphics graphics(dc.m_hDC);

	Pen pen(Color::Black, 3);

	CRect rect;
	GetClientRect(rect);
	graphics.DrawLine(&pen, rect.left + rect.Width() / 3, rect.top, 
		rect.left + rect.Width() / 3, rect.bottom);
	graphics.DrawLine(&pen, rect.left + 2 * rect.Width() / 3, rect.top,
		rect.left + 2 * rect.Width() / 3, rect.bottom);
	graphics.DrawLine(&pen, rect.left, rect.top + rect.Height() / 3,
		rect.right, rect.top + rect.Height() / 3);
	graphics.DrawLine(&pen, rect.left, rect.top + 2 * rect.Height() / 3,
		rect.right, rect.top + 2 * rect.Height() / 3);

	SolidBrush brush(Color::Black);

	for (unsigned int row = 0; row < 3; row++)
	{
		for (unsigned int column = 0; column < 3; column++)
		{
			if (_game.GetCell(row, column) == CellBlack)
			{
				graphics.FillEllipse(&brush, rect.left + row * rect.Width() / 3 + BorderSize,
					rect.top + column * rect.Height() / 3 + BorderSize,
					rect.Width() / 3 - 2 * BorderSize,
					rect.Height() / 3 - 2 * BorderSize
				);
			}
			else if (_game.GetCell(row, column) == CellWhite)
			{
				graphics.DrawEllipse(&pen, rect.left + row * rect.Width() / 3 + BorderSize,
					rect.top + column * rect.Height() / 3 + BorderSize,
					rect.Width() / 3 - 2 * BorderSize,
					rect.Height() / 3 - 2 * BorderSize
					);
			}
		}
	}
}

void CTicTacToeWindow::OnLButtonDown(UINT nFlags, CPoint point)
{
	if (!_in_game)
		return;

	CRect rect;
	GetClientRect(rect);

	unsigned int row = 3 * point.x / rect.Width();
	unsigned int column = 3 * point.y / rect.Height();

	if (_game.AddMove(make_pair(row, column), _black_to_go))
	{
		_black_to_go = !_black_to_go;

		Invalidate();
		UpdateWindow();

		CRule rule;
		auto result = rule.Judge(_game);
		if (result == ResultBlackWin)
		{
			AfxMessageBox(_T("Black wins."));
			_in_game = false;
		}
		else if (result == ResultWhiteWin)
		{
			AfxMessageBox(_T("White wins."));
			_in_game = false;
		}
		else if (result == ResultDraw)
		{
			AfxMessageBox(_T("Draw."));
			_in_game = false;
		}
	}
	else
	{
		AfxMessageBox(_T("Invalid move."));
	}

	CWnd::OnLButtonDown(nFlags, point);
}


void CTicTacToeWindow::NewGame()
{
	_in_game = true;
	_black_to_go = true;
	_game.Init();

	Invalidate();
	UpdateWindow();
}
