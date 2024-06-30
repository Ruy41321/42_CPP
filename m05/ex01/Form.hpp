#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Form
{
private:
    const std::string name;
    bool is_signed;
    const int sign_grade;
    const int exec_grade;
public:
    Form();
    Form(std::string name, int sign_grade, int exec_grade);
    Form(Form &to_copy);
    Form &operator=(Form &to_copy);
    ~Form();

    std::string get_name();
    bool get_is_signed();
    int get_sign_grade();
    int get_exec_grade();

    void beSigned(Bureaucrat &bureaucrat);

    class GradeTooHighException : public std::exception
    {
        virtual const char *what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
        virtual const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &stream, Form &Form);

#endif