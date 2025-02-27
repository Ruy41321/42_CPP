#include <cstdlib>
#include <iostream>

#include "includes/Intern.hpp"
#include "includes/AForm.hpp"
#include "includes/Bureaucrat.hpp"

using std::cout;
using std::cerr;
using std::endl;

#define HIGHEST_GRADE 1
#define LOWEST_GRADE 150

int main ()
{

	Bureaucrat ebil("Ebil", HIGHEST_GRADE);
	Intern someRandomIntern;
	AForm* rrf;
	rrf = someRandomIntern.makeForm(SHRUBBERY, "Bender");

	rrf->beSigned(ebil);
	ebil.executeForm(*rrf);
	std::cout << *rrf << std::endl;
	delete rrf;
}