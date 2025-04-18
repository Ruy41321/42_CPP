#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

#define CHAR 1
#define INT 2
#define FLOAT 3
#define DOUBLE 4
#define INVALID 0

class ScalarConverter
{
	private:
		ScalarConverter() {}

	public:
		static void convert(std::string str);
};

#endif