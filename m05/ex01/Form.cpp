#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : name("default"), sign_grade(150), exec_grade(150)
{
    std::cout << "Default Form constructor called" << std::endl;
    is_signed = false;
}

Form::Form(std::string name, int sign_grade, int exec_grade) : name(name), sign_grade(sign_grade), exec_grade(exec_grade)
{
    std::cout << "Form constructor called" << std::endl;
    if (sign_grade < 1 || exec_grade < 1)
        throw Form::GradeTooHighException();
    if (sign_grade > 150 || exec_grade > 150)
        throw Form::GradeTooLowException();
    is_signed = false;
}

Form::Form(Form &to_copy) 
    : name(to_copy.name), sign_grade(to_copy.sign_grade), exec_grade(to_copy.exec_grade)
{
    std::cout << "Form copy constructor called" << std::endl;
    this->is_signed = to_copy.is_signed;
}

Form &Form::operator=(Form &to_copy)
{
    std::cout << "Form assigned operation called" << std::endl;
    const_cast<std::string&>(this->name) = to_copy.get_name();
    const_cast<int&>(this->sign_grade) = to_copy.get_sign_grade();
    const_cast<int&>(this->exec_grade) = to_copy.get_exec_grade();
    this->is_signed = to_copy.get_is_signed();
    return (*this);
}

Form::~Form()
{
    std::cout << "Destructor of " << this << " called" << std::endl;
}

std::string Form::get_name()
{
    return (this->name);
}

bool Form::get_is_signed()
{
    return (this->is_signed);
}

int Form::get_sign_grade()
{
    return (this->sign_grade);
}

int Form::get_exec_grade()
{
    return (this->exec_grade);
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
    if (bureaucrat.get_rank() > this->sign_grade)
    {
        bureaucrat.signForm(this->name, this->is_signed);
        throw Form::GradeTooLowException();
    }
    this->is_signed = true;
    bureaucrat.signForm(this->name, this->is_signed);
}

const char *Form::GradeTooHighException::what() const throw()
{
    return ("Grade is too high");
}

const char *Form::GradeTooLowException::what() const throw()
{
    return ("Grade is too low");
}

std::ostream &operator<<(std::ostream &stream, Form &form)
{
    stream << "Form " << form.get_name() << " is signed: " << form.get_is_signed() << ", sign grade: " << form.get_sign_grade() << ", exec grade: " << form.get_exec_grade();
    return (stream);
}