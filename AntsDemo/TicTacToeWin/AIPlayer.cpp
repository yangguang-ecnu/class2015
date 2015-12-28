#include "stdafx.h"
#include "AIPlayer.h"
#include "Rule.h"

using namespace std;

CAIPlayer::CAIPlayer()
{
}


CAIPlayer::~CAIPlayer()
{
}

Move CAIPlayer::GetNextMove(CGame& game, bool move_black)
{
	if (game.GetCell(1, 1) == CellEmpty){
		return make_pair(1, 1);
	}

	auto result = FindNextMove(game, move_black);
	return result.second;
}

std::pair<Result, Move> CAIPlayer::FindNextMove(CGame& game, bool move_black)
{
	CRule rule;
	Move draw_move = make_pair(3, 3);
	Move lose_move = make_pair(3, 3);

	for (unsigned int row = 0; row < 3; ++row){
		for (unsigned int column = 0; column < 3; ++column){
			if (game.GetCell(row, column) == CellEmpty){
				// lose_move = make_pair(row, column);
				auto local_game = game;
				local_game.AddMove(make_pair(row, column), move_black);
				auto result = rule.Judge(local_game);
				if ( result == (move_black ? ResultBlackWin : ResultWhiteWin) ||
					result == ResultDraw){
					return make_pair(result, make_pair(row, column));
				}

				auto rival_result = FindNextMove(local_game, !move_black);
				if (rival_result.first == (move_black ? ResultBlackWin : ResultWhiteWin)){
					return make_pair(rival_result.first, make_pair(row, column));
				}
				else if (rival_result.first == ResultDraw){
					draw_move = make_pair(row, column);
				}
				else{
					lose_move = rival_result.second;
				}
			}
		}
	}

	if (draw_move.first != 3){
		return make_pair(ResultDraw, draw_move);
	}

	return make_pair(move_black ? ResultWhiteWin : ResultBlackWin, lose_move);
}

