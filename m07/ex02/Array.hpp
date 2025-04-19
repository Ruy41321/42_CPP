#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array
{
private:
	T* array;
	unsigned int length;

public:
	Array(unsigned int length);
	Array();
	~Array();

    Array(Array &to_copy);
    Array &operator=(Array &to_copy);
	T& operator[](size_t index);
	size_t size();

	class InvalidIndexException : public std::exception {
		public:
			virtual const char* what(void) const throw();
	};
};

#include "Array.tpp"

#endif