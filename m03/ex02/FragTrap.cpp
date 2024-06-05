#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    std::cout << "FragTrap " << name << " has been constructed" << std::endl;
    this->hitPoints = 100;
    this->energyPoints = 100;
    this->attackDamage = 30;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap " << this->name << " has been destructed" << std::endl;
}

void FragTrap::highFivesGuys() {
    std::cout << "FragTrap " << this->name << " ask to high five" << std::endl;
}