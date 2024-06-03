#include "../includes/PhoneBook.hpp"

using std::cout;
using std::cin;

PhoneBook::PhoneBook(){
	this->i = 0;
	this->oldI = 0;
}

PhoneBook::~PhoneBook(){}

void	PhoneBook::add(void){
	Contact contact;
	std::string	input;

	cout << "   Type:" << std::endl << std::endl;

	cout << "   First name: ";
	std::getline(cin, input);
	contact.setFirstName(input);
	
	cout << "   Last name: ";
	std::getline(cin, input);
	contact.setLastName(input);
	
	cout << "   Nickname: ";
	std::getline(cin, input);
	contact.setNickname(input);
	
	cout << "   Phone number: ";
	std::getline(cin, input);
	while (!input.empty() && input.find_first_not_of("0123456789") != std::string::npos)
	{
		cin.clear();
		cout << "   Phone number must be fully composed by numbers" << std::endl;
		cout << "   Phone number: ";
		std::getline(cin, input);
	}
	contact.setNumber(input);
	
	cout << "   Darkest secret: ";
	std::getline(cin, input);
	contact.setDarkestSecret(input);

	if (this->i < MAX_NUM){
		this->contacts[this->i] = contact;
		i++;
	}
	else{
		if (oldI >= i)
			oldI = 0;
		this->contacts[this->oldI] = contact;
		oldI++;
	}
	cout << "   ✅Contact added" << std::endl << std::endl;

	return ;
}

std::string getFormattedStr(const std::string& str)
{
	if (str.length() > 10)
		return str.substr(0,9) + ".";
	return str;
}

void	PhoneBook::search()
{
	std::string	input;
	int			index;

	if (this->i == 0)
	{
		cout << "   There aren't contacts" << std::endl;
		return ;
	}
	cout << "\n     Index|First Name| Last Name|  Nickname|" << std::endl;
	for (int i = 0; i < this->i; i += 1)
	{
		cout << std::right << std::setw(10) << i + 1 << "|";
		cout << std::right << std::setw(10) << getFormattedStr(contacts[i].getFirstName()) << "|" ;
		cout << std::right << std::setw(10) << getFormattedStr(contacts[i].getLastName()) << "|";
		cout << std::right << std::setw(10) << getFormattedStr(contacts[i].getNickname()) << "|";
		cout << std::endl;
	}
	cout << "\n   Type the Index of the contact that you want: ";
	std::getline(cin, input);
	while (1){
		while (!input.empty() && input.find_first_not_of("0123456789") != std::string::npos){
			cin.clear();
			cout << "\nERROR:You must enter a valid index" << std::endl;
			cout << "   Type the Index of the contact that you want: ";
			std::getline(cin, input);
		}
		index = atoi(input.c_str());
		if (index > this->i || index == 0)
		{
			input = "a";
			continue ;
		}
		break ;
	}
	this->displayContact(this->contacts[index - 1]);
}

void	PhoneBook::displayContact(Contact contact){
	cout << std::endl;
	cout << "     First name: " << contact.getFirstName() << std::endl;
	cout << "     Last name: " << contact.getLastName() << std::endl;
	cout << "     Nickname: " << contact.getNickname() << std::endl;
	cout << "     Phone number: " << contact.getNumber() << std::endl;
	cout << "     Darkest secret: " << contact.getDarkestSecret() << std::endl;
}