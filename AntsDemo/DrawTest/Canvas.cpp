#include "stdafx.h"
#include "Canvas.h"

#include <iostream>
#include <set>

using namespace std;

CCanvas::CCanvas()
{
	_width = 0;
	_height = 0;
	_buffer = nullptr;
}

CCanvas::CCanvas(unsigned int width, unsigned int height)
{
	Init(width, height);
}

CCanvas::~CCanvas()
{
	delete []_buffer;
}

bool CCanvas::Init(unsigned width, unsigned height)
{
	_width = width;
	_height = height;

	_buffer = new char[width * height];
	memset(_buffer, ' ', width * height);

	return true;
}

void CCanvas::DrawVerticalLine(unsigned x, unsigned y1, unsigned y2)
{
	for (unsigned int y = y1; y <= y2; ++y)
	{
		_buffer[y * _width + x] = (_buffer[y * _width + x] == '-') ? '+' : '|';
	}
}

void CCanvas::DrawHorizontalLine(unsigned y, unsigned x1, unsigned x2)
{
	for (unsigned int x = x1; x <= x2; ++x)
	{
		_buffer[y * _width + x] = (_buffer[y * _width + x] == '|') ? '+' : '-';
	}
}

void CCanvas::DrawRect(unsigned top, unsigned left, unsigned width, unsigned height)
{
	DrawHorizontalLine(top, left, left + width);
	DrawHorizontalLine(top + height, left, left + width);
	DrawVerticalLine(left, top, top + height);
	DrawVerticalLine(left + width, top, top + height);
}

void CCanvas::Output()
{
	for (unsigned int row = 0; row < _height; ++row)
	{
		for (unsigned int column = 0; column < _width; ++column)
		{
			cout << _buffer[row * _width + column];
		}
		cout << endl;
	}
}
