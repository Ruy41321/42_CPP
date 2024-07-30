#include <cstdlib>
#include <iostream>

#include "includes/Intern.hpp"
#include "includes/AForm.hpp"

using std::cout;
using std::cerr;
using std::endl;

#define HIGHEST_GRADE 1
#define LOWEST_GRADE 150

int main ()
{

	Intern someRandomIntern;
	AForm* rrf;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");

	std::cout << *rrf << std::endl;
}