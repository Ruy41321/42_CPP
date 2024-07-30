#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

using std::cout;
using std::cerr;
using std::endl;

Intern::Intern(void) {
    cout << "Intern Default Constructor called" << endl;
}

Intern::Intern(const Intern &copy)
{
	*this = copy;
	cout << "Intern Copy Constructor called" << endl;
}

Intern::~Intern() {
   	cout << "Intern Destructor called" << endl;
}

Intern& Intern::operator=(const Intern &assign)
{
	cout << "Intern Copy Assignment Operator called" << endl;
	if (this == &assign)
		return *this;
	return *this;
}

static AForm *createShrubberyCreation(const std::string target) {
	return new ShrubberyCreationForm(target);
}

static AForm *createRobotomyRequest(const std::string target) {
	return new RobotomyRequestForm(target);
}

static AForm *createPresidentialPardon(const std::string target) {
	return new PresidentialPardonForm(target);
}

typedef AForm *(*Form_factory)(const std::string);

AForm *Intern::makeForm(std::string name, std::string target)
{
	const std::string form_names[3] = {"shrubbery creation", "presidential pardon", "robotomy request"};
	Form_factory form_factory[3] = {&createShrubberyCreation, &createPresidentialPardon, &createRobotomyRequest};
	for (int i = 0; i < 3; i++)
	{
		if (name == form_names[i])
		{
			std::cout << "Intern creates " << name << std::endl;
			return form_factory[i](target);
		}
	}
    cerr << "Intern can't create no form with that name	" << endl;
    return NULL;
}