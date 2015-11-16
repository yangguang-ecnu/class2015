#pragma once

enum Sex
{
	SexMale,
	SexFemale,
	SexUnknown,
};

struct Student
{
	char name[20];
	unsigned int age;
	enum Sex sex;

};


class CCanvas
{
public:
	CCanvas();
	CCanvas(unsigned int width, unsigned int height);
	~CCanvas();

	bool Init(unsigned width, unsigned height);
	void DrawVerticalLine(unsigned x, unsigned y1, unsigned y2);
	void DrawHorizontalLine(unsigned y, unsigned x1, unsigned x2);
	void DrawRect(unsigned top, unsigned left, unsigned width, unsigned height);
	void Output();

private:
	unsigned _width;
	unsigned _height;
	char * _buffer;
};



