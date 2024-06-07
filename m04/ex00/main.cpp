#include "Headers/Animal.hpp"
#include "Headers/Cat.hpp"
#include "Headers/Dog.hpp"
#include "Headers/WrongAnimal.hpp"
#include "Headers/WrongCat.hpp"

int main()
{
const WrongAnimal* meta = new WrongAnimal();
const Animal* j = new Dog();
const WrongAnimal* i = new WrongCat();
std::cout << j->getType() << " " << std::endl;
std::cout << i->getType() << " " << std::endl;
i->makeSound(); //will output the cat sound!
j->makeSound();
meta->makeSound();

delete meta;
delete j;
delete i;

return 0;
}
