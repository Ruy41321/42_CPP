#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog: public Animal
{
public:
    Dog();
    Dog(Dog &dog);
    Dog &operator=(Dog &dog);
    ~Dog();

    void makeSound() const;
};

#endif
