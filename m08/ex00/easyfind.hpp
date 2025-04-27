#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <exception>
#include <iostream>

class ValueNotFoundExcpetion : public std::exception {
	public:
		const char* what() const throw() {
			return "EasyFindException: value not found";
		}
	};

template <typename T>
bool easyfind(T& container, int param)
{
	if (std::find(container.begin(), container.end(), param) == container.end())
	{
		throw ValueNotFoundExcpetion();
		return false;
	}
	else
		return true;
}

#endif