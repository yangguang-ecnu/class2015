#include "stdafx.h"
#include "HumanPlayer.h"
#include <iostream>

Move CHumanPlayer::GetNextMove(CGame& game, bool move_black)
{
	std::cout << "Please input next move: ";
	unsigned int row, column;
	std::cin >> row >> column;

	return std::make_pair(row, column);
}
