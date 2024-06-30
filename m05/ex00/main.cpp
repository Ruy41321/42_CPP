#include "Bureaucrat.hpp"

int main()
{
    try{
        Bureaucrat b1("b1", 170);
        std::cout << b1 << std::endl;
        b1.decrement_rank();
        std::cout << b1 << std::endl;
        b1.increment_rank();
        std::cout << b1 << std::endl;
        b1.increment_rank();
        std::cout << b1 << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

}