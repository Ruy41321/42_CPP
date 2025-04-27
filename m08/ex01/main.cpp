#include <Span.hpp>

#include <iostream>

int main()
{
	Span sp = Span(5);

	sp.addMultipleNumbers(5);

	for (int i = 0; i < 5; ++i)
	{
		std::cout << "Number " << i + 1 << ": " << sp._vec[i] << std::endl;
	}
 
	std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;

	return 0;
}