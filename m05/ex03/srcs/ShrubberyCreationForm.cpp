#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/AForm.hpp"
#include "../includes/Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", target, 145, 137)
{
    std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy)
: AForm(copy.get_name(), copy.get_target(), copy.get_sign_grade(), copy.get_exec_grade()) {
		std::cout << "[ShrubberyCreationForm] Copy Constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
    std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &presForm)
{
    std::cout << "ShrubberyCreationForm assigned operation called" << std::endl;
	if (this == &presForm)
		return (*this);
    return (*this);
}

void ShrubberyCreationForm::superExecute(Bureaucrat const& bureaucrat) const
{
    if (bureaucrat.get_rank() > this->get_exec_grade())
		throw AForm::GradeTooLowException();
    else if (this->get_is_signed() == false)
    {	
        throw AForm::FormNotSignedException();
    }
	else
	{
		std::ofstream out;

		out.open((this->get_target() + "_shrubbery").c_str(), std::ofstream::in | std::ofstream::trunc);
		
		out << "         /  \\         \n";
        out << "        /    \\        \n";
        out << "       /      \\       \n";
        out << "      /        \\      \n";
        out << "     /          \\     \n";
        out << "    /            \\    \n";
        out << "   /              \\   \n";
        out << "  /                \\  \n";
        out << " /                  \\ \n";
        out << "/____________________\\\n";
        out << "          ||          \n";
        out << "          ||          \n";
        out << "          ||          \n";
        out << "         /  \\         \n";
        out << "        /____\\        \n";
		
	}
}