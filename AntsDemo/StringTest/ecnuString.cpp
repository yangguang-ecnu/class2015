#include "stdafx.h"

#include "ecnuString.h"
#include <string.h>
#include <assert.h>
#include <xutility>

namespace ecnu{

string::string() :
	_buffer(nullptr),
	_buffer_size(0)
{
}

string::string(const char * str)
{
	_buffer_size = strlen(str) + 1;
	_buffer = new char[_buffer_size];
	strcpy(_buffer, str);
}

string::string(const string& rhs) 
{
	_buffer_size = strlen(rhs._buffer) + 1;
	_buffer = new char[_buffer_size];
	strcpy(_buffer, rhs._buffer);
}

string::~string()
{
	if (_buffer != nullptr){
		delete[] _buffer;
	}
}
string string::operator+=(const string& rhs)
{
	char * olddata = _buffer;
	_buffer_size += rhs._buffer_size;
	_buffer = new char[_buffer_size + 1];
	if (rhs._buffer != '\0')
	{
		strcpy(_buffer, olddata);
	}
	else
			_buffer = '\0';
	strcat(_buffer, rhs._buffer);
	delete[] olddata;
	return *this;

}
string string::operator+(const string& rhs)
{
	string result;
	result._buffer = new char[strlen(_buffer) + strlen(rhs._buffer) + 1];
	char * dest = result._buffer;
	char * source = _buffer;

	while (*source != 0)
	{
		*dest++ = *source++;
	}

	source = rhs._buffer;
	while (*source != 0)
	{
		*dest++ = *source++;
	}
	*dest = 0;

	return result;
}

char& string::operator[](int index)
{
	assert(_buffer != nullptr);
	assert(_buffer_size > index);

	return _buffer[index];
}

unsigned int string::GetLength() const
{
	return strlen(_buffer);
}

bool string::operator==(const string& rhs)
{
	return strcmp(_buffer, rhs._buffer) == 0;
}

const string& ecnu::string::operator=(const string& rhs)
{
	if (&rhs == this)
		return *this;

	if (_buffer != nullptr && _buffer_size < strlen(rhs._buffer) + 1)
	{
		delete[]_buffer;
		_buffer = nullptr;
	}

	if (_buffer_size < strlen(rhs._buffer) + 1)
	{
		_buffer = new char[strlen(rhs._buffer) + 1];
	}

	strcpy(_buffer, rhs._buffer);

	return *this;
}

std::ostream& operator << (std::ostream& os, 
	const ecnu::string& str)
{
	os << str._buffer;

	return os;
}

std::istream& operator >> (std::istream& is,
	ecnu::string& str)
{
	char buffer[256];
	is >> buffer;
	str = ecnu::string(buffer);

	return is;
}

ecnu::string operator+(const char * lhs, const ecnu::string& rhs)
{
	return ecnu::string(lhs) + rhs;
}

}