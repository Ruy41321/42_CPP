#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "../includes/Contact.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>

# define MAX_NUM 8

class PhoneBook
{
	private:
		Contact contacts[MAX_NUM];
		int i;
		int oldI;

	public:
		PhoneBook();
		~PhoneBook();

		void	add();
		void	search();
		void	displayContact(Contact);
};

#endif