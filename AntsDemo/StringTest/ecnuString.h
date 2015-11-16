#ifndef _ECNU_STRING
#define _ECNU_STRING

#include <iostream>

namespace ecnu{
	class string
	{
	public:
		string();
		string(const char * str);
		string(const string& rhs);

		~string();

		unsigned int GetLength() const;

		const string& operator = (const string& rhs);
		string operator + (const string& rhs);
		bool operator==(const string& rhs);

		char& operator[](int index);

	private:
		char * _buffer;
		unsigned int _buffer_size;

		friend std::ostream& operator << (std::ostream& os, 
			const ecnu::string& str);
		friend std::istream& operator >> (std::istream& is,
			ecnu::string& str);

	};

	ecnu::string operator + (const char * lhs, const ecnu::string& rhs);
}


#endif