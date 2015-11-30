#include "stdafx.h"
#include "Board.h"
#include <iostream>
#include <cassert>

using namespace std;

void CBoard::Draw(CGame& game)
{
	cout << "===" << endl;
	for (unsigned row = 0; row < 3; ++row){
		for (unsigned column = 0; column < 3; ++column){
			switch (game.GetCell(row, column)){
			case CellBlack:
				cout << 'O';
				break;
			case CellWhite:
				cout << 'X';
				break;
			case CellEmpty:
				cout << ' ';
				break;
			default:
				assert(0);
			}
		}
		cout << endl;
	}
	cout << "===" << endl << endl;
}
