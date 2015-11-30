#pragma once
#include <vector>

enum Cell
{
	CellBlack,
	CellWhite,
	CellEmpty,
};

typedef std::vector < std::vector<Cell> > Game;
typedef std::pair<unsigned int, unsigned int> Move;

class CGame{
public:
	CGame(){
	for (unsigned row = 0; row < 3; ++row){
			std::vector<Cell> game_row;
			for (unsigned column = 0; column < 3; ++column){
				game_row.push_back(CellEmpty);
			}
			_game.push_back(game_row);
		}
	};
	bool AddMove(Move move, bool black){
		_game[move.first][move.second] = black ? CellBlack : CellWhite;
		return true;
	}

	Cell GetCell(unsigned int row, unsigned int column){
		return _game[row][column];
	}

private:
	Game _game;
};

struct IPlayer{
	virtual Move GetNextMove(CGame& game, bool move_black) = 0;
};

struct IBoard{
	virtual void Draw(CGame& game) = 0;
};

enum Result{
	ResultBlackWin,
	ResultWhiteWin,
	ResultDraw,
	ResultContinue,
};

struct IRule{
	virtual Result Judge(CGame& game) = 0;
};
