#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact
{
	private:
		std::string firstName, lastName, nickname, darkestSecret, number;

	public:
		void	setFirstName(std::string);
		void	setLastName(std::string);
		void	setNickname(std::string);
		void	setDarkestSecret(std::string);
		void	setNumber(std::string);
		const std::string&		getFirstName(void) const;
		const std::string&		getLastName(void) const;
		const std::string&		getNickname(void) const;
		const std::string&		getDarkestSecret(void) const;
		const std::string&		getNumber(void) const;
};

#endif