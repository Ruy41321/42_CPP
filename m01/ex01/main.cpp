#include "Zombie.hpp"

int main()
{
	Zombie *z1;
	
	z1 = zombieHorde(4, "mauro");
	for (int i = 0; i < 4; i++)
		z1[i].announce();
	delete[] z1;
	return 0;
}