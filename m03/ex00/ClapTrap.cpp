#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    std::cout << "ClapTrap has been constructed" << std::endl;
    this->name = "ClapTrap";
    this->hitPoints = 10;
    this->energyPoints = 10;
    this->attackDamage = 0;
}

ClapTrap::~ClapTrap()
{
    std::cout << this->name << " has been destructed" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &clapTrap)
{
    std::cout << "ClapTrap has been copied" << std::endl;
    *this = clapTrap;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &clapTrap)
{
    std::cout << "ClapTrap has been assigned" << std::endl;
    this->name = clapTrap.name;
    this->hitPoints = clapTrap.hitPoints;
    this->energyPoints = clapTrap.energyPoints;
    this->attackDamage = clapTrap.attackDamage;
    return *this;
}

ClapTrap::ClapTrap(std::string name)
{
    this->name = name;
    this->hitPoints = 10;
    this->energyPoints = 10;
    this->attackDamage = 0;
    std::cout << this->name << " has been constructed" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->hitPoints <= 0)
    {
        std::cout << this->name << " is already dead" << std::endl;
        return;
    }
    this->hitPoints -= amount;
    std::cout << this->name << " has taken " << amount << " points of damage!" << std::endl;
    if (this->hitPoints <= 0)
    {
        std::cout << this->name << " has died" << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->energyPoints == 0)
    {
        std::cout << this->name << " cannot be repaired because it has no energy points!" << std::endl;
        return;
    }
    if (this->hitPoints <= 0)
    {
        std::cout << this->name << " cannot be repaired because is dead" << std::endl;
        return;
    }
    this->hitPoints += amount;
    this->energyPoints -= 1;
    std::cout << this->name << " has been repaired for " << amount << " points!" << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
    if (this->energyPoints == 0)
    {
        std::cout << this->name << " cannot attack because it has no energy points!" << std::endl;
        return;
    }
    if (this->hitPoints <= 0)
    {
        std::cout << this->name << " cannot attack because is dead" << std::endl;
        return;
    }
    this->energyPoints -= 1;
    std::cout << this->name << " attacks " << target << " causing " << this->attackDamage << " points of damage!" << std::endl;
}