#include <iostream>

int main()
{
	std::string str= "HI THIS IS BRAIN";
	std::string* stringPTR = &str;
	std::string& stringREF = str;

	std::cout << &str <<	"\n"
			  << stringPTR << "\n"
			  << &stringREF << "\n";
	std::cout << str <<	"\n"
			  << *stringPTR << "\n"
			  << stringREF << "\n";
}