#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <exception>

class ValueNotFoundException : public std::exception {
	public:
		const char* what() const throw() {
			return "EasyFindException: value not found";
		}
	};

template <typename T>
typename T::iterator easyfind(T& container, int param)
{
	typename T::iterator it = std::find(container.begin(), container.end(), param);
	if (it == container.end())
		throw ValueNotFoundException();
	return it;
}

#endif