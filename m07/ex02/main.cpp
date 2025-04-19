#include <cstdlib>
#include <iostream>
#include <string>
#include "Array.hpp"

using std::cout;
using std::cerr;
using std::endl;

#define MAX_VAL 750

int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }
    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}


int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	Array<int>	a(3);
	Array<int>	b(3);

	for (size_t i = 0; i < a.size(); i += 1) {
		cout << "a[" << i << "] = " << a[i] << "\n";
	}
	cout << endl;
	for (size_t i = 0; i < b.size(); i += 1) {
		cout << "b[" << i << "] = " << b[i] << "\n";
	}
	a[0] = 1;
	a[1] = 1;
	a[2] = 1;
	cout << endl;
	cout << "AFTER FILLING A WITH 1's" << endl;
	for (size_t i = 0; i < a.size(); i += 1) {
		cout << "a[" << i << "] = " << a[i] << "\n";
	}
	cout << endl;
	for (size_t i = 0; i < b.size(); i += 1) {
		cout << "b[" << i << "] = " << b[i] << "\n";
	}
	b = a;

	cout << "AFTER B = A" << endl;
	for (size_t i = 0; i < a.size(); i += 1) {
		cout << "a[" << i << "] = " << a[i] << "\n";
	}
	cout << endl;
	for (size_t i = 0; i < b.size(); i += 1) {
		cout << "b[" << i << "] = " << b[i] << "\n";
	}


//     // Empty Array
//     Array<int> empty;

// 	// OUT OF BOUNDS EXCEPTION
//     try {
//         cout << a[a.size() + 1] << endl;
//     }
//     catch (std::exception& e) {
//         cerr << e.what() << endl;
//     }

// 	a[0] = 42;
// 	b[1] = 21;
// 	cout << "AFTER changing values of A and B" << endl;
// 	for (size_t i = 0; i < a.size(); i += 1) {
// 		cout << "a[" << i << "] = " << a[i] << "\n";
// 	}
// 	cout << endl;
// 	for (size_t i = 0; i < b.size(); i += 1) {
// 		cout << "b[" << i << "] = " << b[i] << "\n";
// 	}

// 	return EXIT_SUCCESS;
// }