#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>
#include <iterator>

class Span
{
private:
	unsigned int _maxN;
	std::vector<int> _vec;

public:
	Span(unsigned int N);
	Span(const Span &src);
	Span &operator=(const Span &src);
	~Span();
	void addNumber(int n);
	int longestSpan();
	int shortestSpan();
	
	template<typename Iterator>
	void addNumbers(Iterator begin, Iterator end)
	{
		while (begin != end)
		{
			if (_vec.size() >= _maxN)
				throw std::out_of_range("Span is full");
			_vec.push_back(*begin);
			++begin;
		}
	}
};

#endif