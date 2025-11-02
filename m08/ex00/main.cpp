#include "easyfind.hpp"
#include <vector>
#include <iostream>

using std::cout;
using std::cerr;
using std::endl;

int main(void)
{
	std::vector<int> v(5, 42);
	v.at(3) = 21;
	int val_to_find = 22;
	bool found;
	try{ 
		found = easyfind(v, val_to_find);
	}
	catch (const ValueNotFoundException& e)
	{
		found = false;
	}
	cout << val_to_find << " is in the vector: " << (found ? "true" : "false") << endl;
	return EXIT_SUCCESS;
}