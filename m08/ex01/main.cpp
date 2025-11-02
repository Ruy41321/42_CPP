#include "Span.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

int main()
{
	std::cout << "=== Test from subject ===" << std::endl;
	try
	{
		Span sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test with 10,000 numbers ===" << std::endl;
	try
	{
		Span sp2 = Span(10000);
		std::vector<int> numbers;
		
		std::srand(std::time(0));
		for (int i = 0; i < 10000; i++)
		{
			numbers.push_back(std::rand() % 50000);
		}
		
		sp2.addNumbers(numbers.begin(), numbers.end());
		
		std::cout << "Added 10,000 numbers" << std::endl;
		std::cout << "Shortest span: " << sp2.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp2.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test with addNumbers using array ===" << std::endl;
	try
	{
		Span sp3 = Span(10);
		int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
		
		sp3.addNumbers(arr, arr + 10);
		
		std::cout << "Shortest span: " << sp3.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp3.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test exceptions ===" << std::endl;
	try
	{
		Span sp4 = Span(3);
		sp4.addNumber(1);
		sp4.addNumber(2);
		sp4.addNumber(3);
		sp4.addNumber(4); // Should throw
	}
	catch (std::exception &e)
	{
		std::cerr << "Expected error: " << e.what() << std::endl;
	}

	try
	{
		Span sp5 = Span(1);
		sp5.addNumber(42);
		sp5.shortestSpan(); // Should throw
	}
	catch (std::exception &e)
	{
		std::cerr << "Expected error: " << e.what() << std::endl;
	}

	try
	{
		Span sp6 = Span(5);
		std::vector<int> tooMany;
		for (int i = 0; i < 10; i++)
			tooMany.push_back(i);
		sp6.addNumbers(tooMany.begin(), tooMany.end()); // Should throw
	}
	catch (std::exception &e)
	{
		std::cerr << "Expected error: " << e.what() << std::endl;
	}

	return 0;
}