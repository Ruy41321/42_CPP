#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/AForm.hpp"
#include "../includes/Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", target, 25, 5)
{
    std::cout << "PresidentialPardonForm constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy)
: AForm(copy.get_name(), copy.get_target(), copy.get_sign_grade(), copy.get_exec_grade()) {
		std::cout << "[PresidentialPardonForm] Copy Constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
    std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &presForm)
{
    std::cout << "PresidentialPardonForm assigned operation called" << std::endl;
	if (this == &presForm)
		return (*this);
    return (*this);
}

void PresidentialPardonForm::superExecute(Bureaucrat const& bureaucrat) const
{
    if (bureaucrat.get_rank() > this->get_exec_grade())
		throw Bureaucrat::GradeTooLowException();
	else if (this->get_is_signed() == false)
		std::cerr << "The PresidentialPardonForm isn't signed!" << std::endl;
	else
		std::cout << this->get_target() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}