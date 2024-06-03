#include "Zombie.hpp"

int main()
{
	Zombie *z1;
	
	z1 = newZombie("mauro");
	z1->announce();

	randomChump("pippo");

	delete(z1);
}