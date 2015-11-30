#pragma once
#include "Interface.h"
class CRule :
	public IRule
{
public:
	Result Judge(CGame& game);

private:
	bool WholeRow(CGame& game, unsigned row, bool black);
	bool WholeColumn(CGame& game, unsigned column, bool black);
	bool WholeDiag(CGame& game, bool black);

	bool Win(CGame& game, bool black);
	bool Draw(CGame& game);
};

