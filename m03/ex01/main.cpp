#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    // Costruzione di un oggetto ScavTrap
    ScavTrap scavTrap1("ScavTrap1");

    // Copia di un oggetto ScavTrap
    ScavTrap scavTrap2(scavTrap1);

    // Assegnazione di un oggetto ScavTrap
    ScavTrap scavTrap3 = scavTrap1;

    // Attacco di un oggetto ScavTrap
    scavTrap1.attack("target");

    // Un oggetto ScavTrap subisce danni
    scavTrap1.takeDamage(5);

    // Riparazione di un oggetto ScavTrap
    scavTrap1.beRepaired(5);

    // Un oggetto ScavTrap entra in modalità guardia
    scavTrap1.guardGate();

    return 0;
}