#ifndef HUMAN_A_HPP
# define HUMAN_A_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanA
{
private:
	std::string name;
	Weapon *weap;
public:
	HumanA(std::string, Weapon&);
	void attack();
	void setWeapon(Weapon&);
};

#endif