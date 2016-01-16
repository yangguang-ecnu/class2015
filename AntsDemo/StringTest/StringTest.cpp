// StringTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include "ecnuString.h"

#include <fstream>
#include <vector>

struct Info
{
	int weight;
	int height;
	bool OverWeight(){
		return this->weight > this->height - 110;
	}
};

bool OverWeight(Info* info)
{
	return info->weight > info->height - 110;
}

void Test()
{
	Info my_info;
	my_info.weight = 80;
	my_info.height = 180;

	if (my_info.OverWeight())
	{
		std::cout << "Eat less please.";
	}

// 	if (OverWeight(&my_info))
// 	{
// 		std::cout << "Eat less please.";
// 	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	ecnu::string str1 = "Hello";
	ecnu::string str2 = str1;
	ecnu::string str3 = "!";

	//str1 = (str2 = str3);
	str1 += str3;
	std::cout << str1;
	str1 = (str2 + str3);

	std::cout << ecnu::string("Hello" + str2 + str3).GetLength();
	return 0;
}

