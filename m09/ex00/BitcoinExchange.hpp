#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>

class BitcoinExchange {
private:
	std::map<std::string, double> data;
public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &other);
	BitcoinExchange &operator=(const BitcoinExchange &other);
	~BitcoinExchange();

	void loadData(const std::string &database);
	void printValues(const std::string &filename);

	// class OpeningFileException : public std::exception {
	// 	public:
	// 		virtual const char* what(void) const throw();
	// };
};

#endif