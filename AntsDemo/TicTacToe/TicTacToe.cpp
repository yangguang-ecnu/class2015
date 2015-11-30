// TicTacToe.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Interface.h"
#include <iostream>
#include "HumanPlayer.h"
#include "Rule.h"
#include "Board.h"
#include "AIPlayer.h"

using namespace std;

Result Play(IPlayer * players[2], IRule& rule, IBoard& board)
{
	CGame game;
	board.Draw(game);

	for (;;)
	{
		for (unsigned int player = 0; player < 2; ++player)
		{
			auto move = players[player]->GetNextMove(game, player == 0);
			game.AddMove(move, player == 0);
			board.Draw(game);

			auto result = rule.Judge(game);
			if (result == ((player == 0) ?ResultBlackWin : ResultWhiteWin ) || result == ResultDraw)
				return result;
		}
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	CAIPlayer ai_player;
	CHumanPlayer human_player;
	CRule rule;
	CBoard board;

	cout << "Please select: \n"
		<< "1. Play with computer.\n"
		<< "2. Play with another player.\n";

	int choice;
	cin >> choice;

	IPlayer* players[2];

	if (choice == 1){
		players[0] = &ai_player;
		players[1] = &human_player;
	}
	else if (choice == 2){
		players[0] = &human_player;
		players[1] = &human_player;
	}
	else{
		cout << "Are you kidding?\n";
	}

	auto result = Play(players, rule, board);

	switch (result){
	case ResultBlackWin:
		cout << "Black wins." << endl;
		break;
	case ResultWhiteWin:
		cout << "White wins." << endl;
		break;
	case ResultDraw:
		cout << "Draw." << endl;
		break;
	}

	return 0;
}

