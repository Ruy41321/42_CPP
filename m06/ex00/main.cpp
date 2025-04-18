#include "includes/ScalarConverter.hpp"

#include <iostream>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "You must insert 1 parameter" << std::endl;
		return 1;
	}
	ScalarConverter::convert(argv[1]);
	return 0;
}