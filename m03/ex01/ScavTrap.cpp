#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    std::cout << "ScavTrap " << name << " has been constructed" << std::endl;
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap " << this->name << " has been destructed" << std::endl;
}

void ScavTrap::attack(std::string const &target) {
    if (this->hitPoints <= 0) {
        std::cout << "ScavTrap " << this->name << " is dead and cannot attack" << std::endl;
        return;
    }
    if (this->energyPoints < 10) {
        std::cout << "ScavTrap " << this->name << " has not enough energy to attack" << std::endl;
        return;
    }
    this->energyPoints -= 1;
    std::cout << "ScavTrap " << this->name << " attacks " << target << " causing " << this->attackDamage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << this->name << " switched in Gate keeper mode" << std::endl;
}