#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("noNamer")
{
    std::cout << "Basic Bureaucrat constructor called" << std::endl;
    this->rank = 150;
}

Bureaucrat::Bureaucrat(std::string name, int rank) : name(name)
{
    std::cout << "Bureaucrat constructor called" << std::endl;
    if (rank < 1)
        throw Bureaucrat::GradeTooHighException();
    if (rank > 150)
        throw Bureaucrat::GradeTooLowException();
    this->rank = rank;
}

Bureaucrat::Bureaucrat(Bureaucrat &to_copy)
{
    std::cout << "Bureaucrat copy constructor called" << std::endl;
    *this = to_copy;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat &to_copy)
{
    std::cout << "Bureaucrat assigned operation called" << std::endl;
    const_cast<std::string&>(this->name) = to_copy.name;
    this->rank = to_copy.get_rank();
    return (*this);
}

std::ostream &operator<<(std::ostream &stream, Bureaucrat &Bureaucrat)
{
    stream << Bureaucrat.get_name() << ", bureaucrat grade " << Bureaucrat.get_rank();
    return (stream);
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Destructor of " << this << " called" << std::endl;
}

int Bureaucrat::get_rank()
{
    return (this->rank);
}

std::string Bureaucrat::get_name()
{
    return (this->name);
}   

void Bureaucrat::increment_rank()
{
    if (this->rank == 1)
        throw Bureaucrat::GradeTooHighException();
    this->rank--;
}

void Bureaucrat::decrement_rank()
{
    if (this->rank == 150)
        throw Bureaucrat::GradeTooLowException();
    this->rank++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Grade is too high");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Grade is too low");
}

void Bureaucrat::signForm(std::string form_name, bool is_signed)
{
    if (is_signed)
        std::cout << this->name << " signs " << form_name << std::endl;
    else
        std::cout << this->name << " cannot sign " << form_name << " because grade is too low" << std::endl;
}