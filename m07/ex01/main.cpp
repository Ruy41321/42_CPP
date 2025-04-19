#include <cstdlib>
#include <iostream>
#include <string>
#include <iter.hpp>

using std::cout;
using std::endl;

void transform(int& i)
{
	i *= 10;
}

void display(int *array)
{
	for (int i = 0; i < 3; ++i)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}

int main(void)
{
	int int_array[] = {1, 2, 3};

	display(int_array);

	::iter(int_array, 3, ::transform);

	display(int_array);

	return EXIT_SUCCESS;
}