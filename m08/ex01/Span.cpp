#include <Span.hpp>

Span::Span(unsigned int N) : _maxN(N)
{
	if (N == 0)
		throw std::invalid_argument("Span size must be greater than 0");
	_vec = std::vector<int>();
	_vec.reserve(N);
}

void Span::addNumber(int n)
{
	if (_vec.size() >= _maxN)
		throw std::out_of_range("Span is full");
	_vec.push_back(n);
}

int Span::longestSpan()
{
	if (_vec.size() < 2)
		throw std::logic_error("Not enough numbers to find a span");
	int min = *std::min_element(_vec.begin(), _vec.end());
	int max = *std::max_element(_vec.begin(), _vec.end());
	return max - min;
}

int Span::shortestSpan()
{
	if (_vec.size() < 2)
		throw std::logic_error("Not enough numbers to find a span");
	std::vector<int> sortedVec = _vec;
	std::sort(sortedVec.begin(), sortedVec.end());
	int minSpan = sortedVec[1] - sortedVec[0];
	for (size_t i = 1; i < sortedVec.size() - 1; i++)
	{
		int diff = sortedVec[i + 1] - sortedVec[i];
		if (diff < minSpan)
			minSpan = diff;
	}
	return minSpan;
}

Span::Span(const Span &src)
{
	*this = src;
}

Span &Span::operator=(const Span &src)
{
	if (this != &src)
	{
		this->_maxN = src._maxN;
		this->_vec = src._vec;
	}
	return *this;
}

Span::~Span()
{
}