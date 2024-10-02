#include "Headers/Animal.hpp"
#include "Headers/Cat.hpp"
#include "Headers/Dog.hpp"
#include "Headers/WrongAnimal.hpp"
#include "Headers/WrongCat.hpp"

int main()
{
Animal *animals[20];
for (int i = 0; i < 10; i++)
{
    animals[i] = new Dog();
}
for (int i = 10; i < 20; i++)
{
    animals[i] = new Cat();
}
for (int i = 0; i < 20; i++)
{
    animals[i]->makeSound();
}
for (int i = 0; i < 20; i++)
{
    delete animals[i];
}

std::cout << "---------------------" << std::endl;

Dog basic;
basic.getBrain()->setIdea(0, "I am a dog");

{

Dog tmp = basic;
std::cout << tmp.getBrain()->getIdea(0) << std::endl;

}
std::cout << basic.getBrain()->getIdea(0) << std::endl;

basic.makeSound();

std::cout << "---------------------" << std::endl;


return 0;
}