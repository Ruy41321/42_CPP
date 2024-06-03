#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>

class Weapon
{
private:
	std::string type;
public:
	Weapon(std::string);
	Weapon();
	void setType(std::string);
	const std::string getType();
};

#endif