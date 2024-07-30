#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/AForm.hpp"
#include "../includes/Bureaucrat.hpp"
#include <ctime>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", target, 72, 45)
{
    std::cout << "RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy)
: AForm(copy.get_name(), copy.get_target(), copy.get_sign_grade(), copy.get_exec_grade()) {
		std::cout << "[RobotomyRequestForm] Copy Constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
    std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &presForm)
{
    std::cout << "RobotomyRequestForm assigned operation called" << std::endl;
	if (this == &presForm)
		return (*this);
    return (*this);
}

void RobotomyRequestForm::superExecute(Bureaucrat const& bureaucrat) const
{
    if (bureaucrat.get_rank() > this->get_exec_grade())
		throw AForm::GradeTooLowException();
	else if (this->get_is_signed() == false)
		throw AForm::FormNotSignedException();
	else
		{
		std::srand(std::time(NULL));

		std::cout << "BZZZZZZZZZZzzzzzzzzzzzzz" << std::endl;

		if (random() % 2 == 0)
			std::cout << this->get_target() << " successfully robotomized." << std::endl;
		else
			std::cout << this->get_target() << " robotomized failed." << std::endl;
		}
}