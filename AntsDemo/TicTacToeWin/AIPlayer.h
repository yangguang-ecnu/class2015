#pragma once
#include "Interface.h"
class CAIPlayer :
	public IPlayer
{
public:
	CAIPlayer();
	~CAIPlayer();

	virtual Move GetNextMove(CGame& game, bool move_black);
private:
	std::pair<Result, Move> FindNextMove(CGame& game, bool move_black);
};

