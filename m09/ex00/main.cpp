#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	if (argc != 2) {
		std::cerr << "Error: could not open file." << std::endl;
		return 1;
	}

	try {
		BitcoinExchange exchange;
		exchange.loadData("data.csv");
		exchange.printValues(argv[1]);
	} catch (const std::exception &e) {
		std::cerr << "Error: could not open file." << std::endl;
		return 1;
	}

	return 0;
}