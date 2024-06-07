#include "../Headers/Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain default constructor called" << std::endl;
    for (int i = 0; i < 100; i++)
        ideas[i] = "";
}

Brain::Brain(Brain &brain)
{
    std::cout << "Brain copy constructor called" << std::endl;
    *this = brain;
}

Brain& Brain::operator=(Brain &brain)
{
    std::cout << "Brain assignation operator called" << std::endl;
    for (int i = 0; i < 100; i++)
        this->ideas[i] = brain.getIdea(i);
    return *this;
}

Brain::~Brain()
{
    std::cout << "Brain destructor called" << std::endl;
}

void Brain::setIdea(int index, std::string idea)
{
    ideas[index] = idea;
}

std::string Brain::getIdea(int index) const
{
    return ideas[index];
}