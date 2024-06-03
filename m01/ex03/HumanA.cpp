#include "HumanA.hpp"

void HumanA::attack()
{
	std::cout << this->name 
			  << " attacks with their " 
			  << this->weap->getType() << "\n";
}

void HumanA::setWeapon(Weapon &weapon)
{
	this->weap = &weapon;
}

HumanA::HumanA(std::string name, Weapon &weapon)
{
	this->name = name;
	this->weap = &weapon;
}