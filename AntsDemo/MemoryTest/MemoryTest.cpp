// MemoryTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;


void double_it(int* a)
{
	(*a) *= 2;
}

void double_by_reference(int& a)
{
	a *= 2;
}

double Double(int a)
{
	return a * 2;
}

void TestFunction()
{
	int b = 3;

	double_by_reference(b);

	cout << b << endl;
}

void Test()
{
	cout << "Please input number of scores: ";
	int count;
	cin >> count;

	double * scores = new double[count];

	for (int i = 0; i < count; i++)	{
		cin >> scores[i];
	}

	double sum = 0.0;
	for (int i = 0; i < count; ++i)	{
		sum += scores[i];
	}

	cout << sum / count;

	delete []scores;
}

void TestDynamicMemory()
{
	unsigned size_allocated = 2;
	double * scores = new double[size_allocated];
	unsigned count = 0;
	for (;;)
	{
		int temp;
		cin >> temp;

		if (temp < 0)
		{
			break;
		}

		if (count >= size_allocated){
			double * old_scores = scores;
			scores = new double[size_allocated * 2];
			memcpy(scores, old_scores, sizeof(double) * size_allocated);
			delete old_scores;
			size_allocated *= 2;
		}

		scores[count] = temp;
		++count;
	}

	double sum = 0.0;
	for (unsigned int i = 0; i < count; ++i){
		sum += scores[i];
	}

	cout << "Count: " << count << " Average: " << sum / count << endl;
	delete scores;
}

void Test2D()
{
	int width, height;
	cout << "Please input width, height:";

	cin >> width >> height;

	double ** p = new double * [height];

	for (unsigned int i = 0; i < height; ++i){
		p[i] = new double[width];
	}

	//...
	for (unsigned int row = 0; row < height; ++row)
	{
		for (unsigned int column = 0; column < width; ++column)
		{
			p[row][column] = row * column;
			cout << row << "x" << column 
				<< "=" << p[row][column] << " ";
		}
		cout << endl;
	}

	for (unsigned int i = 0; i < height; ++i){
		delete []p[i];
		p[i] = nullptr;
	}

	delete []p;
}

int _tmain(int argc, _TCHAR* argv[])
{
	// TestFunction();

	//	Test();
	// TestDynamicMemory();
	Test2D();

	return 0;
}

