#include <RPN.hpp>

#include <sstream>
#include <stack>
#include <string>
#include <cstdlib>
#include <iostream>

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
		if (isdigit(token[0])) {
			stack.push(std::strtol(token.c_str(), NULL, 10));
		} else {
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
				case '/': stack.push(a / b); break;
				default: throw std::invalid_argument("Invalid operator");
			}
		}
	}

	return stack.top();
}