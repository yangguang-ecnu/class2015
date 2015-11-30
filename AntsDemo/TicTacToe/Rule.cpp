#include "stdafx.h"
#include "Rule.h"

Result CRule::Judge(CGame& game)
{
	if (Win(game, true))
		return ResultBlackWin;
	if (Win(game, false))
		return ResultWhiteWin;

	if (Draw(game))
		return ResultDraw;

	return ResultContinue;
}


bool CRule::Win(CGame& game, bool black)
{
	if (WholeRow(game, 0, black) || WholeRow(game, 1, black) || WholeRow(game, 2, black))
		return true;

	if (WholeColumn(game, 0, black) || WholeColumn(game, 1, black) || WholeColumn(game, 2, black))
		return true;

	if (WholeDiag(game, black))
		return true;

	return false;
}

bool CRule::WholeRow(CGame& game, unsigned row, bool black)
{
	auto cell = black ? CellBlack : CellWhite;

	return  (game.GetCell(row, 0) == cell &&
		game.GetCell(row, 1) == cell &&
		game.GetCell(row, 2) == cell);
}

bool CRule::WholeColumn(CGame& game, unsigned column, bool black)
{
	auto cell = black ? CellBlack : CellWhite;

	return  (game.GetCell(0, column) == cell &&
		game.GetCell(1, column) == cell &&
		game.GetCell(2, column) == cell);
}

bool CRule::WholeDiag(CGame& game, bool black)
{
	auto cell = black ? CellBlack : CellWhite;

	return  (game.GetCell(0, 0) == cell &&
		game.GetCell(1, 1) == cell &&
		game.GetCell(2, 2) == cell) 
		|| (
		game.GetCell(0, 2) == cell &&
		game.GetCell(1, 1) == cell &&
		game.GetCell(2, 0) == cell);
}

bool CRule::Draw(CGame& game)
{
	for (unsigned row = 0; row < 3; ++row){
		for (unsigned column = 0; column < 3; ++column){
			if (game.GetCell(row, column) == CellEmpty)
				return false;
		}
	}

	return true;
}
