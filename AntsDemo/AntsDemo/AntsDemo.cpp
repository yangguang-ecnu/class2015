// AntsDemo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>

const int STICK_LENGTH = 79;

using namespace std;

struct Ant
{
	Ant(char name, unsigned int position, int direction) : name(name), position(position), direction(direction)
	{
	};
	unsigned int position;
	char name;
	int direction; // -1 means left, +1 means right 
};

char stick[STICK_LENGTH + 1] = { 0 };

vector<Ant> g_ants;
// Ant g_ants[3];

void InitAnts(vector<Ant> & ants)
{
	ants.push_back(Ant('A', 0, 1));
	ants.push_back(Ant('B', 1, 1));
	ants.push_back(Ant('C', 2, 1));

	ants.push_back(Ant('X', 78, -1));
	ants.push_back(Ant('Y', 77, -1));
	ants.push_back(Ant('Z', 76, -1));
}

void UpdateStick(char stick[STICK_LENGTH + 1], vector<Ant>& ants)
{
	for (unsigned int i = 0; i < STICK_LENGTH; ++i)
	{
		stick[i] = ' ';
	}
	stick[STICK_LENGTH] = '\0';

	for (unsigned int i = 0; i < ants.size(); ++i)
	{
		if (ants[i].position < STICK_LENGTH)
		{
			stick[ants[i].position] = ants[i].name;
		}
	}
}

void OutputStick(char stick[STICK_LENGTH + 1])
{
	cout << '\r' << stick;
}

Ant* FindAnt(unsigned int position, vector<Ant>& ants)
{
	if (position >= STICK_LENGTH)
		return nullptr;

	if (stick[position] == ' ')
		return nullptr;

	for (unsigned int i = 0; i < ants.size(); ++i)
	{
		if (ants[i].name == stick[position])
			return &ants[i];
	}

	return nullptr;
}

bool ShouldUTurn(Ant& ant, vector<Ant>& ants)
{
	Ant * next_ant = FindAnt(ant.position + ant.direction, ants);

	if (next_ant == nullptr)
	{
		return false;
	}
	else
	{
		return ant.direction != next_ant->direction || 
			(ant.direction == next_ant->direction && (ShouldUTurn(*next_ant, ants)));
	}
}

bool ShouldUTurn2(Ant& ant, vector<Ant>& ants)
{
	for (int i = 0; i < ants.size(); ++i)
	{
		if (&ants[i] != &ant && ants[i].position == ant.position)
			return true;
	}

	return false;
}

void UpdateAnts(vector<Ant>& ants)
{
	vector<Ant> old_ants = ants;

	for (unsigned int i = 0; i < ants.size(); ++i)
	{
		if (ShouldUTurn(old_ants[i], old_ants) || ShouldUTurn2(old_ants[i], old_ants))
		{
			ants[i].direction *= -1;
			ants[i].position += ants[i].direction;
		}
		else
		{
			ants[i].position += ants[i].direction;
		}
	}
}

void Wait()
{
	for (unsigned int i = 0; i < 3000000; ++i)
	{
		double x = sin(0);
	}
}

bool IsEmpty(char stick[STICK_LENGTH + 1])
{
	for (unsigned int i = 0; i < STICK_LENGTH; ++i)
	{
		if (stick[i] != ' ')
			return false;
	}

	return true;
}

int _tmain(int argc, _TCHAR* argv[])
{
	InitAnts(g_ants);
	UpdateStick(stick, g_ants);
	OutputStick(stick);

	while (!IsEmpty(stick))
	{
		UpdateAnts(g_ants);
		UpdateStick(stick, g_ants);
		OutputStick(stick);
		Wait();
	}
	
	return 0;
}

