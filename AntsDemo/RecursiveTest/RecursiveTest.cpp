// RecursiveTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

void print(int n)
{
	if (n >= 1)
	{
		print(n - 1);
		cout << n;
	}
}

void Hanoi(int n, char source, char dest, char mid)
{
	if (n == 1)	{
		cout << source << " => " << dest << endl;
	}
	else {
		Hanoi(n - 1, source, mid, dest);
		Hanoi(1, source, dest, mid);
		Hanoi(n - 1, mid, dest, source);
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	Hanoi(10, 'A', 'C', 'B');

	return 0;
}

