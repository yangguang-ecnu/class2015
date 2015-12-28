// ContainerTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <stdlib.h>
#include <iostream>
#include <list>
#include <algorithm>
#include <deque>
#include <map>
#include <fstream>

using namespace std;

string ProcessWord(const string& word)
{
	string result;
	
	for (size_t i = 0; i < word.size(); ++i)
	{
		if (word[i] >= 'a' && word[i] <= 'z')
		{
			result.push_back(word[i]);
		}
		else if (word[i] >= 'A' && word[i] <= 'Z')
		{
			result.push_back(word[i] + 'a' - 'A');
		}
	}

	return result;
}

void WordCount()
{
	map<string, unsigned int> counts;

	ifstream input_file("d:\\little prince.txt");

	char word[100];

	while (input_file)
	{
		input_file >> word;
		auto processed_word = ProcessWord(word);
		if (processed_word.empty())
			continue;

		auto iter = counts.find(processed_word);
		if (iter == counts.end())
		{
			counts.insert(make_pair(string(processed_word), 1));
		}
		else
		{
			++(iter->second);
		}
	}

	unsigned total_word_count = 0;
	for (auto iter = counts.begin(); iter != counts.end(); ++iter)
	{
		total_word_count += iter->second;
		cout << iter->first.c_str() << ": " << iter->second << endl;
	}

	cout << "Total word count: " << total_word_count << endl;

	multimap<unsigned int, string> word_by_count;
	for (auto iter = counts.begin(); iter != counts.end(); ++iter)
	{
		word_by_count.insert(make_pair(iter->second, iter->first));
	}

	cout << "The 10 most frequently used words: \n";
	int output_count = 0;
	for (auto iter = word_by_count.rbegin(); iter != word_by_count.rend(); ++iter)
	{
		if (output_count++ == 10)
			break;

		cout << iter->second.c_str() << " : " << iter->first << endl;
	}
}

void TestMap()
{
	map < int, string > int2string;

	int2string.insert(make_pair(1, string("One")));
	int2string.insert(make_pair(2, string("Two")));
	int2string.insert(make_pair(3, string("Three")));
	int2string.insert(make_pair(4, string("Four")));
	int2string.insert(make_pair(5, string("Five")));

	cout << "Please input a digit: ";
	int digit;
	cin >> digit;

	cout << int2string[digit].c_str();

}

void TestMap2()
{
	map <string, int> string2int;

	string2int.insert(make_pair(string("One"), 1));
	string2int.insert(make_pair(string("Two"), 2));
	string2int.insert(make_pair(string("Three"), 3));
	string2int.insert(make_pair(string("Four"), 4));
	string2int.insert(make_pair(string("Five"), 5));

	cout << "Please input a digit: ";

	char digit[10];
	cin >> digit;

	auto iter = string2int.find(string(digit));
	if (iter == string2int.end())
	{
		cout << "Invalid digit." << endl;
	}
	else
	{
		cout << string2int[string(digit)];
	}

// 	for (auto iter = string2int.begin(); iter != string2int.end(); ++iter)
// 	{
// 		cout << (*iter).first.c_str() << " " << (*iter).second << endl;
// 	}
}

void TestVector()
{
	std::vector<int> numbers(100000);
	vector<unsigned int> counts(6, 0);

	for (unsigned int i = 0; i < 100000; ++i)
	{
		// 0 - RAND_MAX 
		numbers[i] = rand() % 6 + 1;
	}

	// ...	
	for (unsigned int i = 0; i < 100000; ++i)
	{
		++counts[numbers[i] - 1];
	}

	for (unsigned int i = 0; i < counts.size(); ++i)
	{
		cout << i + 1 << ": " << counts[i] << endl;
	}
}

void TestVector2()
{
	std::vector<int> numbers;

	for (unsigned int i = 0; i < 100000; ++i)
	{
		// 0 - RAND_MAX 
		numbers.push_back(rand() % 6 + 1);
	}

	// ...	
	vector<unsigned int> counts(6, 0);
	for (auto iter = numbers.begin(); iter != numbers.end(); ++iter)
	{
		++counts[*iter - 1];
	}

	for (unsigned int i = 0; i < counts.size(); ++i)
	{
		cout << i + 1 << ": " << counts[i] << endl;
	}
}

void TestVector3()
{
	list<double> values;
	for (unsigned int i = 0; i < 10; ++i)
	{
		values.push_back(rand() / (double)RAND_MAX);
	}

	// sort(values.begin(), values.end());
	values.sort();

	for (auto iter = values.begin(); iter != values.end(); ++iter)
	{
		cout << *iter << " ";
	}
	cout << endl;
}

void TestList()
{
	list<int> numbers;

	for (unsigned int i = 0; i < 100000; ++i)
	{
		// 0 - RAND_MAX 
		numbers.push_back(rand() % 6 + 1);
	}

	vector<unsigned int> counts(6, 0);
	for (auto iter = numbers.begin(); iter != numbers.end(); ++iter)
	{
		++counts[*iter - 1];
	}

	for (unsigned int i = 0; i < counts.size(); ++i)
	{
		cout << i + 1 << ": " << counts[i] << endl;
	}

}

int _tmain(int argc, _TCHAR* argv[])
{
	WordCount();

	return 0;
}

