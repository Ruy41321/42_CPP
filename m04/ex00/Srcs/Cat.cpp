#include "../Headers/Cat.hpp"

Cat::Cat(): Animal()
{
    this->type = "Cat";
    std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(Cat &cat): Animal(cat)
{
    *this = cat;
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat &Cat::operator=(Cat &cat)
{
    this->type = cat.getType();
    return *this;
}

Cat::~Cat()
{
    std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "Maoooo Maaaooooo" << std::endl;
}