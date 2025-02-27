#include "../includes/AForm.hpp"
#include "../includes/Bureaucrat.hpp"

AForm::AForm() : name("default"), sign_grade(150), exec_grade(150)
{
    std::cout << "Default AForm constructor called" << std::endl;
    is_signed = false;
}

AForm::AForm(std::string name, std::string target, int sign_grade, int exec_grade) : name(name), target(target), sign_grade(sign_grade), exec_grade(exec_grade)
{
    std::cout << "AForm constructor called" << std::endl;
    if (sign_grade < 1 || exec_grade < 1)
        throw AForm::GradeTooHighException();
    if (sign_grade > 150 || exec_grade > 150)
        throw AForm::GradeTooLowException();
    is_signed = false;
}

AForm::AForm(AForm &to_copy) 
    : name(to_copy.get_name()), target(to_copy.get_target()), sign_grade(to_copy.get_sign_grade()), exec_grade(to_copy.get_exec_grade())
{
    std::cout << "AForm copy constructor called" << std::endl;
    this->is_signed = to_copy.get_is_signed();
}

AForm &AForm::operator=(AForm &to_copy)
{
    std::cout << "AForm assigned operation called" << std::endl;
    const_cast<std::string&>(this->name) = to_copy.get_name();
    const_cast<std::string&>(this->target) = to_copy.get_target();
    const_cast<int&>(this->sign_grade) = to_copy.get_sign_grade();
    const_cast<int&>(this->exec_grade) = to_copy.get_exec_grade();
    this->is_signed = to_copy.get_is_signed();
    return (*this);
}

AForm::~AForm()
{
    std::cout << "Destructor of AForm: " << this << " called" << std::endl;
}

std::string AForm::get_name() const
{
    return (this->name);
}

std::string AForm::get_target() const
{
    return (this->target);
}

bool AForm::get_is_signed() const
{
    return (this->is_signed);
}

int AForm::get_sign_grade() const
{
    return (this->sign_grade);
}

int AForm::get_exec_grade() const
{
    return (this->exec_grade);
}

void AForm::beSigned(Bureaucrat &bureaucrat)
{
    if (bureaucrat.get_rank() > this->sign_grade)
    {
        bureaucrat.signForm(this->name, this->is_signed);
        throw AForm::GradeTooLowException();
    }
    this->is_signed = true;
    bureaucrat.signForm(this->name, this->is_signed);
}

void AForm::execute(Bureaucrat const& executor) const {
	try
    {
        this->superExecute(executor);
    }
    catch(const std::exception& e)
    {
        throw;
    }
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return ("Grade is too high");
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return ("Grade is too low");
}

const char *AForm::FormNotSignedException::what() const throw()
{
    return ("The form isn't signed");
}

std::ostream &operator<<(std::ostream &stream, AForm &form)
{
    stream << "AForm " << form.get_name() << " is signed: " << form.get_is_signed() << ", sign grade: " << form.get_sign_grade() << ", exec grade: " << form.get_exec_grade();
    return (stream);
}