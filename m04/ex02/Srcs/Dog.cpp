#include "../Headers/Dog.hpp"

Dog::Dog(): Animal()
{
    this->type = "Dog";
    std::cout << "Dog constructor called" << std::endl;
    this->brain = new Brain();
}

Dog::Dog(Dog &dog): Animal(dog)
{
    *this = dog;
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog &Dog::operator=(Dog &dog)
{
    this->type = dog.getType();
	this->brain = new Brain();
    *this->brain = *dog.getBrain();
    return *this;
}

Dog::~Dog()
{
    delete this->brain;
    std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "Bauauauuaau au bau" << std::endl;
}

Brain *Dog::getBrain() const
{
    return this->brain;
}