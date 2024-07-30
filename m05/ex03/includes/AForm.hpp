#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>

class Bureaucrat; 

class AForm
{
private:
    const std::string name;
    const std::string target;
    bool is_signed;
    const int sign_grade;
    const int exec_grade;
public:
    AForm();
    AForm(std::string name, std::string target, int sign_grade, int exec_grade);
    AForm(AForm &to_copy);
    AForm &operator=(AForm &to_copy);
    virtual ~AForm();

    std::string get_name() const;
    std::string get_target() const;
    bool get_is_signed() const;
    int get_sign_grade() const;
    int get_exec_grade() const;

    void beSigned(Bureaucrat &bureaucrat);
    void execute(Bureaucrat const& bureaucrat) const;
    virtual void superExecute(Bureaucrat const& bureaucrat) const = 0;

    class GradeTooHighException : public std::exception
    {
        virtual const char *what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
        virtual const char *what() const throw();
    };

	class FormNotSignedException : public std::exception
    {
		public:
        	virtual const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &stream, AForm &Form);

#endif