#pragma once
#include "Interface.h"

class CHumanPlayer :
	public IPlayer
{
public:
	Move GetNextMove(CGame& game, bool move_black);
};

