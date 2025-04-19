#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename AnyType>
void swap(AnyType& a, AnyType& b)
{
	AnyType temp;

	temp = a;
	a = b;
	b = temp;
}

template <typename AnyType>
AnyType min(AnyType a, AnyType b)
{
	return (a < b) ? a : b;
}

template <typename AnyType>
AnyType max(AnyType a, AnyType b)
{
	return (a > b) ? a : b;
}

#endif