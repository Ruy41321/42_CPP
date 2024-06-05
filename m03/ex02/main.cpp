#include "FragTrap.hpp"

int main() {
    // Costruzione di un oggetto FragTrap
    FragTrap fragTrap1("FragTrap1");

    // Copia di un oggetto FragTrap
    FragTrap fragTrap2(fragTrap1);

    // Assegnazione di un oggetto FragTrap
    FragTrap fragTrap3 = fragTrap1;

    // Attacco di un oggetto FragTrap
    fragTrap1.attack("target");

    // Un oggetto FragTrap subisce danni
    fragTrap1.takeDamage(5);

    // Riparazione di un oggetto FragTrap
    fragTrap1.beRepaired(5);

    // Un oggetto FragTrap chiede un high five
    fragTrap1.highFivesGuys();

    return 0;
}