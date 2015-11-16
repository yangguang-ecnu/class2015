// VectorTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <wchar.h>
#include <assert.h>
#include "ecnuString.h"

using namespace std;

namespace ecnu {
	template<typename TYPE>
	class vector{
	public:
		vector() : _buffer_size(2), _count(0) {
			_buffer = new TYPE[_buffer_size];
		}

		vector(const vector& rhs) : _buffer_size(rhs._buffer_size),
			_count(rhs._count){
			_buffer = new TYPE[_buffer_size];
		}

		~vector(){ if (_buffer != nullptr)
			delete[] _buffer; 
		}
		
		const vector& operator = (const vector& rhs){
			if (&rhs == this)
				return *this;

			if (_buffer != nullptr){
				delete _buffer;
				_buffer = nullptr;
			}

			_buffer_size = rhs._buffer_size;
			_count = rhs._count;
			_buffer = new TYPE[_buffer_size];

			memcpy(_buffer, rhs._buffer, sizeof(TYPE) * _count);
		}

		TYPE & operator [] (int index){
			assert(index >= 0 && index < _count);

			return _buffer[index];
		}

		unsigned int size() const{
			return _count;
		}

		void push_back(TYPE value){
			if (_count >= _buffer_size){
				TYPE * new_buffer = new TYPE[2 * _buffer_size];

				for (unsigned int i = 0; i < _count; ++i){
					new_buffer[i] = _buffer[i];
				}

				delete[]_buffer;
				_buffer_size = 2 * _buffer_size;
				_buffer = new_buffer;
			}

			_buffer[_count++] = value;
		}
	private:
		TYPE * _buffer;
		unsigned int _buffer_size;
		unsigned int _count;
	};
}

void TestDoubleVector();

void TestStringVector()
{
	ecnu::vector<ecnu::string> names;
	for (;;)
	{
		ecnu::string name;
		cout << "Please input a name: ";
		cin >> name;
		if (name == "END"){
			break;
		}

		names.push_back(name);
	}

	for (unsigned int i = 0; i < names.size(); ++i)
	{
		cout << names[i] << endl;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	// TestDoubleVector();
	TestStringVector();
	return 0;
}

void TestDoubleVector()
{
	ecnu::vector<double> scores;
	for (;;)
	{
		double temp;
		cout << "Please input a score (negative to stop): ";
		cin >> temp;
		if (temp < 0){
			break;
		}

		scores.push_back(temp);
	}

	double sum = 0.0;
	for (int i = 0; i < scores.size(); ++i){
		sum += scores[i];
	}

	cout << "Average score is: " << sum / scores.size();
}

