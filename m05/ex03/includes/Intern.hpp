#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include "AForm.hpp"

# define SHRUBBERY "shrubbery creation"
# define ROBOTOMY "robotomy request"
# define PRESIDENTIAL "presidential pardon"

class Intern {
	public:
		Intern();
		Intern(const Intern &to_copy);
		~Intern();
		Intern& operator=(const Intern &assign);

		AForm *makeForm(std::string name, std::string target);		
};

#endif