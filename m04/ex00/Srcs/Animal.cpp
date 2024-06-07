#include "../Headers/Animal.hpp"

Animal::Animal()
{
    std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(Animal &animal)
{
    *this = animal;
    std::cout << "Animal copy constructor called" << std::endl;
}

Animal &Animal::operator=(Animal &animal)
{
    this->type = animal.getType();
    return *this;
}

Animal::~Animal()
{
    std::cout << "Animal destructor called" << std::endl;
}

std::string Animal::getType() const
{
    return this->type;
}

void Animal::makeSound() const
{
    std::cout << "No Animal No Sound" << std::endl;
}