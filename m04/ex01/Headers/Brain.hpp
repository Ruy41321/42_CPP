#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain
{
private:
    std::string ideas[100];
public:
    Brain();
    Brain(Brain &brain);
    Brain &operator=(Brain &brain);
    ~Brain();

    std::string getIdea(int index) const;
    void setIdea(int index, std::string idea);
};

#endif