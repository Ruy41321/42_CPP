#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
private:
    const std::string name;
    int rank;
public:
    Bureaucrat();
    Bureaucrat(std::string name, int rank);
    Bureaucrat(Bureaucrat &to_copy);
    Bureaucrat &operator=(Bureaucrat &to_copy);
    ~Bureaucrat();

    std::string get_name();
    int get_rank();
    void increment_rank();
    void decrement_rank();

    class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
	class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

std::ostream &operator<<(std::ostream &stream, Bureaucrat &Bureaucrat);

#endif