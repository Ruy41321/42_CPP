#ifndef ITER_HPP
#define ITER_HPP

template <typename AnyType>
void iter(AnyType* array, size_t length, void (*func)(AnyType&))
{
	for (size_t i = 0; i < length; ++i)
	{
		func(array[i]);
	}
}

#endif