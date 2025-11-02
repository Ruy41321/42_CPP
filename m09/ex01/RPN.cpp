#include "RPN.hpp"
#include <sstream>
#include <stdexcept>

RPN::RPN() {}

RPN::RPN(const RPN& other) {
	*this = other;
}

RPN& RPN::operator=(const RPN& other) {
	(void)other;
	return *this;
}

RPN::~RPN() {}

long long RPN::calculate(const std::string& expression) {
	std::stack<int> stack;
	std::istringstream iss(expression);
	std::string token;

	while (iss >> token) {
		// Verifica se il token è un singolo digit (numero < 10)
		if (token.length() == 1 && isdigit(token[0])) {
			stack.push(token[0] - '0');
		} 
		// Verifica se il token è un operatore valido
		else if (token.length() == 1 && 
		         (token[0] == '+' || token[0] == '-' || 
		          token[0] == '*' || token[0] == '/')) {
			if (stack.size() < 2) {
				throw std::invalid_argument("Not enough operands");
			}
			int b = stack.top(); 
			stack.pop();
			int a = stack.top(); 
			stack.pop();
			
			switch (token[0]) {
				case '+': stack.push(a + b); break;
				case '-': stack.push(a - b); break;
				case '*': stack.push(a * b); break;
				case '/': 
					if (b == 0) {
						throw std::invalid_argument("Division by zero");
					}
					stack.push(a / b); 
					break;
			}
		} 
		else {
			throw std::invalid_argument("Invalid token");
		}
	}

	// Verifica che ci sia esattamente un elemento nello stack
	if (stack.size() != 1) {
		throw std::invalid_argument("Invalid expression");
	}

	return stack.top();
}