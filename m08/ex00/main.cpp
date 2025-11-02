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
	int val_to_find = 5;
	bool found = false;
	try{ 
		std::vector<int>::iterator it = easyfind(v, val_to_find);
		found = true;
		cout << val_to_find << " found at position: " << std::distance(v.begin(), it) << endl;
	}
	catch (const ValueNotFoundException& e)
	{
		cout << val_to_find << " not found in the vector" << endl;
	}
	cout << val_to_find << " is in the vector: " << (found ? "true" : "false") << endl;
	return EXIT_SUCCESS;
}