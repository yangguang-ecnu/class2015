#pragma once
#include "Interface.h"
class CBoard :
	public IBoard
{
public:
	virtual void Draw(CGame& game);
};

