#include <BitcoinExchange.hpp>

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib> 
#include <algorithm>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {
    *this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
    if (this != &other) {
        data = other.data;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::loadData(const std::string &database) {
    std::ifstream file(database.c_str());
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file: " + database);
    }

    std::string line;
    std::getline(file, line); // Ignora l'intestazione
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string date;
        std::string valueStr;

        // Usa std::getline per separare la data e il valore usando la virgola come delimitatore
        if (std::getline(iss, date, ',') && std::getline(iss, valueStr)) {
            try {
                double value = std::strtod(valueStr.c_str(), NULL); // Converte il valore da stringa a double
                data[date] = value; // Memorizza la coppia (data, valore) nella mappa
            } catch (...) {
                throw std::runtime_error("Invalid value in line: " + line);
            }
        } else {
            std::cerr << "Error: Malformed line: " << line << std::endl;
            throw std::runtime_error("Malformed line");
        }
    }

    file.close();
}

int isDateInvalid(const std::string &date) {
	// Controlla se la data è nel formato YYYY-MM-DD
	if (date.length() != 10 || date[4] != '-' || date[7] != '-') {
		return 1;
	}
	// Controlla se l'anno, il mese e il giorno sono numeri
	for (int i = 0; i < int(date.length()); ++i) {
		if (i == 4 || i == 7) continue; // Ignora i trattini
		if (!isdigit(date[i])) {
			return 1;
		}
	}
	return 0; 
}

int isLineValid(std::string &line) {
    size_t pipePos = line.find('|');
    if (pipePos == std::string::npos) {
        return 0;
    }
    // Controlla se c'è uno spazio prima del '|'
    if (pipePos == 0 || line[pipePos - 1] != ' ') {
        return 0;
    }
    // Controlla se c'è uno spazio dopo il '|'
    if (pipePos + 1 >= line.length() || line[pipePos + 1] != ' ') {
        return 0;
    }
    return 1;
}

void BitcoinExchange::printValues(const std::string &filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file: " + filename);
    }
    std::string line;
    std::getline(file, line); // Ignora l'intestazione
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string date;
        std::string valueStr;

        if (isLineValid(line) && std::getline(iss, date, '|') && std::getline(iss, valueStr)) {
            date.erase(std::remove(date.begin(), date.end(), ' '), date.end());
            try {
                double value = std::strtod(valueStr.c_str(), NULL);
                if (value < 0) {
                    std::cerr << "Error: Not a positive number." << std::endl;
                    continue;
                }
                if (value > 1000) {
                    std::cerr << "Error: Too large a number." << std::endl;
                    continue;
                }
				if (isDateInvalid(date)) {
					std::cerr << "Error: Invalid date format." << std::endl;
					continue;
				}
                std::map<std::string, double>::iterator it = data.lower_bound(date);
                if (it == data.end()) {
                    std::cerr << "Error: Date not found in database." << std::endl;
                    continue;
                }
                double rate = it->second;
                std::cout << date << " => " << value << " = " << value * rate << std::endl;
            } catch (...) {
                std::cerr << "Error: Invalid value in line: " << line << std::endl;
            }
        } else {
            std::cerr << "Error: bad input => " << line << std::endl;
        }
    }
    file.close();
}
