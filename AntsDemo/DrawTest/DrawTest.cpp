// DrawTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

#include "Canvas.h"

using namespace std;

void Test()
{
	for (unsigned int row = 0; row < 10; ++row)
	{
		for (unsigned int column = 0; column < 20; ++column)
		{
			cout << (column < 2 * row) ? " " : "*";
		}
		cout << endl;
	}
}

const unsigned int WIDTH = 80;
const unsigned int HEIGHT = 23;

void DrawHorizontalLine(char * buffer, 
	unsigned int x1, 
	unsigned int y1, 
	unsigned int x2, 
	unsigned int y2)
{
	for (unsigned int x = x1; x <= x2; ++x)
	{
		buffer[y1 * WIDTH + x] = (buffer[y1 * WIDTH + x] == '|') ? '+' : '-';
	}
}

void DrawVerticalLine(char * buffer,
	unsigned int x1,
	unsigned int y1,
	unsigned int x2,
	unsigned int y2)
{
	for (unsigned int y = y1; y <= y2; ++y)
	{
		buffer[y * WIDTH + x1] = (buffer[y * WIDTH + x1] == '-') ? '+' : '|';
	}
}

void DrawRect(char * buffer,
	unsigned int left,
	unsigned int top,
	unsigned int width,
	unsigned int height)
{
	DrawHorizontalLine(buffer, left, top, left + width, top);
	DrawHorizontalLine(buffer, left, top + height, left + width, top + height);
	DrawVerticalLine(buffer, left, top, left, top + height);
	DrawVerticalLine(buffer, left + width, top, left + width, top + height);
}

void OutputBuffer(char * buffer)
{
	for (unsigned int row = 0; row < HEIGHT; ++row)
	{
		for (unsigned int column = 0; column < WIDTH; ++column)
		{
			cout << buffer[row * WIDTH + column];
		}
//		cout << endl;
	}

}

void InitBuffer(char * buffer)
{
	for (unsigned int row = 0; row < HEIGHT; ++row)
	{
		for (unsigned int column = 0; column < WIDTH; ++column)
		{
			buffer[row * WIDTH + column] = ' ';
		}
	}

	// memset(buffer, ' ', WIDTH * HEIGHT);	
}

void DrawTest()
{
	char buffer[WIDTH * HEIGHT] = { 0 };
	InitBuffer(buffer);

	cout << "Please input x, y, width, height: ";

	unsigned int x, y, width, height;
	cin >> x >> y >> width >> height;
	DrawRect(buffer, x, y, width, height);
	OutputBuffer(buffer);

	cout << "Please input x, y, width, height: ";
	cin >> x >> y >> width >> height;
	DrawRect(buffer, x, y, width, height);
	OutputBuffer(buffer);
}

void DrawTestOO()
{
	CCanvas canvas(79, 23);

	for (;;)
	{
		cout << "Please input x, y, width, height: ";
		unsigned int x, y, width, height;
		cin >> x >> y >> width >> height;

		canvas.DrawRect(x, y, width, height);
		canvas.Output();
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	DrawTestOO();

	return 0;
}

