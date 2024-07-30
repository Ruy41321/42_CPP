#ifndef SHEBURYCREATIONFORM_HPP
# define SHEBURYCREATIONFORM_HPP

# include "AForm.hpp"

class ShrubberyCreationForm : public AForm 
{
	public:
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &copy);
		~ShrubberyCreationForm(void);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm &presForm);

		void superExecute(Bureaucrat const& bureaucrat) const;
};

#endif