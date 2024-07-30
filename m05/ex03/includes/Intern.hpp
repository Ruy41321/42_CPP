#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include "AForm.hpp"

class Intern {
	public:
		Intern();
		Intern(const Intern &to_copy);
		~Intern();
		Intern& operator=(const Intern &assign);

		AForm *makeForm(std::string name, std::string target);		
};

#endif