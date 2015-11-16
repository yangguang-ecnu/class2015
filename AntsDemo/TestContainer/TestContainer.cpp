// TestContainer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> scores;
	for (int i = 0; i < 5; ++i)
	{
		int temp;
		cin >> temp;
		scores.push_back(temp);
	}
	
	sort(scores.begin(), scores.end());

	for (int i = 0; i < scores.size(); ++i){
		cout << scores[i] << ' ';
	}
	return 0;
}

