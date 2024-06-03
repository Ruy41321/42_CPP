#ifndef HUMAN_B_HPP
# define HUMAN_B_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanB
{
private:
	std::string name;
	Weapon *weap;
public:
	HumanB(std::string);
	void attack();
	void setWeapon(Weapon&);
};

#endif