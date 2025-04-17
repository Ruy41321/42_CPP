#include "includes/ScalarConvert.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage: ./convert [value]" << std::endl;
		return 1;
	}
	ScalarConvert::convert(argv[1]);
	return 0;
}