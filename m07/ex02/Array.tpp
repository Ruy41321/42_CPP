#include <Array.hpp>

template <typename T>
Array<T>::Array(unsigned int new_size) : length(new_size)
{
	array = new T[length];
}

template <typename T>
Array<T>::Array() : length(0)
{
	array = new T[0];
}

template <typename T>
Array<T>::~Array()
{
	if (array)
		delete[] array;
}

template <typename T>
Array<T>::Array(Array &to_copy) : array(new T[0]), length(0)
{
	*this = to_copy;
}

#include <iostream>

template <typename T>
Array<T> &Array<T>::operator=(Array &to_copy)
{
	if (this == &to_copy)
		return *this;
		
	if (array)
		delete[] array;
	length = to_copy.length;
	array = new T[length];
	for (size_t i = 0; i < length; i++) {
		array[i] = to_copy.array[i];
	}
	return *this;
}

template <typename T>
char const*	Array<T>::InvalidIndexException::what(void) const throw() {
	return "Array exception: index out of range";
}

template <typename T>
T &Array<T>::operator[](size_t index)
{
	if (index >= length)
		throw Array::InvalidIndexException();
	return array[index];
}

template <typename T>
size_t Array<T>::size()
{
	return length;
}
