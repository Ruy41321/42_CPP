#include <cstdlib>
#include <iostream>

#include "includes/Bureaucrat.hpp"
#include "includes/AForm.hpp"
#include "includes/PresidentialPardonForm.hpp"
#include "includes/RobotomyRequestForm.hpp"
#include "includes/ShrubberyCreationForm.hpp"

using std::cout;
using std::cerr;
using std::endl;

#define HIGHEST_GRADE 1
#define LOWEST_GRADE 150

int main (int argc, char **argv)
{
	(void)argc;
	(void)argv;

	Bureaucrat hermano("Hermano", LOWEST_GRADE);

	Bureaucrat ebil("Ebil", HIGHEST_GRADE);
	cout << endl;

	cout << endl;
	ShrubberyCreationForm scf("Ebil");
	PresidentialPardonForm ppf("Ebil");
	RobotomyRequestForm rrf("Ebil");
	cout << endl;

	ebil.executeForm(scf);
	scf.beSigned(ebil);
	ebil.executeForm(scf);

	cout << endl;

	ebil.executeForm(ppf);
	ppf.beSigned(ebil);
	ebil.executeForm(ppf);

	cout << endl;

	ebil.executeForm(rrf);
	rrf.beSigned(ebil);
	ebil.executeForm(rrf);

	cout << endl;

	try {
		hermano.executeForm(scf);
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	cout << endl;
	return EXIT_SUCCESS;
}