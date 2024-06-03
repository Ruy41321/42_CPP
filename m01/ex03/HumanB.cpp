#include "HumanB.hpp"

void HumanB::attack()
{
	std::cout << this->name 
			  << " attacks with their " 
			  << this->weap->getType() << "\n";
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->weap = &weapon;
}

HumanB::HumanB(std::string name)
{
	this->name = name;
}