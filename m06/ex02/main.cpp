#include "includes/Base.hpp"

Base *generate(void);
void identify(Base *p);
void identify(Base &p);

int main()
{
	Base *base = generate();

    identify(base);
    identify(*base);

    delete base;
    return 0;
}