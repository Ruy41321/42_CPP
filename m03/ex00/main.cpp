#include "ClapTrap.hpp"

int main() {
    // Costruzione di un oggetto ClapTrap
    ClapTrap clapTrap1("ClapTrap1");

    // Copia di un oggetto ClapTrap
    ClapTrap clapTrap2(clapTrap1);

    // Assegnazione di un oggetto ClapTrap
    ClapTrap clapTrap3 = clapTrap1;

    // Attacco di un oggetto ClapTrap
    clapTrap1.attack("ClapTrap2");

    // Un oggetto ClapTrap subisce danni
    clapTrap1.takeDamage(5);
    clapTrap1.takeDamage(5);
    clapTrap1.takeDamage(5);

    clapTrap1.attack("ClapTrap2");
    // Riparazione di un oggetto ClapTrap
    clapTrap1.beRepaired(5);

    return 0;
}