#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <iostream>

using std::cout;
using std::cerr;
using std::endl;

Base *generate(void)
{
	srand(time(0));
	int random = std::rand() % 3;
	cout << "Random number: " << random << endl;
	switch (random)
	{
		case 0:
			return new A();
		case 1:
			return new B();
		case 2:
			return new C();
		default:
			cerr << "Error: Invalid random number" << endl;
			return NULL;
	}
}

void identify(Base *ptr)
{
	if (dynamic_cast<A*>(ptr))
		cout << "A" << endl;
	else if (dynamic_cast<B*>(ptr))
		cout << "B" << endl;
	else if (dynamic_cast<C*>(ptr))
		cout << "C" << endl;
	else
		cerr << "Error: Unknown type" << endl;
}

void identify(Base &ref)
{
	try
	{
		A &a = dynamic_cast<A&>(ref);
		cout << "A" << endl;
		(void)a;
		return;
	}
	catch (std::exception &e) {}

	try
	{
		B &b = dynamic_cast<B&>(ref);
		cout << "B" << endl;
		(void)b;
		return;
	}
	catch (std::exception &e) {}

	try
	{
		C &c = dynamic_cast<C&>(ref);
		cout << "C" << endl;
		(void)c;
		return;
	}
	catch (std::exception &e) {}
}