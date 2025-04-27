#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>
#include <iterator>
#include <cstdlib>
#include <ctime>

class Span
{
private:
	unsigned int _maxN;

public:
	std::vector<int> _vec;
	Span(unsigned int N);
	Span(const Span &src);
	Span &operator=(const Span &src);
	~Span();
	void addNumber(int n);
	int longestSpan();
	int shortestSpan();
	void addMultipleNumbers(int n);
};

#endif