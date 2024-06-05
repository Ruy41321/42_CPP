#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
    protected:
        std::string name;
        unsigned int hitPoints;
        unsigned int energyPoints;
        unsigned int attackDamage;
    public:
        ClapTrap();
        ClapTrap(const ClapTrap &clapTrap);
        ~ClapTrap();
        ClapTrap &operator=(const ClapTrap &clapTrap);

        ClapTrap(std::string name);
        void attack(const std::string &target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};

#endif