#include <BitcoinExchange.hpp>

#include <iostream>

int main(int argc, char **argv)
{
	if (argc != 2) {
		std::cerr << "Usage: " << argv[0] << " <filename>" << std::endl;
		return 1;
	}

	try {
		BitcoinExchange exchange;
		exchange.loadData("data.csv");
		exchange.printValues(argv[1]);
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}

	return 0;
}