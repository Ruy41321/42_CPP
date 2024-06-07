#include "../Headers/WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal()
{
    this->type = "WrongCat";
    std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::WrongCat(WrongCat &wrongCat): WrongAnimal(wrongCat)
{
    this->type = wrongCat.type;
    std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat &WrongCat::operator=(WrongCat &wrongCat)
{
    this->type = wrongCat.type;
    std::cout << "WrongCat assignation operator called" << std::endl;
    return *this;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat destructor called" << std::endl;
}

void WrongCat::makeSound() const
{
    std::cout << "miaoaoooo" << std::endl;
}