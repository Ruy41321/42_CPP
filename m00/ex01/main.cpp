#include "includes/PhoneBook.hpp"

void stampIntro()
{
    std::cout << "/-------------------------------------------\\\n"
            "|                                           |\n"
            "|                 Welcome                   |\n"
            "|                                           |\n"
			"|                  Type:                    |\n"
            "|          ADD - To add a new contact       |\n"
            "|          SEARCH - To display a contact    |\n"
            "|          EXIT - To exit PhoneBook         |\n"
            "|                                           |\n"
            "\\-------------------------------------------/" << std::endl;
}

int	main(){
	PhoneBook pb;
    std::string input;

    stampIntro();
	std::cout << "PhoneBook > ";
    std::getline(std::cin, input);
    while (input != "EXIT")
    {
        if (input == "ADD")
            pb.add();
        else if (input == "SEARCH")
            pb.search();
		std::cout << "PhoneBook > ";
    	std::getline(std::cin, input);
    }
    std::cout << "Exiting..." << std::endl;
    return 0;
}